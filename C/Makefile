MAKE ?= make
TARGET_DIR01 = Problem2004a
TARGET_DIR02 = Problem2004b
TARGET_DIR03 = Problem2005a
TARGET_DIR04 = Problem2005b
TARGET_DIR05 = Problem2006a
TARGET_DIR06 = Problem2006b
TARGET_DIR07 = Problem2007
TARGET_DIR08 = Problem2007haru
TARGET_DIR09 = Problem2008
TARGET_DIR10 = Problem2008haru
TARGET_DIR11 = Problem2009
TARGET_DIR12 = Problem2010
TARGET_DIR13 = Problem2011
TARGET_DIR14 = Problem2012
TARGET_DIR15 = Problem2012haru
TARGET_DIR16 = Problem2014
DIR_LIST     = $(TARGET_DIR01) $(TARGET_DIR02) $(TARGET_DIR03) $(TARGET_DIR04)  \
               $(TARGET_DIR05) $(TARGET_DIR06) $(TARGET_DIR07) $(TARGET_DIR08)  \
               $(TARGET_DIR09) $(TARGET_DIR10) $(TARGET_DIR11) $(TARGET_DIR12)  \
               $(TARGET_DIR13) $(TARGET_DIR14) $(TARGET_DIR15) $(TARGET_DIR16)


.PHONY : all
all :
	@for dir in $(DIR_LIST); do  \
	    $(MAKE) -C $$dir;        \
	done

.PHONY : clean
clean :
	@for dir in $(DIR_LIST); do  \
	    $(MAKE) -C $$dir clean;  \
	done

.PHONY : objclean
objclean :
	@for dir in $(DIR_LIST); do     \
	    $(MAKE) -C $$dir objclean;  \
	done
