.SUFFIXES: .c .o

lab01: lab01.o variant.o test.o
	gcc -lm --std=gnu99 -o lab01 variant.o lab01.o test.o

.c.o:
	gcc -lm --std=gnu99 -c -o $@ $<

lab01.o: lab01.c variant.h test.h
test.o: test.c test.h lab01.h
variant.o: variant.c variant.h

clean:
	rm -f *.o
	rm -f *~
	rm -f *.bak
