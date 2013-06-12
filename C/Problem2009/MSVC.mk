### This Makefile was written for nmake. ###
CC      = cl
CFLAGS  = /O2 /Wall /c
LDFLAGS = /O2
RM      = del /F
TARGET  = problem2009.exe
SRC_DIR = src
BIN_DIR = bin
OBJ     = $(BIN_DIR)\$(TARGET:.exe=.obj)
SRC     = $(SRC_DIR)\$(TARGET:.exe=.c)


all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(LDLAGS) $** /Fo$@

$(OBJ)    : $(SRC)
	@if not exist $(BIN_DIR)\NUL  \
	    mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) $** /Fo$@


clean :
	$(RM) $(TARGET) $(OBJ)
objclean :
	$(RM) $(OBJ)
