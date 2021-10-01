#include <malloc.h>
#include "queue.h"

struct Node {
	QueueValue item;
	struct Node *next;
	struct Node *prev;
};

struct Queue {
	size_t size;
	struct Node *fst;
	struct Node *lst;
};

Queue
qu_new(void)
{
	struct Queue *q = malloc(sizeof(*q));
	q->size = 0;
	q->fst = q->lst = NULL;
	return q;
}

void
qu_free(Queue q)
{
	struct Node *tmp = q->fst;
	while (q->fst != q->lst) {
		q->fst = q->fst->next;
		free(tmp);
		tmp = q->fst;
	}
	free(q->fst);
	free(q);
}

size_t
qu_size(Queue q)
{
	return q->size;
}

QueueValue
qu_top(Queue q)
{
	return q->lst->item;
}

void
qu_push(Queue q, QueueValue val)
{
	struct Node *node = malloc(sizeof(*node));
	node->item = val;
	node->prev = NULL;

	if (q->size == 0) {
		node->next = NULL;
		q->fst = q->lst = node;

		q->size++;
		return;
	}

	node->next = q->fst;
	q->fst->prev = node;
	q->fst = node;

	q->size++;
}

QueueValue
qu_pop(Queue q)
{
	QueueValue v = q->lst->item;
	q->lst = q->lst->prev;
	q->size--;
	return v;
}

void
qu_clear(Queue q)
{
	struct Node *tmp = q->fst;
	while (q->fst != q->lst) {
		q->fst = q->fst->next;
		free(tmp);
		tmp = q->fst;
	}
	free(q->fst);
	q->fst = q->lst = NULL;
	q->size = 0;
}
