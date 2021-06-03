#include <stdio.h>
#include <stdlib.h>

int x, y; 

int main() {
	printf("Please enter width and height:\n");
	scanf("%i", &x);
	if (x == 0) {
		printf("End\n");
		exit(1);
	}

	scanf("%i", &y);
	for (int i = 1; i <= y; i++) {
		for(int j = 1; j <= x; j++) {
			if((j == 1 || j == x) && (i == 1 || i == y)) {
				printf("+");
			} else if ((j == 1 || j == x) && (i != 1 || i !=y)) {
				printf("|");
			} else if ((j != 1 && j != x) && (i != 1 && i != y)) {
				printf("~");
			} else {
				printf("-");
			}
		}
		printf("\n");
	}
	main();
}
