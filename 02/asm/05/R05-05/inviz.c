#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>

#define BUF_SIZE 4096

static bool make_substitution_table(const unsigned char *s1,
                                    const unsigned char *s2,
                                    char *substitution_table) {
	unsigned char c = 0;
	do {
		substitution_table[c] = c;
	} while (c++ != UCHAR_MAX);
	for (; *s1 && *s2; ++s1, ++s2) {
		substitution_table[*s1] = *s2;
	}
	return !*s1 && !*s2;
}

static void apply_substitution(const unsigned char *substitution_table,
                               unsigned char *str) {
	for (; *str; ++str) {
		*str = substitution_table[*str];
	}
}

int main(int argc, char *argv[]) {
	unsigned char s1[UCHAR_MAX + 1], s2[UCHAR_MAX + 1];
	fgets(s1, sizeof(s1), stdin);
	fgets(s2, sizeof(s2), stdin);

	unsigned char substitution_table[UCHAR_MAX + 1];
	if (!make_substitution_table(s1, s2, substitution_table)) {
		return 0;
	}

	size_t queries;
	scanf("%zu%*1[\n]", &queries);
	while (queries--) {
		unsigned char query[BUF_SIZE];
		fgets(query, sizeof(query), stdin);
		apply_substitution(substitution_table, query);
		printf("%s", query);
	}

	return 0;
}
