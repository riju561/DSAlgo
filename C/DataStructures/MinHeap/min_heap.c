#include <malloc.h>
#include "min_heap.h"

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 2

struct MinHeap {
	MinHeapValue *array;
	size_t size;
	size_t capacity;

	MinHeapCmpFn cmp;
};

#define parent(i) ((i) / 2)
#define left(i) (2 * (i))
#define right(i) (2 * (i) + 1)

#define lt(h, i, j) \
	((h)->cmp == NULL     \
	? (h)->array[i] < (h)->array[j] \
	: (h)->cmp((h)->array[i], (h)->array[j]) < 0)

static void
heapify(struct MinHeap *h, size_t i);

struct MinHeap *
mih_new(MinHeapCmpFn cmp)
{
	struct MinHeap *h = malloc(sizeof(*h));
	h->size = 0;
	h->capacity = INITIAL_CAPACITY;
	h->array = malloc(INITIAL_CAPACITY * sizeof(*h->array));
	h->cmp = cmp;
	return h;
}

void
mih_free(struct MinHeap *h)
{
	free(h->array);
	free(h);
}

size_t
mih_size(struct MinHeap *h)
{
	return h->size;
}

MinHeapValue
mih_top(struct MinHeap *h)
{
	return h->array[0];
}

void
mih_push(struct MinHeap *h, MinHeapValue val)
{
	size_t curr;
	MinHeapValue tmp;

	if (h->size == h->capacity) {
		h->capacity *= GROWTH_FACTOR;
		h->array = realloc(h->array, h->capacity * sizeof(*h->array));
	}

	h->array[h->size++] = val;
	curr = h->size - 1;
	while (lt(h, curr, parent(curr))) {
		tmp = h->array[curr];
		h->array[curr] = h->array[parent(curr)];
		h->array[parent(curr)] = tmp;

		curr = parent(curr);
	}
}

MinHeapValue
mih_pop(struct MinHeap *h)
{
	MinHeapValue min;
	min = h->array[0];
	h->array[0] = h->array[h->size - 1];
	h->size--;
	heapify(h, 1);
	return min;
}

void
mih_clear(struct MinHeap *h)
{
	h->size = 0;
	h->capacity = INITIAL_CAPACITY;
	h->array = realloc(h->array, INITIAL_CAPACITY);
}

static void
heapify(struct MinHeap *h, size_t i)
{
	size_t l, r, min;
	MinHeapValue val;

	l = left(i);
	r = right(i);

	if (l < h->size && lt(h, l, i))
		min = l;
	else
		min = i;

	if (r < h->size && lt(h, r, i))
		min = r;

	if (min != i) {
		val = h->array[i];
		h->array[i] = h->array[min];
		h->array[min] = val;
		heapify(h, min);
	}
}
