#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mia_libreria.h"


int main() {

    int scelta;
    char c;
    FILE *strings_eng;
    while (1) {
        strings_eng = fopen("strings_eng.txt", "r");
        if (strings_eng == NULL) {
            printf("Error open file!");
            printf("Insert a valid txt file");
        }
        else {
            while((c=fgetc(strings_eng))!=EOF) {
                printf("%c", c);
            }
            fclose(strings_eng);
        }
        printf("Enter option: ");
        scanf("%d", &scelta);
        switch(scelta) {
                
            case 0:
                printf("Goodbye!\n");
                return 0;
                
            case 1:
				/*
             	 * Se il numero è minore di 10 uso la ricorsione
             	 * altrimenti uso il metodo iterrativo per mantenere l'efficienza
             	 */
                printf("You have selected factorial calculating.. \n");
				printf("Insert a number: ");
				unsigned long int *n1 = (unsigned long int*)malloc(sizeof(unsigned long int)*1);
				unsigned long int *n2 = (unsigned long int*)malloc(sizeof(unsigned long int)*1);
				scanf("%lu", n1);
            		if (*n1 <= 10) {
            		    *n2 = rec_fact(*n1);
            		}
            		else {
            		    *n2 = iter_fact(*n1);
            		}
				printf("Factorial of %lu is: %lu\n",*n1, *n2);
				free(n1);
				free(n2);
				sleep(1);
				break;				
				
                
            case 2:
                printf("You have selected Strings prefix\n");
                char *s1 = NULL;
                char *s2 = NULL;
                int dim = 30;
                int *pdim = &dim;
                printf("Inserisci una stringa: ");
                getline(&s1, &pdim, stdin);
                printf("Inserisci un'altra stringa: ");
                getline(&s2, &pdim, stdin);
                if (prefisso(s1, s2)) {
                    printf("The strings are prefix\n");
                }
                else {
                    printf("The strings aren't prefix\n");
                }
				free(s1);
				free(s2);
				sleep(1);
                break;
                
            case 3:
				printf("You have selected M.C.D.\n");
				printf("Inserisci il primo numero: ");
				int *primo_numero_mcd = (int*)malloc(sizeof(int));
				scanf("%d", primo_numero_mcd);
				printf("Inserisci il secondo numero: ");
				int *secondo_numero_mcd = (int*)malloc(sizeof(int));
				scanf("%d", secondo_numero_mcd);
				printf("Il mcd è: %d\n", mcd(*primo_numero_mcd, *secondo_numero_mcd));
				free(primo_numero_mcd);
				free(secondo_numero_mcd);
				sleep(1);
				break;

			case 4:
				printf("Under construction..");
				/*printf("You have selected togli spazi.\n");
				char *string1 = NULL;
				dim = 30;
				pdim = &dim;
				printf("Insert a string: ");
				getline(&s1, &pdim, stdin);
				togli_spazi(s1);
				int i=0;
				printf("Your string without spaces is: ");
				while(s1[i] != '\0') {
					printf("%c", s1[i]);
					i++;
				}
				printf("\n");*/
				sleep(1);
				break;
			case 5:
				printf("You have selected substring finder\n");
				char *big_string = NULL;
				char *sub_string = NULL;
				int dim_es_five = 50;
				int *p_dim_es_five = &dim_es_five;
				printf("Write a string that you want find a substring: ");
				getline(&big_string, &p_dim_es_five, stdin);
				printf("Write now a substring to find: ");
				getline(&sub_string, &p_dim_es_five, stdin);
				printf("%d",trova(big_string, sub_string));
				sleep(1);
				break;
            default:
                printf("Invalid option, please retry! \n");
				sleep(1);
		}
    }
}
