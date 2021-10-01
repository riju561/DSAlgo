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
 * NOTE: The heap keeps items
 * ordered, so it needs to know
 * how to order them. If the items
 * are basic like int or char, then
 * pass NULL to the mah_new function.
 * If the values are a custom struct,
 * then you will need to provide a
 * pointer to a function of type
 * int custom_compare(MaxHeapValue l, MaxHeapValue r)
 * where the return values must be:
 * if l == r -> 0
 * if l <  r -> < 0
 * if l >  r -> > 0
 * So if, for example, you want to keep a max heap
 * of strings, you can set the MaxHeapValue typedef
 * to const char *, and pass the strcmp function to
 * mah_new like so: MaxHeap h = mah_new(strcmp).
 *
 * Brief usage:
 * To construct a MaxHeap item do
 *
 * ~~~~~~~~~~~~~~
 * MaxHeap h;
 * h = mah_new(NULL);
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

typedef int (*MaxHeapCmpFn)(MaxHeapValue a, MaxHeapValue b);

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
 *
 * Read the description note if
 * you don't know what to pass as
 * argument.
 */
MaxHeap
mah_new(MaxHeapCmpFn cmp);

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
