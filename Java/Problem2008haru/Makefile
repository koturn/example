### This Makefile was written for GNU Make. ###
JAVAC       = javac
JAR         = jar

TARGET      = Problem2008haru.jar
SRC_DIR     = src
BIN_DIR     = bin
MAIN_SRC    = $(SRC_DIR)/FracTest.java
MAIN_BIN    = $(BIN_DIR)/FracTest.class
MAIN        = $(basename $(notdir $(MAIN_BIN)))
MANIFEST    = MANIFEST.MF
SRCS        = $(addprefix $(SRC_DIR)/, $(addsuffix .java, $(MAIN) Fraction MixedFraction))
OBJS        = $(addprefix $(BIN_DIR)/, $(notdir $(SRCS:%.java=%.class)))

ENCODE      = utf-8
JFLAGS      = -sourcepath $(SRC_DIR) -encoding $(ENCODE) -d $(BIN_DIR)      \
              $(if $(SRC_VERSION), $(addprefix -source , $(SRC_VERSION)),)  \
              $(if $(BIN_VERSION), $(addprefix -target , $(BIN_VERSION)),)


.PHONY : all
all : $(TARGET)

$(TARGET) : $(OBJS) $(MANIFEST)
	$(JAR) cvfm $@ $(MANIFEST) -C $(dir $<) .

$(MANIFEST) :
	echo "Main-Class: $(MAIN)" > $(MANIFEST)

$(MAIN_BIN) : $(SRCS)
	@if [ ! -d $(dir $@) ]; then  \
	    mkdir $(dir $@);          \
	fi
	$(JAVAC) $(JFLAGS) $(MAIN_SRC)


.PHONY : clean
clean :
	$(RM) $(TARGET) $(BIN_DIR)/*.class
.PHONY : objclean
objclean :
	$(RM) $(BIN_DIR)/*.class
