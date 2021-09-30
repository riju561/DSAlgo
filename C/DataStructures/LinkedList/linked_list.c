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
	Node *n1, *n2;
	n1 = l->head;
	while (n1 != NULL) {
		n2 = n1->next;
		free(n1);
		n1 = n2;
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

	l->size++;

	if (l->size == 0) {
		node->next = NULL;
		l->head = node;
		return;
	}

	node->next = l->head;
	l->head = node;
}

ListValue
ll_pop_front(List l)
{
	ListValue v = l->head->item;
	l->head = l->head->next;
	return v;
}

void
ll_clear(List l)
{
	Node *n1, *n2;
	n1 = l->head;
	while (n1 != NULL) {
		n2 = n1->next;
		free(n1);
		n1 = n2;
	}
	l->head = NULL;
	l->size = 0;
}

ListIt
ll_begin(List l)
{
	return l->head;
}

ListIt
ll_end(List v)
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
