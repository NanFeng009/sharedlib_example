CFLAGS += -g

all:
	$(CC) $(CFLAGS) -c -o tst.o tst.c
	$(CC) -fpic $(CFLAGS) -c -o tstlib.o tstlib.c
	$(CC) -shared -Wl,-rpath=. -o tstlib.so  tstlib.o
	$(CC) -Wl,-rpath=. tst.o tstlib.so -o tst

clean:
	$(RM) *.o tst tstlib.so

ltrace:
	ltrace -n2  ./tst
	ltrace -n2 -l tstlib.so  ./tst

# http://notes.secretsauce.net/notes/2014/04/14_reading-dwarf-prototypes-in-ltrace.html
# For the implicit variable in makefile
# https://www.gnu.org/software/make/manual/make.html#Implicit-Variables
