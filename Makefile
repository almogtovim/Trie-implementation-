gcc=CC
-wall=FLAG

all: mains maind

mains: main.o libmyMath.a
	$(CC) $(FLAG) -o mains main.o -L. libmyMath.a

maind: main.o libmyMath.so
	$(CC) $(FLAG) -o maind main.o -L. ./libmyMath.so

mymaths: libmyMath.a

libmyMath.a :basicMath.o power.o myMath.h
	ar -rcs libmyMath.a basicMath.o power.o

mymathd: libmyMath.so

libmyMath.so: basicMath.o power.o myMath.h
	$(CC) -shared -o libmyMath.so basicMath.o power.o

main.o: main.c myMath.h
	$(CC) $(FLAG) -c main.c

power.o: power.c myMath.h
	$(CC) $(FLAG) -fPIC -c power.c

basicMath.o: basicMath.c myMath.h
	$(CC) $(FLAG) -c basicMath.c 

clean:
	rm -f *.o *.a *.so mains maind
