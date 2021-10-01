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

struct Vector *
vec_new()
{
	struct Vector *v = malloc(sizeof(*v));
	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->array = malloc(INITIAL_CAPACITY * sizeof(*v->array));
	return v;
}

struct Vector *
vec_new_with_capacity(size_t capacity)
{
	struct Vector *v = malloc(sizeof(*v));
	v->size = 0;
	v->capacity = capacity;
	v->array = malloc(capacity * sizeof(*v->array));
	return v;
}

void
vec_free(struct Vector *v)
{
	free(v->array);
	free(v);
}

size_t
vec_size(struct Vector *v)
{
	return v->size;
}

size_t
vec_capacity(struct Vector *v)
{
	return v->capacity;
}

void
vec_push(struct Vector *v, VecValue val)
{
	if (v->size == v->capacity) {
		v->capacity *= GROWTH_FACTOR;
		v->array = realloc(v->array, v->capacity * sizeof(*v->array));
	}
	v->array[v->size++] = val;
}

VecValue
vec_pop(struct Vector *v)
{
	return v->array[--v->size];
}

void
vec_clear(struct Vector *v)
{
	v->capacity = INITIAL_CAPACITY;
	v->size = 0;
	v->array = realloc(v->array, INITIAL_CAPACITY * sizeof(*v->array));
}

VecValue
vec_at_idx(struct Vector *v, size_t idx)
{
	return v->array[idx];
}

VecIt
vec_begin(struct Vector *v)
{
	return v->array;
}

VecIt
vec_rbegin(struct Vector *v)
{
	return v->array + v->size - 1;
}

VecIt
vec_end(struct Vector *v)
{
	return v->array + v->size;
}

VecIt
vec_rend(struct Vector *v)
{
	return v->array - 1;
}

VecIt
vec_next(VecIt it)
{
	return it + 1;
}

VecIt
vec_rnext(VecIt it)
{
	return it - 1;
}

VecValue
vec_at(VecIt it)
{
	return *it;
}
