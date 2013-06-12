### This Makefile was written for nmake. ###
CC      = cl
CFLAGS  = /O2 /Wall /c
LDFLAGS = /O2
RM      = del /F
TARGET1 = problem2004b-01.exe
TARGET2 = problem2004b-02.exe
SRC_DIR = src
BIN_DIR = bin
OBJ1    = $(BIN_DIR)\$(TARGET1:.exe=.obj)
OBJ2    = $(BIN_DIR)\$(TARGET2:.exe=.obj)
SRC1    = $(SRC_DIR)\$(TARGET1:.exe=.c)
SRC2    = $(SRC_DIR)\$(TARGET2:.exe=.c)


all : $(TARGET1) $(TARGET2)

$(TARGET1) : $(OBJ1)
	$(CC) $(LDLAGS) $** /Fo$@

$(OBJ1)    : $(SRC1)
	@if not exist $(BIN_DIR)\NUL  \
	    mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) $** /Fo$@

$(TARGET2) : $(OBJ2)
	$(CC) $(LDLAGS) $** /Fo$@

$(OBJ2)    : $(SRC2)
	@if not exist $(BIN_DIR)\NUL  \
	    mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) $** /Fo$@


clean :
	$(RM) $(TARGET1) $(TARGET2) $(OBJ1) $(OBJ2)
objclean :
	$(RM) $(OBJ1) $(OBJ2)
