#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <stddef.h>

/*
 * Doubly Linked List module.
 *
 * To change the type of
 * items the list takes,
 * change the DListValue typedef.
 *
 * Brief usage:
 * To construct a DList item do
 *
 * ~~~~~~~~~~~~~~
 * DList l;
 * l = dl_new();
 * ~~~~~~~~~~~~~~
 *
 * And to free it do
 *
 * ~~~~~~~~~~~~~~
 * dl_free(l);
 * ~~~~~~~~~~~~~~
 *
 * This module comes with
 * iterators that are used
 * like so:
 *
 * ~~~~~~~~~~~~~~
 * DListIt it;
 * for (it = dl_begin(l); it != dl_end(l); it = dl_next(it)) {
 * 	do_something_with(dl_at(it));
 * }
 * ~~~~~~~~~~~~~~
 *
 * or,equivalently,
 *
 * ~~~~~~~~~~~~~~
 * DListIt it;
 * for_each_in_dl(it, l) {
 * 	do_something_with(dl_at(it));
 * }
 * ~~~~~~~~~~~~~~
 *
 * The same goes about the reverse iterators.
 *
 * ~~~~~~~~~~~~~~
 * DListIt it;
 * for (it = dl_rbegin(l); it != dl_rend(l); it = dl_rnext(it)) {
 * 	do_something_with(dl_at(it));
 * }
 *
 * for_each_in_dl_rev(it, l) {
 * 	do_something_with(dl_at(it));
 * }
 * ~~~~~~~~~~~~~~
 *
 * Discover all the other functions
 * below and enjoy :D
 */

typedef int DListValue;

typedef struct DoublyLinkedList *DList;
typedef struct DoublyLinkedListIt *DListIt;

#define for_each_in_dl(i, l)                                                   \
	for ((i) = dl_begin(l); (i) != dl_end(l); (i) = dl_next(i))

#define for_each_in_dl_rev(i, l)                                               \
	for ((i) = dl_rbegin(l); (i) != dl_rend(l); (i) = dl_rnext(i))

/*
 * ~~~~~~~~~~~~~~
 * Constructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Constructs a Doubly Linked List.
 * The returned valued must
 * be freed with dl_free when
 * no longed needed.
 */
DList
dl_new(void);

/*
 * ~~~~~~~~~~~~~~
 * Destructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Frees a DList value.
 */
void
dl_free(DList l);

/*
 * ~~~~~~~~~~~~~~
 * Accessors
 * ~~~~~~~~~~~~~~
 */

/*
 * Returns the number
 * of items inserted
 * so far.
 * NOTE: Complexity
 * is O(1).
 */
size_t
dl_size(DList l);

/*
 * Returns the item at
 * position idx (starting
 * from 0).
 * WARNING: If the list has
 * less than idx + 1 items,
 * calling this function causes
 * undefined behaviour.
 * NOTE: The complexity of this
 * function is O(n).
 */
DListValue
dl_at_idx(DList l, size_t idx);

/*
 * ~~~~~~~~~~~~~~
 * Modifiers
 * ~~~~~~~~~~~~~~
 */

/*
 * Pushes an item at
 * the end of the list,
 * increasing its size by 1.
 */
void
dl_push_back(DList l, DListValue val);

/*
 * Pushes an item at
 * the beginning of the list,
 * increasing its size by 1.
 */
void
dl_push_front(DList l, DListValue val);

/*
 * Pops and returns the last
 * value in the list.
 * WARNING: If the list is
 * empty, calling this function
 * causes undefined behaviour.
 */
DListValue
dl_pop_back(DList l);

/*
 * Pops and returns the first
 * value in the list.
 * WARNING: If the list is
 * empty, calling this function
 * causes undefined behaviour.
 */
DListValue
dl_pop_front(DList l);

/*
 * Clears the list,
 * returning it to
 * 0 size.
 */
void
dl_clear(DList l);

/*
 * ~~~~~~~~~~~~~~
 * Iterator
 * ~~~~~~~~~~~~~~
 */

/*
 * Returns an iterator
 * pointing to the beginning
 * of the list.
 */
DListIt
dl_begin(DList l);

/*
 * Returns an iterator
 * that points to the
 * past-the-end item
 * in the list.
 */
DListIt
dl_end(DList v);

/*
 * Returns an iterator
 * to the next item
 * from the one the
 * given iterator points to.
 */
DListIt
dl_next(DListIt it);

/*
 * Returns an iterator
 * pointing to the reverse
 * beginning of the list.
 */
DListIt
dl_rbegin(DList l);

/*
 * Returns an iterator
 * that points to the
 * before-the-start item
 * in the list.
 */
DListIt
dl_rend(DList v);

/*
 * Returns an iterator
 * to the previous item
 * from the one the
 * given iterator points to.
 */
DListIt
dl_rnext(DListIt it);

#endif /* DOUBLY_LINKED_LIST_H */
