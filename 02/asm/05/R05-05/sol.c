#include <stdio.h>

#define BUF_SIZE 4096

int foo(unsigned char *s1, unsigned char *s2, char *omg) 
{
	unsigned char c = 0;
	do {
		omg[c] = c;
	} while (c++ != 255);
    while (*s1 && *s2) {
		omg[*s1] = *s2;
        ++s1; ++s2;
    }
	return !*s1 && !*s2;
}

void bar(unsigned char *omg, unsigned char *str) {
	while (*str) {
        *str = omg[*str];
        ++str;
	}
}

int main(int argc, char *argv[]) {
	unsigned char s1[256], s2[256];
	fgets(s1, 256, stdin);
	fgets(s2, 256, stdin);

	unsigned char lol[256];
	if (!foo(s1, s2, lol)) return 0;

	unsigned int strings;
	scanf("%u%*1[\n]", &strings);
	while (strings--) {
		unsigned char str[BUF_SIZE];
		fgets(str, BUF_SIZE, stdin);
		bar(lol, str);
		printf("%s", str);
	}

	return 0;
}
