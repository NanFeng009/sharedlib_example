BUILDFLAGS := -g

dog:dog.c
	gcc -c $(BUILDFLAGS) -fPIC dog.c
	gcc $(BUILDFLAGS) -shared -o ../../bin/libdog.so dog.o
	cp dog.h ../../inc


clean:
	rm -rf *.o *.so
	rm ../../inc/dog.h
