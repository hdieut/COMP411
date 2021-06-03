#include <stdio.h>

int A[10][10];
int B[10][10];
int C[10][10];
int M;

int main() {

	scanf("%d", &M);
	for (int i=0; i < M; i++) {
		for(int j=0; j<M; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	for (int i = 0; i<M; i++) {
		for(int j = 0; j<M; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j<M; j++) {
			for(int k = 0; k<M; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			printf("%6d", C[i][j]);
		}
		printf("\n");
	}
}
