#include <malloc.h>
#include "max_heap.h"

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 2

struct MaxHeap {
	MaxHeapValue *array;
	size_t size;
	size_t capacity;

	MaxHeapCmpFn cmp;
};

#define parent(i) ((i) / 2)
#define left(i) (2 * (i))
#define right(i) (2 * (i) + 1)

#define gt(h, i, j) \
	((h)->cmp == NULL     \
	? (h)->array[i] > (h)->array[j] \
	: (h)->cmp((h)->array[i], (h)->array[j]) > 0)

static void
heapify(struct MaxHeap *h, size_t i);

struct MaxHeap *
mah_new(MaxHeapCmpFn cmp)
{
	struct MaxHeap *h = malloc(sizeof(*h));
	h->size = 0;
	h->capacity = INITIAL_CAPACITY;
	h->array = malloc(INITIAL_CAPACITY * sizeof(*h->array));
	h->cmp = cmp;
	return h;
}

void
mah_free(struct MaxHeap *h)
{
	free(h->array);
	free(h);
}

size_t
mah_size(struct MaxHeap *h)
{
	return h->size;
}

MaxHeapValue
mah_top(struct MaxHeap *h)
{
	return h->array[0];
}

void
mah_push(struct MaxHeap *h, MaxHeapValue val)
{
	size_t curr;
	MaxHeapValue tmp;

	if (h->size == h->capacity) {
		h->capacity *= GROWTH_FACTOR;
		h->array = realloc(h->array, h->capacity * sizeof(*h->array));
	}

	h->array[h->size++] = val;
	curr = h->size - 1;
	while (gt(h, curr, parent(curr))) {
		tmp = h->array[curr];
		h->array[curr] = h->array[parent(curr)];
		h->array[parent(curr)] = tmp;

		curr = parent(curr);
	}
}

MaxHeapValue
mah_pop(struct MaxHeap *h)
{
	MaxHeapValue max;
	max = h->array[0];
	h->array[0] = h->array[h->size - 1];
	h->size--;
	heapify(h, 1);
	return max;
}

void
mah_clear(struct MaxHeap *h)
{
	h->size = 0;
	h->capacity = INITIAL_CAPACITY;
	h->array = realloc(h->array, INITIAL_CAPACITY);
}

static void
heapify(struct MaxHeap *h, size_t i)
{
	size_t l, r, max;
	MaxHeapValue val;

	l = left(i);
	r = right(i);

	if (l < h->size && gt(h, l, i))
		max = l;
	else
		max = i;

	if (r < h->size && gt(h, r, i))
		max = r;

	if (max != i) {
		val = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = val;
		heapify(h, max);
	}
}
