#include <stdio.h>

typedef struct {
	int year;
	int month;
	int day;
	int ID;
} record;

record data[50];
int i;

int compare_ints(int x, int y) {
	if (x == y) { return 0; } 
	if (x < y) { return -1; }
	if (x > y) { return 1; }
}

void swap_records(record *p1, record *p2) {
	record temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	
/*	for(int x = 0; x < 1; x++) {
		temp[x].year = a[x].year;
		temp[x].month = a[x].month;
		temp[x].day = a[x].day;
		temp[x].ID = a[x].ID;

		a[x].year = b[x].year;
		a[x].month = b[x].month;
		a[x].day = b[x].day;
		a[x].ID = b[x].ID;
		
		b[x].year = temp[x].year;
		b[x].month = temp[x].month;
		b[x].day = temp[x].day;
		b[x].ID = temp[x].ID;
	}
*/ 
}


int main() {
	
	// scan in number of inputs 
	scanf("%d", &i);

	// scan in rest of data 
	for (int x = 0; x < i; x++) {
		scanf("%d", &data[x].year);
		scanf("%d", &data[x].month);
		scanf("%d", &data[x].day);
		scanf("%d", &data[x].ID);
	}
	
	// loop to compare data and swap when necessary
	for(int x = 0; x < i-1; x++) {
		for(int y = x+1; y < i; y++) {
			record *p = &data[x];
			record *s = &data[y];

			if (compare_ints(data[x].year, data[y].year) == 0) {
				if (compare_ints(data[x].month, data[y].month) ==  1) {
					swap_records(&data[x], &data[y]);
				} else if (compare_ints(data[x].month, data[y].month) == 0) {
					if (compare_ints(data[x].day, data[y].day) == 1) {
						swap_records(&data[x], &data[y]);
					} else if (compare_ints(data[x].day, data[y].day) == 0) {
						if (compare_ints(data[x].ID, data[y].ID) == 1) {
							swap_records(&data[x], &data[y]);
						}
					}
				}
			} else if (compare_ints(data[x].year, data[y].year) == 1) {
				swap_records(&data[x], &data[y]);
			}
		}
	}

	// print data 
	for(int x = 0; x < i; x++) {
		printf("%d %d %d %d\n", data[x].year, data[x].month, data[x].day, data[x].ID);
	}
}
