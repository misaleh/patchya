CC       :=C:/mingw64/bin/gcc.exe
LINK	 :=C:/mingw64/bin/gcc.exe
CFLAGS   :=-g -O0 -Wall
INCLUDES :=-Ipatchya-loader\Source\Arch\Win32 -Ipatchya-loader\Source 
SRC_DIR  :=patchya-loader\Source
OUTPUT   :=patchya-loader\Build
QTOUTPUT :=patchya-config\Build\release
DEL_CMD  :=del
COPY_CMD :=copy

.PHONY : all
all : patchya-loader
 
# Link the object files into a binary
patchya-loader : config.o  debugger.o logger.o bin_funcs.o patchya-loader.o search_alg.o debugger_win32.o
	$(LINK) -o $(OUTPUT)\patchya-loader.exe $(OUTPUT)\debugger_win32.o $(OUTPUT)\config.o  $(OUTPUT)\debugger.o $(OUTPUT)\logger.o $(OUTPUT)\bin_funcs.o $(OUTPUT)\patchya-loader.o $(OUTPUT)\search_alg.o


debugger_win32.o : $(SRC_DIR)\Arch\Win32\debugger_win32.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)\Arch\Win32\debugger_win32.c -o $(OUTPUT)\debugger_win32.o
	

config.o : $(SRC_DIR)\config.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)\config.c -o $(OUTPUT)\config.o


debugger.o : $(SRC_DIR)\debugger.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)\debugger.c -o $(OUTPUT)\debugger.o


logger.o : $(SRC_DIR)\logger.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)\logger.c -o $(OUTPUT)\logger.o

bin_funcs.o : $(SRC_DIR)\bin_funcs.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)\bin_funcs.c -o $(OUTPUT)\bin_funcs.o

search_alg.o : $(SRC_DIR)\search_alg.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)\search_alg.c -o $(OUTPUT)\search_alg.o
	
patchya-loader.o : $(SRC_DIR)\patchya-loader.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)\patchya-loader.c -o $(OUTPUT)\patchya-loader.o
	
	
.PHONY : clean
clean :
	$(DEL_CMD) $(OUTPUT)
	
.PHONY : install
install :
	$(COPY_CMD)  $(QTOUTPUT)\p-configurator.exe  Release\Win32\ && 	copy  $(OUTPUT)\patchya-loader.exe  Release\Win32\
