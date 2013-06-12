### This Makefile was written for GNU Make. ###
CC      = gcc
LDLIBS  = -lm
CFLAGS  = -pipe -O3 -Wall -Wextra $(if $(STD), $(addprefix -std=, $(STD)),)
LDFLAGS = -pipe -O3 -s
TARGET  = problem2010
OBJ     = $(addprefix bin/, $(addsuffix .o, $(basename $(TARGET))))
SRC     = $(addprefix src/, $(addsuffix .c, $(basename $(TARGET))))


ifeq ($(OS),Windows_NT)
    TARGET := $(addsuffix .exe, $(TARGET))
    CFLAGS += -finput-charset=utf-8 -fexec-charset=cp932
endif


%.exe :
	$(CC) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@

%.o :
	@if [ ! -d $(dir $@) ]; then  \
	    mkdir $(dir $@);          \
	fi
	$(CC) $(CFLAGS) $(filter %.c, $^) -c -o $@


.PHONY : all
all : $(TARGET)

$(TARGET) : $(OBJ)

$(OBJ)    : $(SRC)


.PHONY : clean
clean :
	$(RM) $(TARGET) $(OBJ)
.PHONY : objclean
objclean :
	$(RM) $(OBJ)
