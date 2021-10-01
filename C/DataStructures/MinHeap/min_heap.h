#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <stddef.h>

/*
 * Min Heap module.
 *
 * To change the type of
 * items the heap takes,
 * change the MinHeapValue typedef.
 *
 * NOTE: The heap keeps items
 * ordered, so it needs to know
 * how to order them. If the items
 * are basic like int or char, then
 * pass NULL to the mih_new function.
 * If the values are a custom struct,
 * then you will need to provide a
 * pointer to a function of type
 * int custom_compare(MinHeapValue l, MinHeapValue r)
 * where the return values must be:
 * if l == r -> 0
 * if l <  r -> < 0
 * if l >  r -> > 0
 * So if, for example, you want to keep a min heap
 * of strings, you can set the MinHeapValue typedef
 * to const char *, and pass the strcmp function to
 * mih_new like so: MinHeap h = mih_new(strcmp).
 *
 * Brief usage:
 * To construct a MinHeap item do
 *
 * ~~~~~~~~~~~~~~
 * MinHeap h;
 * h = mih_new(NULL);
 * ~~~~~~~~~~~~~~
 *
 * And to free it do
 *
 * ~~~~~~~~~~~~~~
 * mih_free(h);
 * ~~~~~~~~~~~~~~
 *
 * Discover all the other functions
 * below and enjoy :D
 */

typedef int MinHeapValue;

typedef int (*MinHeapCmpFn)(MinHeapValue a, MinHeapValue b);

typedef struct MinHeap *MinHeap;

/*
 * ~~~~~~~~~~~~~~
 * Constructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Construct a MinHeap.
 * The returned valued must
 * be freed with mih_free when
 * no longed needed.
 *
 * Read the description note if
 * you don't know what to pass as
 * argument.
 */
MinHeap
mih_new(MinHeapCmpFn cmp);

/*
 * ~~~~~~~~~~~~~~
 * Destructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Frees a MinHeap value.
 */
void
mih_free(MinHeap h);

/*
 * ~~~~~~~~~~~~~~
 * Accessors
 * ~~~~~~~~~~~~~~
 */

/*
 * Returns the number
 * of items inserted
 * so far.
 */
size_t
mih_size(MinHeap h);

/*
 * Access the top element
 * in the heap.
 * WARNING: If the heap is
 * empty, calling this function
 * causes undefined behaviour.
 */
MinHeapValue
mih_top(MinHeap h);

/*
 * ~~~~~~~~~~~~~~
 * Modifiers
 * ~~~~~~~~~~~~~~
 */

/*
 * Pushes an item in
 * the heap, increasing
 * its size by 1.
 */
void
mih_push(MinHeap h, MinHeapValue val);

/*
 * Pops and returns the top
 * value in the heap.
 * WARNING: If the heap is
 * empty, calling this function
 * causes undefined behaviour.
 */
MinHeapValue
mih_pop(MinHeap h);

/*
 * Clears the heap,
 * returning its size
 * to 0.
 */
void
mih_clear(MinHeap h);

#endif /* MIN_HEAP_H */
