#include <malloc.h>
#include "stack.h"

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 2

struct Stack {
	StackValue *array;
	size_t size;
	size_t capacity;
};

struct Stack *
stk_new(void)
{
	struct Stack *s = malloc(sizeof(*s));
	s->size = 0;
	s->capacity = INITIAL_CAPACITY;
	s->array = malloc(INITIAL_CAPACITY * sizeof(*s->array));
	return s;
}

struct Stack *
stk_new_with_capacity(size_t capacity)
{
	struct Stack *s = malloc(sizeof(*s));
	s->size = 0;
	s->capacity = capacity;
	s->array = malloc(capacity * sizeof(*s->array));
	return s;
}

void
stk_free(struct Stack *s)
{
	free(s->array);
	free(s);
}

size_t
stk_size(struct Stack *s)
{
	return s->size;
}

StackValue
stk_top(struct Stack *s)
{
	return s->array[s->size - 1];
}

void
stk_push(struct Stack *s, StackValue val)
{
	if (s->size == s->capacity) {
		s->capacity *= GROWTH_FACTOR;
		s->array = realloc(s->array, s->capacity * sizeof(*s->array));
	}
	s->array[s->size++] = val;
}

StackValue
stk_pop(struct Stack *s)
{
	return s->array[--s->size];
}

void
stk_clear(struct Stack *s)
{
	s->capacity = INITIAL_CAPACITY;
	s->size = 0;
	s->array = realloc(s->array, INITIAL_CAPACITY * sizeof(*s->array));
}
