### This Makefile was written for GNU Make. ###
CC      = gcc
MACROS  = -DDEBUG
CFLAGS  = -pipe -O3 -Wall -Wextra $(if $(STD), $(addprefix -std=, $(STD)),) $(MACROS)
LDFLAGS = -pipe -O3 -s
TARGET1 = problem2004b-01
TARGET2 = problem2004b-02
OBJ1    = $(addprefix bin/, $(addsuffix .o, $(basename $(TARGET1))))
OBJ2    = $(addprefix bin/, $(addsuffix .o, $(basename $(TARGET2))))
SRC1    = $(addprefix src/, $(addsuffix .c, $(basename $(TARGET1))))
SRC2    = $(addprefix src/, $(addsuffix .c, $(basename $(TARGET2))))


ifeq ($(OS),Windows_NT)
    TARGET1 := $(addsuffix .exe, $(TARGET1))
    TARGET2 := $(addsuffix .exe, $(TARGET2))
    CFLAGS  += -finput-charset=utf-8 -fexec-charset=cp932
endif


%.exe :
	$(CC) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@

%.o :
	@if [ ! -d $(dir $@) ]; then  \
	    mkdir $(dir $@);          \
	fi
	$(CC) $(CFLAGS) $(filter %.c, $^) -c -o $@


.PHONY : all
all : $(TARGET1) $(TARGET2)

$(TARGET1) : $(OBJ1)

$(OBJ1)    : $(SRC1)

$(TARGET2) : $(OBJ2)

$(OBJ2)    : $(SRC2)


.PHONY : clean
clean :
	$(RM) $(TARGET1) $(TARGET2) $(OBJ1) $(OBJ2)
.PHONY : objclean
objclean :
	$(RM) $(OBJ1) $(OBJ2)
