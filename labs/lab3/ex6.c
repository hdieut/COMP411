#include <stdio.h>

int NchooseK(int x, int y);

int main() {

  int a, b, c;
  
  printf("Enter two integers (for n and k) separated by space:\n");
  scanf("%d", &a);
  scanf("%d", &b);
  c = NchooseK(a, b);
  printf("%d\n", c);
  if (a != 0) 
	main();
}



int NchooseK(int x, int y) {
  if (y == 0 || x == y) return 1;
  return  NchooseK(x - 1, y - 1) + NchooseK(x - 1, y);

}
