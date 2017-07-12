#include <stdio.h>
#include <stdlib.h>

#include "DynamicList.h"

int main(void)
{
	list ls;
	list second_ls;
	list last_ls;
	
	list_init(&ls);
	list_init(&second_ls);
	list_init(&last_ls);

	list_add(&ls, "long");
	list_add(&ls, "time");
	list_add(&ls, "no");
	list_add(&ls, "see");

	printf("Testing (1) list_init (2) list_add (3) list_count functions:\n");
	printf("Word count: %d\n", list_count(&ls));

	for (int i = 0; i < list_count(&ls); i++)
	{
		printf("%s ", (char*)list_find(&ls, i));
	}
	printf("\n\nTesting (4) list_find (5) list_copy (6) list_deep_copy functions:\n");
	printf("Makes two copies, one shadow copy, and another one deep copy\n");

	list_copy(&ls, &second_ls);
	list_deep_copy(&ls, &last_ls);

	for (int i = 0; i < list_count(&second_ls); i++)
	{
		printf("%s ", (char*)list_find(&second_ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&last_ls); i++)
	{
		printf("%s ", (char*)list_find(&last_ls, i));
	}
	printf("\nTesting (7) list_replace function:\n");
	printf("Replace a new word for the shadow copy list\n");

	list_replace(&second_ls, 0, "No");

	for (int i = 0; i < list_count(&ls); i++)
	{
		printf("%s ", (char*)list_find(&ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&second_ls); i++)
	{
		printf("%s ", (char*)list_find(&second_ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&last_ls); i++)
	{
		printf("%s ", (char*)list_find(&last_ls, i));
	}
	printf("\nReplace another new word for the deep copy list\n");

	list_replace(&last_ls, 0, "looong");

	for (int i = 0; i < list_count(&ls); i++)
	{
		printf("%s ", (char*)list_find(&ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&second_ls); i++)
	{
		printf("%s ", (char*)list_find(&second_ls, i));
	}
	printf("\n");

	for (int i = 0; i < list_count(&last_ls); i++)
	{
		printf("%s ", (char*)list_find(&last_ls, i));
	}
	printf("\nTesting (8) list_insert function:\n");
	printf("Insert a new word for the deep copy list\n");

	list_insert(&last_ls, 0, "very");

	for (int i = 0; i < list_count(&last_ls); i++)
	{
		printf("%s ", (char*)list_find(&last_ls, i));
	}
	printf("\nTesting (9) list_remove function:\n");

	list_remove(&last_ls, 0);

	for (int i = 0; i < list_count(&last_ls); i++)
	{
		printf("%s ", (char*)list_find(&last_ls, i));
	}
	printf("\nTesting (10) list_clear function:\n");	

	list_clear(&ls);
	list_add(&ls, "Hello");
	list_add(&ls, "World");

	for (int i = 0; i < list_count(&ls); i++)
	{
		printf("%s ", (char*)list_find(&ls, i));
	}
	printf("\n");

	list_free(&ls);
	// list_free(&second_ls);   // another_ls is a shadow copy of ls, point to the same address location as ls
	list_free(&last_ls);

	getchar();
}