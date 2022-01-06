all:
	cc -g -c -o tst.o tst.c
	cc -fpic -g -c -o tstlib.o tstlib.c
	cc -shared -Wl,-rpath=. -o tstlib.so  tstlib.o
	cc -Wl,-rpath=. tst.o tstlib.so -o tst

clean:
	rm -r *.o tst tstlib.so

ltrace:
	ltrace -n2  ./tst
	ltrace -n2 -l tstlib.so  ./tst

#http://notes.secretsauce.net/notes/2014/04/14_reading-dwarf-prototypes-in-ltrace.html
