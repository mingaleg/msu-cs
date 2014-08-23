all:
	echo "Use 'make main_down' or 'make main_abs_up'"

main_down: main_down.o cmp.o swap.o timestamp.o
	gcc -std=gnu99 -m32 -o main_down main_down.o cmp.o swap.o timestamp.o
main_abs_up: main_abs_up.o cmp.o swap.o timestamp.o
	gcc -std=gnu99 -m32 -o main_abs_up main_abs_up.o cmp.o swap.o timestamp.o

main_down.o: main.c
	gcc -std=gnu99 -m32 -c main.c -o main_down.o -DCMP=cmp_down
main_abs_up.o: main.c
	gcc -std=gnu99 -m32 -c main.c -o main_abs_up.o -DCMP=cmp_abs_up

cmp.o: cmp.asm
	nasm -f elf32 cmp.asm -o cmp.o
swap.o: swap.asm
	nasm -f elf32 swap.asm -o swap.o
timestamp.o:
	nasm -f elf32 timestamp.asm -o timestamp.o

clean:
	rm -f *.o
