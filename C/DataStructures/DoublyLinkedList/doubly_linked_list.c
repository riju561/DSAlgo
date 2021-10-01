#include <malloc.h>
#include "doubly_linked_list.h"

typedef struct DoublyLinkedListIt Node;
struct DoublyLinkedListIt {
	DListValue item;
	Node *next;
	Node *prev;
};

struct DoublyLinkedList {
	size_t size;
	Node *fst;
	Node *lst;
};

DList
dl_new(void)
{
	struct DoublyLinkedList *l = malloc(sizeof(*l));
	l->size = 0;
	l->fst = l->lst = NULL;
	return l;
}

void
dl_free(DList l)
{
	Node *tmp = l->fst;
	while (l->fst != l->lst) {
		l->fst = l->fst->next;
		free(tmp);
		tmp = l->fst;
	}
	free(l->fst);
	free(l);
}

size_t
dl_size(DList l)
{
	return l->size;
}

DListValue
dl_at_idx(DList l, size_t idx)
{
	size_t i;
	Node *n = l->fst;

	for (i = 0; i < idx; i++)
		n = n->next;

	return n->item;
}

void
dl_push_back(DList l, DListValue val)
{
	Node *node = malloc(sizeof(*node));
	node->item = val;
	node->next = NULL;

	l->size++;

	if (l->size == 0) {
		node->prev = NULL;
		l->fst = l->lst = node;
		return;
	}

	node->prev = l->lst;
	l->lst = node;
}

void
dl_push_front(DList l, DListValue val)
{
	Node *node = malloc(sizeof(*node));
	node->item = val;
	node->prev = NULL;

	l->size++;

	if (l->size == 0) {
		node->next = NULL;
		l->fst = l->lst = node;
		return;
	}

	node->next = l->fst;
	l->fst = node;
}

DListValue
dl_pop_back(DList l)
{
	DListValue v = l->lst->item;
	l->lst = l->lst->prev;
	l->size--;
	return v;
}

DListValue
dl_pop_front(DList l)
{
	DListValue v = l->fst->item;
	l->fst = l->fst->next;
	l->size--;
	return v;
}

void
dl_clear(DList l)
{
	Node *tmp = l->fst;
	while (l->fst != l->lst) {
		l->fst = l->fst->next;
		free(tmp);
		tmp = l->fst;
	}
	free(l->fst);
	l->fst = l->lst = NULL;
	l->size = 0;
}

DListIt
dl_begin(DList l)
{
	return l->fst;
}

DListIt
dl_end(DList __attribute__((unused))v)
{
	return NULL;
}

DListIt
dl_next(DListIt it)
{
	return it->next;
}

DListIt
dl_rbegin(DList l)
{
	return l->lst;
}

DListIt
dl_rend(DList __attribute__((unused))v)
{
	return NULL;
}

DListIt
dl_rnext(DListIt it)
{
	return it->prev;
}
