/*
 --------------------------------------------------
 Project: a2q3
 File:    mystring_ptest.c
 About:   public test driver
 Version: 2024-09-09
 --------------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include "mystring.h"

#define MAX_LINE 10
#define MAX_LINE_LEN 80
#define MAX_WORD

char  *displayformat0 = "%s('%s'): %d\n";
char  *displayformat1 = "%s('%s'): '%s'\n";
char  *displayformat2 = "%s('%s' '%s'): '%s'\n";

char tests[][80] = {
"Abc  DEF",
"  aBc   Def   ",
"  Toonie is the Canadian $2 coin. ",
"  Binary has 10 digits.  "
};

char tests1[][80] = {
"Abc",
"test",
"Canadian",
"10"
};

void test_str_wc() {
	printf("------------------\n");
	printf("Test: str_wc\n\n");
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++)
		//printf("str_wc(%s):%d\n", tests[i], str_wc(tests[i]));
		printf(displayformat0, "str_wc", tests[i], str_wc(tests[i]));

	printf("\n");
}

void test_str_lower() {
	printf("------------------\n");
	printf("Test: str_lower\n\n");
	char dest[MAX_LINE_LEN];
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++) {
		strcpy(dest, tests[i]);
		str_lower(dest);
		printf(displayformat1, "str_lower",  tests[i], dest);
	}
	printf("\n");
}

void test_str_trim() {
	printf("------------------\n");
	printf("Test: str_trim\n\n");
	char dest[MAX_LINE_LEN];
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++) {
		strcpy(dest, tests[i]);
		str_trim(dest);
		printf(displayformat1, "str_trim",  tests[i], dest);
	}
	printf("\n");
}

/*void test_str_str() {
	printf("------------------\n");
	printf("Test: str_str\n\n");
	char dest[MAX_LINE_LEN];
	int count = sizeof tests / sizeof *tests;
	for (int i = 0; i < count; i++) {
		char *p = str_str(tests[i], tests1[i]);
		if (p) {
		printf(displayformat2, "str_str", tests[i], tests1[i], p);
		}
		else  {
		printf(displayformat2, "str_str", tests[i], tests1[i], "null");
		}
	}
	printf("\n");
}
*/
int main(int argc, char* args[]) {
	test_str_wc();
	test_str_lower();
	test_str_trim();
	//test_str_str();
	return 0;
}
