include ../../buildenv.mk

MAJOR_VER := 1
MINOR_VER := 0


CFLAGS   += $(COMMON_FLAGS)

LIB_RATINGS_NAME := libratings.so

all : $(LIB_RATINGS_NAME)

.PHONY : all clean

$(LIB_RATINGS_NAME) : ratings.o
	gcc -shared $(CFLAGS) -Wl,-soname,$@.$(MAJOR_VER) -o $@.$(MAJOR_VER).$(MINOR_VER) $^
	#normal should do following steps by installing script and the correct location should be /opt/lib
	if [ ! -d $(ROOT_DIR)/bin ]; then mkdir -p $(ROOT_DIR)/bin; fi
	mv $@.$(MAJOR_VER).$(MINOR_VER) $(ROOT_DIR)/bin/
	ln -sf $(ABS_ROOT_DIR)/bin/$@.$(MAJOR_VER).$(MINOR_VER) $(ABS_ROOT_DIR)/bin/$@.$(MAJOR_VER)
	ln -sf $(ABS_ROOT_DIR)/bin/$@.$(MAJOR_VER).$(MINOR_VER) $(ABS_ROOT_DIR)/bin/$@
	if [ ! -d $(ROOT_DIR)/inc ]; then mkdir -p $(ROOT_DIR)/inc; fi
	cp ratings.h $(ROOT_DIR)/inc

ratings.o : ratings.c
	gcc -c -fPIC $(CFLAGS) $^

clean:
	rm -rf *.o
	rm -rf $(ROOT_DIR)/bin/libratings.*
	rm -rf $(ROOT_DIR)/inc/ratings.h


#libratings.so        # is called the linker-name used for linking.
#libratings.so.1      # is called the soname used by the operating system loader.
#libratings.so.1.0    # is called the real-name which is updated by the library maintainer.
