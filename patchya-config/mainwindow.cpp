#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>
#include "config.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    bool ok;
    QString hexVal;
    QString decVal;
    QString victimPath;
    QString loaderPath;
    QString line;
    char* patternConfig =  CONFIG_PATTERN;
    int configStartIndex = 0;
    int SNRPatches = 0;
    int OffPatches =0;
    QLineEdit *SNRLineEdit[10] = {ui->lineEdit_7, ui->lineEdit_8, ui->lineEdit_9, ui->lineEdit_13, ui->lineEdit_15, ui->lineEdit_17, ui->lineEdit_19, ui->lineEdit_16, ui->lineEdit_18, ui->lineEdit_20};
    QLineEdit *SNRLineEditR[10] = {ui->lineEdit_31, ui->lineEdit_34, ui->lineEdit_28, ui->lineEdit_29, ui->lineEdit_36, ui->lineEdit_33, ui->lineEdit_27, ui->lineEdit_30, ui->lineEdit_32, ui->lineEdit_35};
    QLineEdit *OffsetLineEdit[10] = {ui->lineEdit_11, ui->lineEdit_12, ui->lineEdit_10, ui->lineEdit_14, ui->lineEdit_26, ui->lineEdit_24, ui->lineEdit_21, ui->lineEdit_22, ui->lineEdit_23, ui->lineEdit_25};
    QLineEdit *OffsetLineEditA[10] = {ui->lineEdit_41, ui->lineEdit_40, ui->lineEdit_37, ui->lineEdit_43, ui->lineEdit_45, ui->lineEdit_38, ui->lineEdit_46, ui->lineEdit_39, ui->lineEdit_42, ui->lineEdit_44};
    QLineEdit *OffsetLineEditR[10] = {ui->lineEdit_51, ui->lineEdit_50, ui->lineEdit_47, ui->lineEdit_53, ui->lineEdit_55, ui->lineEdit_48, ui->lineEdit_56, ui->lineEdit_49, ui->lineEdit_52, ui->lineEdit_54};


    //Create loader file
    loaderPath = ui->lineEdit_5->text();


    QString loaderTemplatePath = LOADER_TEMPLATE_PATH;
    while(!QFile(loaderTemplatePath).exists())
    {
        loaderTemplatePath = QInputDialog::getText(0,"Error","Couldn't find loader template in default path, please enter path of template loader");
        if(loaderTemplatePath == NULL) return;
        QFileInfo loaderTemplateInfo(loaderTemplatePath);
        if(loaderTemplateInfo.suffix() != "exe")
            QMessageBox::information(0, "Error", "loader template must be an exe!");
    }
   QFile orignalTemplate(loaderTemplatePath);
   orignalTemplate.open(QIODevice::ReadOnly|QIODevice::ExistingOnly);
   QByteArray  iContents = orignalTemplate.readAll();
   orignalTemplate.close();




    QFile loaderFile(loaderPath);
    if(!loaderFile.open(QIODevice::ReadWrite|QIODevice::NewOnly)) {
        QMessageBox::information(0, "Error", loaderFile.errorString());
        return;
    }
    //initial configuration
    configStartIndex = iContents.indexOf(patternConfig);
    qDebug() << "search result"<<configStartIndex;

    // path of victim
    QString  inFile = ui->lineEdit_6->text();
    QByteArray inFileba = inFile.toLatin1();
    //warning if file is not in current file system
    if(!QFile(inFile).exists())
    {
        QMessageBox::information(0, "Warning", "victim file is not currently in the file system, however loader will be created anyway");
    }
    iContents.replace(configStartIndex+CONFIG_INFILE_OFFSET,inFileba.size(),inFileba);

    //Gate condition

    if(ui->radioButton->isChecked())
    {
        hexVal = ui->lineEdit->text();
        uint nHex =  hexVal.toUInt(&ok,16);
        if(!ok)
        {
            QMessageBox::information(0, "error","Memory Address Must br valid Hex without 0x");
            loaderFile.close();
            loaderFile.remove();
            return;
        }
        const char gateCond[2] = {PATCH_COND_PC,0};
        iContents.replace(configStartIndex+CONFIG_GATE_CONDITION_OFFSET,1,gateCond);
        QByteArray memPCba;
        convertIntToBA(nHex,memPCba);
        iContents.replace(configStartIndex+CONFIG_MEM_PC_OFFSET,4,memPCba);

    }
    else if(ui->radioButton_2->isChecked())
    {
        hexVal = ui->lineEdit_2->text();
        uint nHex =  hexVal.toUInt(&ok,16);
        if(!ok)
        {
            QMessageBox::information(0, "Error","Memory Address Must br valid Hex without 0x");
            loaderFile.close();
            loaderFile.remove();
            return;
        }
        QByteArray gateCondba;
        gateCondba.resize(1);
        gateCondba[0] = PATCH_COND_MEM;
        iContents.replace(configStartIndex+CONFIG_GATE_CONDITION_OFFSET,1,gateCondba);

        QByteArray memAddba;
        convertIntToBA(nHex,memAddba);
        iContents.replace(configStartIndex+CONFIG_MEM_ADD_OFFSET,4,memAddba);

        hexVal = ui->lineEdit_4->text();
        nHex =  hexVal.toUInt(&ok,16);
        if(!ok)
        {
            QMessageBox::information(0, "Error","Memory Address Must br valid Hex without 0x");
            loaderFile.close();
            loaderFile.remove();
            return;
        }
        QByteArray memDatba;
        convertIntToBA(nHex,memDatba);
        iContents.replace(configStartIndex+CONFIG_MEM_VAL_OFFSET,4,memDatba);
    }
    else if(ui->radioButton_3->isChecked())
    {

        decVal = ui->lineEdit_3->text();
        uint nDec =  decVal.toUInt(&ok,10);
        if(!ok)
        {
            QMessageBox::information(0, "Error","Timeout must be in decimal");
            loaderFile.close();
            loaderFile.remove();
            return;
        }
        const char gateCond[2] = {PATCH_COND_TOUT,0};
        iContents.replace(configStartIndex+CONFIG_GATE_CONDITION_OFFSET,1,gateCond);
        QByteArray toutba;
        convertIntToBA(nDec,toutba);
        iContents.replace(configStartIndex+CONFIG_TIMEOUT_OFFSET,4,toutba);
    }
    else
    {
        QMessageBox::information(0, "Error","Gate Condition Must be selected!");
        loaderFile.close();
        loaderFile.remove();
        return;
    }

    //Number of patches
    SNRPatches = ui->spinBox->value();
    OffPatches = ui->spinBox_2->value();

    QByteArray SNRba;
    convertIntToBA(SNRPatches,SNRba);
    iContents.replace(configStartIndex+CONFIG_NUM_SNR_OFFSET,4,SNRba);

    QByteArray OFFba;
    convertIntToBA(OffPatches,OFFba);
    iContents.replace(configStartIndex+CONFIG_NUM_OFF_OFFSET,4,OFFba);

    //SNR patches
    for(int i = 0 ; i < SNRPatches ; i++)
    {

        QString PattS = SNRLineEdit[i]->text();

        PattS.replace(" ","");
        PattS = PattS.toUpper();

        QString PattR = SNRLineEditR[i]->text();
        PattR.replace(" ","");
        QByteArray PattRba = QByteArray::fromHex(PattR.toLatin1());
        QByteArray PattSba = PattS.toLatin1();
        if((2*PattRba.size()) != PattSba.size())
        {
            QMessageBox::information(0, "Error","Search and Replace pattern sizes must match");
            loaderFile.close();
            loaderFile.remove();
            return;
        }
        QByteArray pattSizeba;
        convertIntToBA(PattRba.size(),pattSizeba);

        iContents.replace(configStartIndex+CONFIG_PATT_SRCH_OFFSET+(i*MAX_PATTERN_SIZE),PattSba.size(),PattSba);
        iContents.replace(configStartIndex+CONFIG_PATT_REP_OFFSET+(i*MAX_PATTERN_SIZE),PattRba.size(),PattRba);
        iContents.replace(configStartIndex+CONFIG_PATT_SNR_SIZE_OFFSET+(4*i),4,pattSizeba);
    }

    // Offset patches
    for(int i = 0 ; i < OffPatches ; i++)
    {
        QString OffAddress = OffsetLineEdit[i]->text();
        QString OffOrignal = OffsetLineEditA[i]->text();
        QString OffReplace = OffsetLineEditR[i]->text();

        OffAddress.replace(" ","");
        OffOrignal.replace(" ","");
        OffReplace.replace(" ","");


        QByteArray OffAddressba;
        int off_add =  OffAddress.toUInt(&ok,16);
        if(!ok)
        {
            QMessageBox::information(0, "Error","Memory Address Must br valid Hex without 0x");
            loaderFile.close();
            loaderFile.remove();
            return;
        }
        convertIntToBA(off_add,OffAddressba);
        QByteArray OffOrignalba = QByteArray::fromHex(OffOrignal.toLatin1());
        QByteArray OffReplaceba = QByteArray::fromHex(OffReplace.toLatin1());

        if(OffOrignalba.size() != OffReplaceba.size())
        {
            QMessageBox::information(0, "Error","Offset Original and Patch size must match");
            loaderFile.close();
            loaderFile.remove();
            return;
        }
        QByteArray offSizeba;
        convertIntToBA(OffReplaceba.size(),offSizeba);

        iContents.replace(configStartIndex+CONFIG_OFF_ADD_OFFSET+(i*MAX_PATTERN_SIZE),OffAddressba.size(),OffAddressba);
        iContents.replace(configStartIndex+CONFIG_OFF_ORG_OFFSET+(i*MAX_PATTERN_SIZE),OffOrignalba.size(),OffOrignalba);
        iContents.replace(configStartIndex+CONFIG_OFF_REP_OFFSET+(i*MAX_PATTERN_SIZE),OffReplaceba.size(),OffReplaceba);
        iContents.replace(configStartIndex+CONFIG_OFF_SIZE_OFFSET+(4*i),4,offSizeba);

    }


    //configured
    const char config_flag[2] = {CONFIG_FLAG,0};
    iContents.replace(configStartIndex,1,config_flag);



    loaderFile.write(iContents);
    loaderFile.close();

    QMessageBox::information(0, "Status","Done");
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
    }
    else
    {
        ui->lineEdit->setEnabled(false);
    }
}


void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->setEnabled(true);
    }
    else
    {
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
    }
}

void MainWindow::on_radioButton_3_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_3->setEnabled(true);
        ui->lineEdit_4->setEnabled(false);
    }
    else
    {
        ui->lineEdit_3->setEnabled(false);
    }
}


void MainWindow::on_actionGithub_Project_triggered(bool checked)
{

        QString githuburl = "https://github.com/misaleh/patchya";
        QDesktopServices::openUrl(QUrl(githuburl));
}


void MainWindow::on_actionExit_2_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionGithub_Project_toggled(bool arg1)
{

}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    QLineEdit *SNRLineEdit[10] = {ui->lineEdit_7, ui->lineEdit_8, ui->lineEdit_9, ui->lineEdit_13, ui->lineEdit_15, ui->lineEdit_17, ui->lineEdit_19, ui->lineEdit_16, ui->lineEdit_18, ui->lineEdit_20};
    QLineEdit *SNRLineEditR[10] = {ui->lineEdit_31, ui->lineEdit_34, ui->lineEdit_28, ui->lineEdit_29, ui->lineEdit_36, ui->lineEdit_33, ui->lineEdit_27, ui->lineEdit_30, ui->lineEdit_32, ui->lineEdit_35};

    for(int i = 0 ; i < arg1 ; i++)
    {
        SNRLineEdit[i]->setEnabled(true);
        SNRLineEditR[i]->setEnabled(true);
    }
    for(int i = arg1 ; i < 10 ; i++)
    {
        SNRLineEdit[i]->setEnabled(false);
        SNRLineEditR[i]->setEnabled(false);
    }
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    QLineEdit *OffsetLineEdit[10] = {ui->lineEdit_11, ui->lineEdit_12, ui->lineEdit_10, ui->lineEdit_14, ui->lineEdit_26, ui->lineEdit_24, ui->lineEdit_21, ui->lineEdit_22, ui->lineEdit_23, ui->lineEdit_25};
    QLineEdit *OffsetLineEditA[10] = {ui->lineEdit_41, ui->lineEdit_40, ui->lineEdit_37, ui->lineEdit_43, ui->lineEdit_45, ui->lineEdit_38, ui->lineEdit_46, ui->lineEdit_39, ui->lineEdit_42, ui->lineEdit_44};
    QLineEdit *OffsetLineEditR[10] = {ui->lineEdit_51, ui->lineEdit_50, ui->lineEdit_47, ui->lineEdit_53, ui->lineEdit_55, ui->lineEdit_48, ui->lineEdit_56, ui->lineEdit_49, ui->lineEdit_52, ui->lineEdit_54};

    for(int i = 0 ; i < arg1 ; i++)
    {
        OffsetLineEdit[i]->setEnabled(true);
        OffsetLineEditA[i]->setEnabled(true);
        OffsetLineEditR[i]->setEnabled(true);
    }
    for(int i = arg1 ; i < 10 ; i++)
    {
        OffsetLineEdit[i]->setEnabled(false);
        OffsetLineEditA[i]->setEnabled(false);
        OffsetLineEditR[i]->setEnabled(false);
    }
}
