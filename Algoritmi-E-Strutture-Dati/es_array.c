#include <stdio.h>

int sequenze(char a[], int inf, int sup){
	
	/*caso base */
	if(inf>=sup) {
		return 0;
	}

	int m = (inf+sup)/2;

	if (a[m]=='a' && a[m+1]=='r'){
		return 1+sequenze(a,inf,m)+sequenze(a,m+1,sup);
	} else {
		return sequenze(a,inf,m) + sequenze(a,m+1,sup);
	}
}

int main() {
	char a[] = {'b','a','r','c','a','r'};
	//int a [] = {'a', 'b', 'c', 'r'};
	printf("N° sequenze: %d",sequenze(a, 0, 5));
	return 0;
}