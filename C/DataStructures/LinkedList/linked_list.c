#include <malloc.h>
#include "linked_list.h"

typedef struct LinkedListIt Node;
struct LinkedListIt {
	ListValue item;
	Node *next;
};

struct LinkedList {
	size_t size;
	Node *head;
};

List
ll_new(void)
{
	struct LinkedList *l = malloc(sizeof(*l));
	l->size = 0;
	l->head = NULL;
	return l;
}

void
ll_free(List l)
{
	Node *tmp = l->head;
	while (l->head) {
		l->head = l->head->next;
		free(tmp);
		tmp = l->head;
	}
	free(l);
}

size_t
ll_size(List l)
{
	return l->size;
}

ListValue
ll_at_idx(List l, size_t idx)
{
	size_t i;
	Node *n = l->head;

	for (i = 0; i < idx; i++)
		n = n->next;

	return n->item;
}

void
ll_push_front(List l, ListValue val)
{
	Node *node = malloc(sizeof(*node));
	node->item = val;

	if (l->size == 0) {
		node->next = NULL;
		l->head = node;

		l->size++;
		return;
	}

	node->next = l->head;
	l->head = node;

	l->size++;
}

ListValue
ll_pop_front(List l)
{
	ListValue v = l->head->item;
	l->head = l->head->next;
	l->size--;
	return v;
}

void
ll_clear(List l)
{
	Node *tmp = l->head;
	while (l->head) {
		l->head = l->head->next;
		free(tmp);
		tmp = l->head;
	}
	l->size = 0;
}

ListIt
ll_begin(List l)
{
	return l->head;
}

ListIt
ll_end(List __attribute__((unused))v)
{
	return NULL;
}

ListIt
ll_next(ListIt it)
{
	return it->next;
}


ListValue
ll_at(ListIt it)
{
	return it->item;
}
