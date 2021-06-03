/* Example: analysis of text */

#include <stdio.h>
#include <string.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
  char text[MAX];
  int length;
 
  puts("Type some text (then ENTER):");
  
  /* Save typed characters in text[]: */
    
  fgets(text, MAX, stdin);
  length = strlen(text) - 1;
  
  /* Analyse contents of text[]: */
  
  int compare = 0;
  char result[MAX];

  printf("Your input in reverse is:");
  for (int x = 0; x <= length + 1; x++) {
	result[x] = text[length - x];
  }
  printf("%s\n", result);

  for (int x = 0; x <= length; x++) {
	if (result[x] == result[length + 1 - x]) {
		compare++;
	}
  }

  if (compare == length) {
     printf("Found a palindrome!\n");
  }
}
