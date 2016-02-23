/*
  Legge un vettore il cui numero di elementi
viene dato da input.
*/
#include<stdio.h>
#include<stdlib.h>

int main() {
  int *a;
  int d;
  int i;

			/* chiede il numero di elementi */
  printf("Quanti elementi? ");
  scanf("%d", &d);

			/* alloca il vettore */
  a=malloc(d*sizeof(int));

			/* legge gli elementi */
  for(i=0; i<=d-1; i++) {
    printf("Dammi l'elemento a[%d]: ", i);
    scanf("%d", &(a[i]));
  }

			/* stampa gli elementi del vettore */
  for(i=0; i<=d-1; i++) {
    printf("a[%d] vale %d\n", i, a[i]);
    }
    free(a);
  return 0;
}
