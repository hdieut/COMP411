#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  char buf[MAX_BUF];
  int length;
  char result[MAX_BUF];

  // other stuff

  do {
        // read a line
	fgets(buf, MAX_BUF, stdin);
        // calculate its length
	length = strlen(buf);
        // modify the line by switching characters
	if (buf[length-2] == '\n' || buf[length-2] == '\0') break;
	for (int i = 0; i <= length; i++) {
		if (buf[i] == 'e' || buf[i] == 'E') {
			result[i] = '3';
		} else if (buf[i] == 'i' || buf[i] == 'I') {
			result[i] = '1';
		} else if (buf[i] == 'o' || buf[i] == 'O') {
			result[i] = '0';
		} else if (buf[i] == 's' || buf[i] == 'S') {
			result[i] = '5';
		} else {
			result[i] = buf[i];
		}
	}
        // print the modified line
	printf("%s", result);
  } while (length > 1); {

  }
}
