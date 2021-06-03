/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

int main()
{
  char Strings[NUM][LEN];

  printf("Please enter %d strings, one per line:\n", NUM);

  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */

  for (int x = 0; x < NUM; x++) {
	fgets(Strings[x], LEN, stdin);
  }
  puts("\nHere are the strings in the order you entered:");

  /* Write a for loop here to print all the strings. */
  
  for (int y = 0; y < NUM; y++) {
	printf("%s", Strings[y]);
  }
  
  /* Bubble sort */

  char tempstring[NUM][LEN];
  for (int i = 0; i < NUM-1; i++) {
	for (int j = i + 1; j < NUM; j++) {
		if (strcmp(Strings[i], Strings[j]) > 0) {
			strcpy(tempstring[i], Strings[i]);
			strcpy(Strings[i], Strings[j]);
			strcpy(Strings[j], tempstring[i]);
		}
	}
  }

  
  
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */

  for (int z = 0; z < NUM; z++) {
	printf("%s", Strings[z]);
  }
}
