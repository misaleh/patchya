/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGithub_Project;
    QAction *actionExit_2;
    QAction *actionAdd_SNR_Patch;
    QAction *actionAdd_Offset_Patch;
    QAction *actionRemove_SNR_Patch;
    QAction *actionRemove_Offset_Patch;
    QWidget *centralWidget;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label;
    QFrame *line;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_22;
    QLineEdit *lineEdit_23;
    QLineEdit *lineEdit_24;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_25;
    QLineEdit *lineEdit_26;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_27;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_30;
    QLineEdit *lineEdit_31;
    QLineEdit *lineEdit_32;
    QLineEdit *lineEdit_33;
    QLineEdit *lineEdit_34;
    QLineEdit *lineEdit_35;
    QLineEdit *lineEdit_36;
    QLineEdit *lineEdit_37;
    QLineEdit *lineEdit_38;
    QLineEdit *lineEdit_39;
    QLineEdit *lineEdit_40;
    QLineEdit *lineEdit_41;
    QLineEdit *lineEdit_42;
    QLineEdit *lineEdit_43;
    QLineEdit *lineEdit_44;
    QLineEdit *lineEdit_45;
    QLineEdit *lineEdit_46;
    QLineEdit *lineEdit_47;
    QLineEdit *lineEdit_48;
    QLineEdit *lineEdit_49;
    QLineEdit *lineEdit_50;
    QLineEdit *lineEdit_51;
    QLineEdit *lineEdit_52;
    QLineEdit *lineEdit_53;
    QLineEdit *lineEdit_54;
    QLineEdit *lineEdit_55;
    QLineEdit *lineEdit_56;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(748, 600);
        actionGithub_Project = new QAction(MainWindow);
        actionGithub_Project->setObjectName(QStringLiteral("actionGithub_Project"));
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QStringLiteral("actionExit_2"));
        actionAdd_SNR_Patch = new QAction(MainWindow);
        actionAdd_SNR_Patch->setObjectName(QStringLiteral("actionAdd_SNR_Patch"));
        actionAdd_Offset_Patch = new QAction(MainWindow);
        actionAdd_Offset_Patch->setObjectName(QStringLiteral("actionAdd_Offset_Patch"));
        actionRemove_SNR_Patch = new QAction(MainWindow);
        actionRemove_SNR_Patch->setObjectName(QStringLiteral("actionRemove_SNR_Patch"));
        actionRemove_Offset_Patch = new QAction(MainWindow);
        actionRemove_Offset_Patch->setObjectName(QStringLiteral("actionRemove_Offset_Patch"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 40, 171, 17));
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 70, 141, 17));
        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(20, 100, 131, 17));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 111, 16));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(27, 130, 581, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(230, 40, 113, 20));
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(230, 70, 113, 20));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(230, 100, 113, 20));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(410, 70, 113, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 70, 61, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 40, 61, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(350, 100, 61, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, 70, 61, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 150, 121, 16));
        label_6->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(380, 150, 121, 16));
        label_7->setFont(font);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(293, 140, 20, 251));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(520, 530, 81, 23));
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(100, 500, 331, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 500, 131, 20));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 530, 131, 20));
        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(100, 530, 331, 20));
        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setEnabled(false);
        lineEdit_7->setGeometry(QRect(20, 200, 111, 20));
        lineEdit_8 = new QLineEdit(centralWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setEnabled(false);
        lineEdit_8->setGeometry(QRect(20, 230, 111, 20));
        lineEdit_9 = new QLineEdit(centralWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setEnabled(false);
        lineEdit_9->setGeometry(QRect(20, 260, 111, 20));
        lineEdit_13 = new QLineEdit(centralWidget);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setEnabled(false);
        lineEdit_13->setGeometry(QRect(20, 290, 111, 20));
        lineEdit_15 = new QLineEdit(centralWidget);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setEnabled(false);
        lineEdit_15->setGeometry(QRect(20, 320, 111, 20));
        lineEdit_16 = new QLineEdit(centralWidget);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setEnabled(false);
        lineEdit_16->setGeometry(QRect(20, 410, 111, 20));
        lineEdit_17 = new QLineEdit(centralWidget);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setEnabled(false);
        lineEdit_17->setGeometry(QRect(20, 350, 111, 20));
        lineEdit_18 = new QLineEdit(centralWidget);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));
        lineEdit_18->setEnabled(false);
        lineEdit_18->setGeometry(QRect(20, 440, 111, 20));
        lineEdit_19 = new QLineEdit(centralWidget);
        lineEdit_19->setObjectName(QStringLiteral("lineEdit_19"));
        lineEdit_19->setEnabled(false);
        lineEdit_19->setGeometry(QRect(20, 380, 111, 20));
        lineEdit_20 = new QLineEdit(centralWidget);
        lineEdit_20->setObjectName(QStringLiteral("lineEdit_20"));
        lineEdit_20->setEnabled(false);
        lineEdit_20->setGeometry(QRect(20, 470, 111, 20));
        lineEdit_10 = new QLineEdit(centralWidget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setEnabled(false);
        lineEdit_10->setGeometry(QRect(320, 260, 111, 20));
        lineEdit_21 = new QLineEdit(centralWidget);
        lineEdit_21->setObjectName(QStringLiteral("lineEdit_21"));
        lineEdit_21->setEnabled(false);
        lineEdit_21->setGeometry(QRect(320, 380, 111, 20));
        lineEdit_11 = new QLineEdit(centralWidget);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setEnabled(false);
        lineEdit_11->setGeometry(QRect(320, 200, 111, 20));
        lineEdit_14 = new QLineEdit(centralWidget);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setEnabled(false);
        lineEdit_14->setGeometry(QRect(320, 290, 111, 20));
        lineEdit_22 = new QLineEdit(centralWidget);
        lineEdit_22->setObjectName(QStringLiteral("lineEdit_22"));
        lineEdit_22->setEnabled(false);
        lineEdit_22->setGeometry(QRect(320, 410, 111, 20));
        lineEdit_23 = new QLineEdit(centralWidget);
        lineEdit_23->setObjectName(QStringLiteral("lineEdit_23"));
        lineEdit_23->setEnabled(false);
        lineEdit_23->setGeometry(QRect(320, 440, 111, 20));
        lineEdit_24 = new QLineEdit(centralWidget);
        lineEdit_24->setObjectName(QStringLiteral("lineEdit_24"));
        lineEdit_24->setEnabled(false);
        lineEdit_24->setGeometry(QRect(320, 350, 111, 20));
        lineEdit_12 = new QLineEdit(centralWidget);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setEnabled(false);
        lineEdit_12->setGeometry(QRect(320, 230, 111, 20));
        lineEdit_25 = new QLineEdit(centralWidget);
        lineEdit_25->setObjectName(QStringLiteral("lineEdit_25"));
        lineEdit_25->setEnabled(false);
        lineEdit_25->setGeometry(QRect(320, 470, 111, 20));
        lineEdit_26 = new QLineEdit(centralWidget);
        lineEdit_26->setObjectName(QStringLiteral("lineEdit_26"));
        lineEdit_26->setEnabled(false);
        lineEdit_26->setGeometry(QRect(320, 320, 111, 20));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setEnabled(true);
        spinBox->setGeometry(QRect(220, 150, 42, 22));
        spinBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        spinBox->setMaximum(10);
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(540, 150, 42, 22));
        spinBox_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        spinBox_2->setMaximum(10);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 180, 111, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(170, 180, 111, 16));
        lineEdit_27 = new QLineEdit(centralWidget);
        lineEdit_27->setObjectName(QStringLiteral("lineEdit_27"));
        lineEdit_27->setEnabled(false);
        lineEdit_27->setGeometry(QRect(160, 380, 111, 20));
        lineEdit_27->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_28 = new QLineEdit(centralWidget);
        lineEdit_28->setObjectName(QStringLiteral("lineEdit_28"));
        lineEdit_28->setEnabled(false);
        lineEdit_28->setGeometry(QRect(160, 260, 111, 20));
        lineEdit_28->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_29 = new QLineEdit(centralWidget);
        lineEdit_29->setObjectName(QStringLiteral("lineEdit_29"));
        lineEdit_29->setEnabled(false);
        lineEdit_29->setGeometry(QRect(160, 290, 111, 20));
        lineEdit_29->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_30 = new QLineEdit(centralWidget);
        lineEdit_30->setObjectName(QStringLiteral("lineEdit_30"));
        lineEdit_30->setEnabled(false);
        lineEdit_30->setGeometry(QRect(160, 410, 111, 20));
        lineEdit_30->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_31 = new QLineEdit(centralWidget);
        lineEdit_31->setObjectName(QStringLiteral("lineEdit_31"));
        lineEdit_31->setEnabled(false);
        lineEdit_31->setGeometry(QRect(160, 200, 111, 20));
        lineEdit_31->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_32 = new QLineEdit(centralWidget);
        lineEdit_32->setObjectName(QStringLiteral("lineEdit_32"));
        lineEdit_32->setEnabled(false);
        lineEdit_32->setGeometry(QRect(160, 440, 111, 20));
        lineEdit_32->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_33 = new QLineEdit(centralWidget);
        lineEdit_33->setObjectName(QStringLiteral("lineEdit_33"));
        lineEdit_33->setEnabled(false);
        lineEdit_33->setGeometry(QRect(160, 350, 111, 20));
        lineEdit_33->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_34 = new QLineEdit(centralWidget);
        lineEdit_34->setObjectName(QStringLiteral("lineEdit_34"));
        lineEdit_34->setEnabled(false);
        lineEdit_34->setGeometry(QRect(160, 230, 111, 20));
        lineEdit_34->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_35 = new QLineEdit(centralWidget);
        lineEdit_35->setObjectName(QStringLiteral("lineEdit_35"));
        lineEdit_35->setEnabled(false);
        lineEdit_35->setGeometry(QRect(160, 470, 111, 20));
        lineEdit_35->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_36 = new QLineEdit(centralWidget);
        lineEdit_36->setObjectName(QStringLiteral("lineEdit_36"));
        lineEdit_36->setEnabled(false);
        lineEdit_36->setGeometry(QRect(160, 320, 111, 20));
        lineEdit_36->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        lineEdit_37 = new QLineEdit(centralWidget);
        lineEdit_37->setObjectName(QStringLiteral("lineEdit_37"));
        lineEdit_37->setEnabled(false);
        lineEdit_37->setGeometry(QRect(460, 260, 111, 20));
        lineEdit_38 = new QLineEdit(centralWidget);
        lineEdit_38->setObjectName(QStringLiteral("lineEdit_38"));
        lineEdit_38->setEnabled(false);
        lineEdit_38->setGeometry(QRect(460, 350, 111, 20));
        lineEdit_39 = new QLineEdit(centralWidget);
        lineEdit_39->setObjectName(QStringLiteral("lineEdit_39"));
        lineEdit_39->setEnabled(false);
        lineEdit_39->setGeometry(QRect(460, 410, 111, 20));
        lineEdit_40 = new QLineEdit(centralWidget);
        lineEdit_40->setObjectName(QStringLiteral("lineEdit_40"));
        lineEdit_40->setEnabled(false);
        lineEdit_40->setGeometry(QRect(460, 230, 111, 20));
        lineEdit_41 = new QLineEdit(centralWidget);
        lineEdit_41->setObjectName(QStringLiteral("lineEdit_41"));
        lineEdit_41->setEnabled(false);
        lineEdit_41->setGeometry(QRect(460, 200, 111, 20));
        lineEdit_42 = new QLineEdit(centralWidget);
        lineEdit_42->setObjectName(QStringLiteral("lineEdit_42"));
        lineEdit_42->setEnabled(false);
        lineEdit_42->setGeometry(QRect(460, 440, 111, 20));
        lineEdit_43 = new QLineEdit(centralWidget);
        lineEdit_43->setObjectName(QStringLiteral("lineEdit_43"));
        lineEdit_43->setEnabled(false);
        lineEdit_43->setGeometry(QRect(460, 290, 111, 20));
        lineEdit_44 = new QLineEdit(centralWidget);
        lineEdit_44->setObjectName(QStringLiteral("lineEdit_44"));
        lineEdit_44->setEnabled(false);
        lineEdit_44->setGeometry(QRect(460, 470, 111, 20));
        lineEdit_45 = new QLineEdit(centralWidget);
        lineEdit_45->setObjectName(QStringLiteral("lineEdit_45"));
        lineEdit_45->setEnabled(false);
        lineEdit_45->setGeometry(QRect(460, 320, 111, 20));
        lineEdit_46 = new QLineEdit(centralWidget);
        lineEdit_46->setObjectName(QStringLiteral("lineEdit_46"));
        lineEdit_46->setEnabled(false);
        lineEdit_46->setGeometry(QRect(460, 380, 111, 20));
        lineEdit_47 = new QLineEdit(centralWidget);
        lineEdit_47->setObjectName(QStringLiteral("lineEdit_47"));
        lineEdit_47->setEnabled(false);
        lineEdit_47->setGeometry(QRect(600, 260, 111, 20));
        lineEdit_48 = new QLineEdit(centralWidget);
        lineEdit_48->setObjectName(QStringLiteral("lineEdit_48"));
        lineEdit_48->setEnabled(false);
        lineEdit_48->setGeometry(QRect(600, 350, 111, 20));
        lineEdit_49 = new QLineEdit(centralWidget);
        lineEdit_49->setObjectName(QStringLiteral("lineEdit_49"));
        lineEdit_49->setEnabled(false);
        lineEdit_49->setGeometry(QRect(600, 410, 111, 20));
        lineEdit_50 = new QLineEdit(centralWidget);
        lineEdit_50->setObjectName(QStringLiteral("lineEdit_50"));
        lineEdit_50->setEnabled(false);
        lineEdit_50->setGeometry(QRect(600, 230, 111, 20));
        lineEdit_51 = new QLineEdit(centralWidget);
        lineEdit_51->setObjectName(QStringLiteral("lineEdit_51"));
        lineEdit_51->setEnabled(false);
        lineEdit_51->setGeometry(QRect(600, 200, 111, 20));
        lineEdit_52 = new QLineEdit(centralWidget);
        lineEdit_52->setObjectName(QStringLiteral("lineEdit_52"));
        lineEdit_52->setEnabled(false);
        lineEdit_52->setGeometry(QRect(600, 440, 111, 20));
        lineEdit_53 = new QLineEdit(centralWidget);
        lineEdit_53->setObjectName(QStringLiteral("lineEdit_53"));
        lineEdit_53->setEnabled(false);
        lineEdit_53->setGeometry(QRect(600, 290, 111, 20));
        lineEdit_54 = new QLineEdit(centralWidget);
        lineEdit_54->setObjectName(QStringLiteral("lineEdit_54"));
        lineEdit_54->setEnabled(false);
        lineEdit_54->setGeometry(QRect(600, 470, 111, 20));
        lineEdit_55 = new QLineEdit(centralWidget);
        lineEdit_55->setObjectName(QStringLiteral("lineEdit_55"));
        lineEdit_55->setEnabled(false);
        lineEdit_55->setGeometry(QRect(600, 320, 111, 20));
        lineEdit_56 = new QLineEdit(centralWidget);
        lineEdit_56->setObjectName(QStringLiteral("lineEdit_56"));
        lineEdit_56->setEnabled(false);
        lineEdit_56->setGeometry(QRect(600, 380, 111, 20));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(320, 180, 111, 16));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(460, 180, 111, 16));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(600, 180, 111, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 748, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit_2);
        menuFile->addSeparator();
        menuHelp->addAction(actionGithub_Project);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Patchya", nullptr));
        actionGithub_Project->setText(QApplication::translate("MainWindow", "Github Project", nullptr));
        actionExit_2->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionAdd_SNR_Patch->setText(QApplication::translate("MainWindow", "Add SNR Patch", nullptr));
        actionAdd_Offset_Patch->setText(QApplication::translate("MainWindow", "Add Offset Patch", nullptr));
        actionRemove_SNR_Patch->setText(QApplication::translate("MainWindow", "Remove SNR Patch", nullptr));
        actionRemove_Offset_Patch->setText(QApplication::translate("MainWindow", "Remove Offset Patch", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "Memory Address", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "Memory Data Value", nullptr));
        radioButton_3->setText(QApplication::translate("MainWindow", "Timeout", nullptr));
        label->setText(QApplication::translate("MainWindow", "Gate Condition", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lineEdit->setInputMask(QApplication::translate("MainWindow", "hhhhhhhh", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "ex: 103B", nullptr));
        lineEdit_2->setInputMask(QApplication::translate("MainWindow", "hhhhhhhh", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "ex: 4064", nullptr));
        lineEdit_3->setInputMask(QApplication::translate("MainWindow", "99999999", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("MainWindow", "ex: 500", nullptr));
        lineEdit_4->setInputMask(QApplication::translate("MainWindow", "hhhhhhhh", nullptr));
        lineEdit_4->setPlaceholderText(QApplication::translate("MainWindow", "ex: A913", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "RVA of Data", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "RVA ", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "ms", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Data Value", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "SNR Patches", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Offset Patches", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Create Loader", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Loader Name", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Victim Path", nullptr));
        lineEdit_10->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        lineEdit_21->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        lineEdit_11->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        lineEdit_14->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        lineEdit_22->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        lineEdit_23->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        lineEdit_24->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        lineEdit_12->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        lineEdit_25->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        lineEdit_26->setInputMask(QApplication::translate("MainWindow", "Hhhhhhhh", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Search Pattern", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Replace Pattern", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Offset RVA ", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Original Data", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Patch Data", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
