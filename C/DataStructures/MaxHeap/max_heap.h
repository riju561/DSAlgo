#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <stddef.h>

/*
 * Max Heap module.
 *
 * To change the type of
 * items the heap takes,
 * change the MaxHeapValue typedef.
 *
 * Brief usage:
 * To construct a MaxHeap item do
 *
 * ~~~~~~~~~~~~~~
 * MaxHeap h;
 * h = mah_new();
 * ~~~~~~~~~~~~~~
 *
 * And to free it do
 *
 * ~~~~~~~~~~~~~~
 * mah_free(h);
 * ~~~~~~~~~~~~~~
 *
 * Discover all the other functions
 * below and enjoy :D
 */

typedef int MaxHeapValue;

typedef struct MaxHeap *MaxHeap;

/*
 * ~~~~~~~~~~~~~~
 * Constructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Construct a MaxHeap.
 * The returned valued must
 * be freed with mih_free when
 * no longed needed.
 */
MaxHeap
mah_new(void);

/*
 * ~~~~~~~~~~~~~~
 * Destructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Frees a MaxHeap value.
 */
void
mah_free(MaxHeap h);

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
mah_size(MaxHeap h);

/*
 * Access the top element
 * in the heap.
 * WARNING: If the heap is
 * empty, calling this function
 * causes undefined behaviour.
 */
MaxHeapValue
mah_top(MaxHeap h);

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
mah_push(MaxHeap h, MaxHeapValue val);

/*
 * Pops and returns the top
 * value in the heap.
 * WARNING: If the heap is
 * empty, calling this function
 * causes undefined behaviour.
 */
MaxHeapValue
mah_pop(MaxHeap h);

/*
 * Clears the heap,
 * returning its size
 * to 0.
 */
void
mah_clear(MaxHeap h);

#endif /* MIN_HEAP_H */
