MAKE ?= make
TARGET_DIR01 = Problem2007
TARGET_DIR02 = Problem2007haru
TARGET_DIR03 = Problem2008haru
TARGET_DIR04 = Problem2009/01
TARGET_DIR05 = Problem2009/02
TARGET_DIR06 = Problem2010
TARGET_DIR07 = Problem2011
TARGET_DIR08 = Problem2012/01
TARGET_DIR09 = Problem2012/02
TARGET_DIR10 = Problem2012haru
TARGET_DIR11 = Problem2014
DIR_LIST     = $(TARGET_DIR01) $(TARGET_DIR02) $(TARGET_DIR03) $(TARGET_DIR04)  \
               $(TARGET_DIR05) $(TARGET_DIR06) $(TARGET_DIR07) $(TARGET_DIR08)  \
               $(TARGET_DIR09) $(TARGET_DIR10) $(TARGET_DIR11)


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
