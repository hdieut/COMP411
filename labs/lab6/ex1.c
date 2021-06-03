#include <stdio.h> 

int num, sum;
int main() {

  do {
	printf("Number ?\n");
	scanf("%d", &num);
	
	if (num == 0) {
		printf("Done\n");
		break;
	}
	sum = 0;
	for (int x = 1; sum < num; x++) {
		sum +=  x;
	}

	if (num == sum) {
		printf("%d is a triangular number\n", num);
	} else {
		printf("%d is not a triangular number\n", num);
	} 
  } while (num > 0); 
}
