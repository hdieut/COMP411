#include <stdio.h>

int main() {

int x, y;

printf("Enter a number from 1 to 20:\n");
scanf("%i", &x);

if (x < 1 || x > 20) {
        printf("Number is not in the range from 1 to 20\n");
} 
else {
	printf("Here are the first %i ordinal numbers:\n", x);
	
	y = 1;
	while (y <= x) {
		if (y == 1) {
			printf("1st\n");
		} 
		else if (y == 2) {
			printf("2nd\n");
		}
		else if (y == 3) {
			printf("3rd\n");
		}
		else {
			printf("%ith\n", y);
		}
		y++;
	}

}
}
