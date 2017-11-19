#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_list.h"


int main(int argc, char const *argv[])
{
	string_list sl = NULL;

	char *s = "ciao\0"; 
	append(&sl, s);
	char *str = "cacca\0";
	append(&sl, str);
	frequent_character(sl);
	return 0;
}