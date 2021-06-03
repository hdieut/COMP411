/* Example: analysis of text */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
  char charResult[MAX];
  int index = 0;

   printf("Your input in reverse is:");
   for (int x = 0; x <= length + 1; x++) {
	result[x] = text[length - x];
 	if (isalpha(result[x]) != 0) {
		charResult[index] = tolower(result[x]);
		index++;
   	}
   }

   printf("%s\n", result);
   for (int x = 0; x <= index-1; x ++) {
	if (charResult[x] == charResult[index - 1 - x]) {
		compare++;
	}
   }
   if (compare == index) {
   	printf("Found a palindrome!\n");
   }
}
