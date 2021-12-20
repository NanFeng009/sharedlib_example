include ../buildenv.mk
CFLAGS   += $(COMMON_FLAGS)

LD_FLAGS += $(COMMON_LDFLAGS)
LD_FLAGS += -Wl,-rpath .

INC_PATH := $(ROOT_DIR)/inc

all : dependent runtime lib_rating ani

.PHONY : dependent runtime lib_rating dog_lib clean 

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

ani : dog main.o
	gcc $(CFLAGS) -Wl,-rpath=. main.o -L . -L../bin -ldog -o ../bin/ani

dog:
	make -C dog_lib

main.o : main.c
	gcc $(CFLAGS) -I$(INC_PATH) -c main.c

.PHONY: lib_rating dependent runtime clean all
clean:
	make -C lib_rating clean
	make -C dog_lib
	rm -rf $(ROOT_DIR)/bin/runtime $(ROOT_DIR)/bin/dependent
	rm -rf runtime.o dependent.o
	rm -rf main.o
