#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void reverse(int * a) {
	for(int i = 1; i < a[0] / 2 + 1; ++i)
		swap(&a[i], &a[a[0] - i]);
}

void add(int * a, int * b, int * c) {
	int buff = 0;
	int n = (a[0] < b[0] ? b[0] : a[0]);
	for(int i = 1; i < n + buff; ++i) {
		c[i] = a[i] + b[i] + buff;
		if(c[i] > 9) {
			c[i] %= 10;
			buff = 1;
		}
		else
			buff = 0;
		if(i == n)
			n++;
	}
	for(int i = n - 1; i > 0; --i)
		printf("%d", c[i]);
}

void sub(int * a, int * b, int * c) {
	int buff = 0;
	int n = (a[0] < b[0] ? b[0] : a[0]);
	for(int i = 1; i < n; ++i) {
		c[i] = a[i] - b[i] - buff;
		if(c[i] < 0) {
			c[i] += 10;
			buff = 1;
		}
		else
			buff = 0;
		if((i + 1 == n) && buff) {
			printf("-");
			sub(b, a, c);
			buff = -1;
		}
	}
	c[0] = n;
	while((!c[c[0] - 1]) && (c[0] != 2))
		--c[0];
	if(buff >= 0)
		for(int i = c[0] - 1; i > 0; --i)
			printf("%d", c[i]);
}

void mul(int * a, int * b, int * c) {
	for(int i = 1; i < a[0]; ++i)
		for(int j = 1; j < b[0]; ++j) {
			c[i + j - 1] += (a[i] * b[j]) % 10;
			c[i + j] += (a[i] * b[j]) / 10;
		}
	c[0] = a[0] + b[0];
	for(int i = 1; i < c[0]; ++i) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while((!c[c[0] - 1]) && (c[0] != 2))
		--c[0];
	for(int i = c[0] - 1; i > 0; --i)
		printf("%d", c[i]);
}

int main(void) {
	int *a = (int *)calloc(10001, sizeof(int));
	int *b = (int *)calloc(10001, sizeof(int));
	int *c = (int *)calloc(20021, sizeof(int));

	char x = getchar();

	for(a[0] = 1; (x >= '0') && (x <= '9'); ++a[0]) {
		a[a[0]] = x - '0';
		x = getchar();
	}
	char act = x;
	x = getchar();
	for(b[0] = 1; (x >= '0') && (x <= '9'); ++b[0]) {
		b[b[0]] = x - '0';
		x = getchar();
	}

	reverse(a);
	reverse(b);
	if(act == '+')
		add(a, b, c);
	if(act == '-')
		sub(a, b, c);
	if(act == '*')
		mul(a, b, c);
	free(a);
	free(b);
	free(c);
}
