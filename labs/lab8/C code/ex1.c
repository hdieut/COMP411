#include <stdio.h>

int AA[100];
int BB[100];
int CC[100];
int M;

int main() {

        scanf("%d", &M);
        for (int i=0; i < M*M; i++) {
   //             for(int j=0; j<M; j++) {
                        scanf("%d", &AA[i]);
     //           }
        }
        
        for (int i = 0; i < M*M; i++) {
             //   for(int j = 0; j<M; j++) {
                        scanf("%d", &BB[i]);
               // }
        }

        for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                        for(int k = 0; k<M; k++) {
                                CC[i*M+j] += AA[i*M+k] * BB[k*M+j];
                        }
                }
        }

        for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                        printf("%d ", CC[i*M+j]);
                }
                printf("\n");
        }
}


