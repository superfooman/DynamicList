#include <stdio.h>
#include <stdlib.h>

#include "DynamicList.h"

int main(void)
{
	list ls;
	list another_ls;
	list last_ls;
	
	list_init(&ls);
	list_init(&another_ls);
	list_init(&last_ls);

	list_add(&ls, "Hello");
	list_add(&ls, "World");

	printf("Word count: %d\n", list_count(&ls));

	for (int i = 0; i < list_count(&ls); i++)
	{
		printf("%s ", (char*)list_find(&ls, i));
	}
	printf("\nMakes two copies, one shadow copy, and another one deep copy\n");

	list_copy(&ls, &another_ls);
	list_deep_copy(&ls, &last_ls);

	for (int i = 0; i < list_count(&another_ls); i++)
	{
		printf("%s ", (char*)list_find(&another_ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&last_ls); i++)
	{
		printf("%s ", (char*)list_find(&last_ls, i));
	}
	printf("\nReplace a new word for the shadow copy list\n");

	list_replace(&another_ls, 0, "Hi");

	for (int i = 0; i < list_count(&ls); i++)
	{
		printf("%s ", (char*)list_find(&ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&another_ls); i++)
	{
		printf("%s ", (char*)list_find(&another_ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&last_ls); i++)
	{
		printf("%s ", (char*)list_find(&last_ls, i));
	}
	printf("\nReplace another new word for the deep copy list\n");

	list_replace(&last_ls, 0, "Hello!!");

	for (int i = 0; i < list_count(&ls); i++)
	{
		printf("%s ", (char*)list_find(&ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&another_ls); i++)
	{
		printf("%s ", (char*)list_find(&another_ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&last_ls); i++)
	{
		printf("%s ", (char*)list_find(&last_ls, i));
	}
	printf("\n");

	list_free(&ls);
	// list_free(&another_ls);   // another_ls is a shadow copy of ls, point to the same address location as ls
	list_free(&last_ls);

	getchar();
}