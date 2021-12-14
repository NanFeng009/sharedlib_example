FLAGS := -Wl,-rpath=.
FLAGS += -Wl,-Map=ani.map.txt
FLAGS += -Wl,-t

#include the header file search path
FLAGS += -Idog_lib -Icat_lib

FLAGS += -g

all:ani

main.o:main.c
	gcc $(FLAGS) -c main.c

dog:
	make -C dog_lib

cat:
	make -C cat_lib

ani: dog cat main.o
	gcc $(FLAGS) main.o -L. -L../bin -ldog -lcat -o ../bin/ani

clean:
	make -C dog_lib clean
	make -C cat_lib clean
	rm -rf *.o ani.map.txt
