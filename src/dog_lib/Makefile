BUILDFLAGS := -g

dog:dog.c
	gcc -c $(BUILDFLAGS) -fPIC dog.c
	gcc $(BUILDFLAGS) -shared -o ../../bin/libdog.so dog.o


clean:
	rm -rf *.o *.so
