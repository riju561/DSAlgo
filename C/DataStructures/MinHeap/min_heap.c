#include <malloc.h>
#include "min_heap.h"

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 2

struct MinHeap {
	MinHeapValue *array;
	size_t size;
	size_t capacity;
};

#define parent(i) ((i) / 2)
#define left(i) (2 * (i))
#define right(i) (2 * (i) + 1)

static void
heapify(struct MinHeap *h, size_t i);

struct MinHeap *
mih_new(void)
{
	struct MinHeap *h = malloc(sizeof(*h));
	h->size = 0;
	h->capacity = INITIAL_CAPACITY;
	h->array = malloc(INITIAL_CAPACITY * sizeof(*h->array));
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
	while (h->array[curr] < h->array[parent(curr)]) {
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

	if (l < h->size && h->array[l] < h->array[i])
		min = l;
	else
		min = i;

	if (r < h->size && h->array[r] < h->array[i])
		min = r;

	if (min != i) {
		val = h->array[i];
		h->array[i] = h->array[min];
		h->array[min] = val;
		heapify(h, min);
	}
}
