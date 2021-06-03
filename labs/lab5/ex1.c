#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define true 1
#define false 0

#define MAX 100

char maze[MAX][MAX];
char wasHere[MAX][MAX];
char correctPath[MAX][MAX];
int width, height;
int startX, startY, endX, endY;
char tempString[MAX+2];   // To read in one line of the maze

bool recursiveSolve(int x, int y);

int main() {

  int x, y;
  scanf("%d%d", &width, &height);
  scanf("\n");    // This is needed to "eat" the newline after height,
                  // before the actual maze entries begin on the next line


  /* NOTE:  maze[y][x] will refer to the (x,y) element of the maze,
	   i.e., y-th row and x-th column in the maze.
     The row is typically the first index in a 2D array because
     reading and writing is done row-wise.  This is called
     "row-major" order.

     Also note that although we have declared the maze to be 100x100,
     that is the maximum size we need.  The actual entries in the
     maze will be height * width.
  */


  for(y=0; y < height; y++) {
    fgets(tempString, width+2, stdin);  // Read #width chars, plus newline and NULL into tempString
    for(x=0; x < width; x++) {          // Copy only the actual #width chars into the maze
      maze[y][x]=tempString[x];
 
      if (maze[y][x] == 'S') {
		startX = x;
		startY = y;
      } else if (maze[y][x] == 'F') {
		endX = x;
		endY = y;      // Check for 'S' and 'F' here and use that to
      }			      // set values of startX, startY, endX and endY

      wasHere[y][x] = 0;     // initialize
      correctPath[y][x] = 0; // initialize
    }
  }

  recursiveSolve(startX, startY);

  for (y=0; y < height; y++) {         // Code to print the output maze
	for (x=0; x < width; x++) {
		if (correctPath[y][x] == 1) {
			maze[y][x] = '.';
		}

	}
	 printf("%s\n", maze[y]); 
  }

}


bool recursiveSolve(int x, int y) {
  if (x == endX && y == endY) { return true; }
  if (maze[y][x] == '*' || wasHere[y][x]) { return false; }
  wasHere[y][x] = 1;
  if (x != 0) {
	if (recursiveSolve(x-1, y)) {
		correctPath[y][x] = 1;
		return true;
	}
  }
  if (x != width - 1) {
	if (recursiveSolve(x+1, y)) {
		correctPath[y][x] = 1;
		return true;
	}
  }
  if (y != 0) {
	if (recursiveSolve(x, y-1)) {
		correctPath[y][x] = 1;
		return true;
	}
  }
  if (y != height - 1) {
	if (recursiveSolve(x, y+1)) {
		correctPath[y][x] = 1;
		return true;
	}
  }
  return false;
  /* You can pretty much use the body of the code in the java version
      with almost no changes at all!  I only had to change *one* line!
  */
}
