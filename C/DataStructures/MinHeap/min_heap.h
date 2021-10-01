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
 * Brief usage:
 * To construct a MinHeap item do
 *
 * ~~~~~~~~~~~~~~
 * MinHeap h;
 * h = mih_new();
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
 */
MinHeap
mih_new(void);

/*
 * ~~~~~~~~~~~~~~
 * Destructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Frees a MinHeap value.
 */
void
mih_free(MinHeap);

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
mih_size(MinHeap);

/*
 * Access the top element
 * in the heap.
 * WARNING: If the heap is
 * empty, calling this function
 * causes undefined behaviour.
 */
MinHeapValue
mih_top(MinHeap);

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
mih_push(MinHeap, MinHeapValue);

/*
 * Pops and returns the top
 * value in the heap.
 * WARNING: If the heap is
 * empty, calling this function
 * causes undefined behaviour.
 */
MinHeapValue
mih_pop(MinHeap);

/*
 * Clears the heap,
 * returning its size
 * to 0.
 */
void
mih_clear(MinHeap);

#endif /* MIN_HEAP_H */
