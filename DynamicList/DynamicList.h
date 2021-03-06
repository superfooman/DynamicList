#ifndef LIST_H
#define LIST_H

#define LIST_INIT_CAPACITY 4

typedef struct list list;
struct list
{
	void** items; // point to list of items
	int capacity;
	int count;
};

typedef enum bool bool;
typedef enum bool
{
	false = 0,
	true

};

void list_init(list*);
int list_count(list*);
int list_capacity(list*);
static void list_resize(list*, int);
void list_add(list*, void*);
void list_copy(list*, list*);
void list_deep_copy(list*, list*);
void list_insert(list*, int, void*);
void* list_find(list*, int);
void list_replace(list*, int, void*);
void list_remove(list*, int);
void list_free(list*);
void list_clear(list*);

#endif
