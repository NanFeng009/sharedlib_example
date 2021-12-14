
BUILDFLAGS := -g

cat:cat.c
	gcc -c $(BUILDFLAGS) -fPIC cat.c
	gcc $(BUILDFLAGS) -shared -o ../../bin/libcat.so cat.o


clean:
	rm -rf *.o *.so
