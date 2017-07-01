#include<stdio.h>
#include<stdlib.h>

#include "DynamicList.h"

void list_init(list* ls)
{
	ls->count = 0;
	ls->capacity = LIST_INIT_CAPACITY;
	ls->items = malloc(sizeof(void*) * ls->capacity);

}

int list_count(list* ls)
{
	return ls->count;
}

int list_capacity(list* ls)
{
	return ls->capacity;
}

static void list_resize(list* ls, int new_capacity)
{
	void** item = realloc(ls->items, sizeof(void *) * new_capacity);
	if (item) {
		ls->items = item;
		ls->capacity = new_capacity;
	}
}

void list_add(list* ls, void* item)
{
	if (ls->count == ls->capacity)
		list_resize(ls, ls->capacity * 2);
	ls->items[ls->count++] = item;

}

void list_copy(list* ls, list* another_ls)
{
	another_ls->items = ls->items;
	another_ls->count = ls->count;
	another_ls->capacity = ls->capacity;
}

void list_deep_copy(list* ls, list* another_ls)
{
	for (int i = 0; i < ls->count; i++)
	{
		list_add(another_ls, ls->items[i]);
	}
	another_ls->count = ls->count;
	another_ls->capacity = ls->capacity;
}

void* list_find(list* ls, int index)
{
	if (index >= 0 && index < ls->count)
		return ls->items[index];
	return NULL;
}

void list_replace(list* ls, int index, void* item)
{
	if (index >= 0 && index < ls->count)
		ls->items[index] = item;

}

void list_free(list* ls)
{
	free(ls->items);
}



