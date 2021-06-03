#include <stdio.h>

int N;
char pattern[11];

void binary(int currentlevel) {
	if (currentlevel == N) {
		printf("%s\n", pattern);
	} else {
		pattern[currentlevel] = '0';
		binary(currentlevel+1);
		pattern[currentlevel] = '1';
		binary(currentlevel+1);
	}
}

int main() {
	scanf("%d", &N);
	pattern[N] = '\0';
	binary(0);
}

