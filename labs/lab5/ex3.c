#include <stdio.h>
#include <string.h>

char animals[20][15];
char lyrics[20][60];
int  number;

void nurseryrhyme(int current) {
                 // print "current" number of spaces

  if (current == 0) {
	printf("There was an old lady who swallowed a %s;\n", animals[current]); 
  } else if (current > 0) {
	printf("%*s", current, "");
	printf("She swallowed the %s to catch the %s;\n", animals[current++], animals[current--]);
  }
                                                // print something before the recursive call
                                                // you need to check if the current level is 0
                                                //   if so, print "There was an old lady..."
                                                //   or if it is > 0, print "She swallowed ...
  if(current < number-1)                        // if we are not at the last animal, make the recursive call
    nurseryrhyme(current+1);

                                                // print something after the recursive call
  printf("%*s", current , "");
  printf("I don't know why she swallowed a %s - %s\n", animals[current], lyrics[current]);
}



int main() {
  int i=0;

  while (1) {
                                                // read the next animal name
   fgets(animals[i], 15, stdin);

    if (strcmp(animals[i], "END\n") == 0)       // if it is "END\n", we are done reading
      break;
                           
    int length = strlen(animals[i])-1;
    animals[i][length] = '\0';                     // determine the length of the string read
    fgets(lyrics[i], 60, stdin);                                           // strip the newline at the end
    length = strlen(lyrics[i])-1;
    lyrics[i][length] = '\0';                                            // read the lyric corresponding to the animal
    i++;
  }

  number = i;

  nurseryrhyme(0);
}
