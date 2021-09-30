#include <stddef.h>
#include <malloc.h>
#include "vector.h"

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 2

struct Vector {
	size_t size;
	size_t capacity;
	VecValue *array;
};

Vec
vec_new()
{
	struct Vector *v = malloc(sizeof(*v));
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->array = malloc(INITIAL_CAPACITY * sizeof(*v->array));
	return v;
}

void
vec_free(Vec v)
{
	free(v->array);
	free(v);
}

size_t
vec_size(Vec v)
{
	return v->size;
}

size_t
vec_capacity(Vec v)
{
	return v->capacity;
}

void
vec_push(Vec v, VecValue val)
{
	if (v->size == v->capacity) {
		v->capacity *= GROWTH_FACTOR;
		v->array = realloc(v->array, v->capacity * sizeof(*v->array));
	}
	v->array[v->size++] = val;
}

VecValue
vec_pop(Vec v)
{
	return v->array[--v->size];
}

VecValue
vec_at_idx(Vec v, size_t idx)
{
	return v->array[idx];
}

VecIt
vec_begin(Vec v)
{
	return v->array;
}

VecIt
vec_end(Vec v)
{
	return v->array + v->size;
}

VecIt
vec_next(VecIt it)
{
	return it + 1;
}

VecValue
vec_at(VecIt it)
{
	return *it;
}
