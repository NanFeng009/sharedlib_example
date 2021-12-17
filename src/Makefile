include ../buildenv.mk
CFLAGS   += $(COMMON_FLAGS)

LD_FLAGS += $(COMMON_LDFLAGS)
LD_FLAGS += -Wl,-rpath .

INC_PATH := $(ROOT_DIR)/inc

all : dependent runtime lib_rating 

.PHONY : dependent runtime lib_rating clean

dependent : lib_rating dependent.o
	if [! -d $(ROOT_DIR)/bin ]; then mkdir -p $(ROOT_DIR)/bin; fi
	gcc dependent.o -L$(ROOT_DIR)/bin -lratings $(LD_FLAGS) -o $(ROOT_DIR)/bin/$@

dependent.o : dependent.c
	gcc -I$(INC_PATH) -c $(CFLAGS) dependent.c


runtime : lib_rating runtime.o
	gcc runtime.o -ldl -o $(ROOT_DIR)/bin/$@

runtime.o : runtime.c
	gcc -I$(INC_PATH) -c $(CFLAGS) $^

lib_rating:
	make -C lib_rating


.PHONY: lib_rating dependent runtime clean all
clean:
	make -C lib_rating clean
	rm -rf $(ROOT_DIR)/bin/runtime $(ROOT_DIR)/bin/dependent
	rm -rf runtime.o dependent.o
