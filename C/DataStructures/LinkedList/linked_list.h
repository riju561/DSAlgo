#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
/*
 * Linked List module.
 *
 * To change the type of
 * items the list takes,
 * change the ListValue typedef.
 *
 * Brief usage:
 * To construct a LinkedList item do
 *
 * ~~~~~~~~~~~~~~
 * List l;
 * l = ll_new();
 * ~~~~~~~~~~~~~~
 *
 * And to free it do
 *
 * ~~~~~~~~~~~~~~
 * ll_free(l);
 * ~~~~~~~~~~~~~~
 *
 * This module comes with
 * iterators that are used
 * like so:
 *
 * ~~~~~~~~~~~~~~
 * ListIt it;
 * for (it = ll_begin(l); it != ll_end(l); it = ll_next(it)) {
 * 	do_something_with(ll_at(it));
 * }
 * ~~~~~~~~~~~~~~
 *
 * or,equivalently,
 *
 * ~~~~~~~~~~~~~~
 * ListIt it;
 * for_each_in_ll(it, l) {
 * 	do_something_with(ll_at(it));
 * }
 * ~~~~~~~~~~~~~~
 *
 * The same goes about the reverse iterators.
 *
 * ~~~~~~~~~~~~~~
 * ListIt it;
 * for (it = ll_rbegin(l); it != ll_rend(l); it = ll_rnext(it)) {
 * 	do_something_with(ll_at(it));
 * }
 *
 * for_each_in_ll_rev(it, l) {
 * 	do_something_with(ll_at(it));
 * }
 * ~~~~~~~~~~~~~~
 *
 * Discover all the other functions
 * below and enjoy :D
 */

typedef int ListValue;

typedef struct LinkedList *List;
typedef struct LinkedListIt *ListIt;

#define for_each_in_ll(i, l)                                                   \
	for ((i) = ll_begin(l); (i) != ll_end(l); (i) = ll_next(i))

#define for_each_in_ll_rev(i, l)                                               \
	for ((i) = ll_rbegin(l); (i) != ll_rend(l); (i) = ll_rnext(i))

/*
 * ~~~~~~~~~~~~~~
 * Constructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Constructs a Linked List.
 * The returned valued must
 * be freed with ll_free when
 * no longed needed.
 */
List
ll_new(void);

/*
 * ~~~~~~~~~~~~~~
 * Destructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Frees a List value.
 */
void
ll_free(List l);

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
ll_size(List l);

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
ListValue
ll_at_idx(List l, size_t idx);

/*
 * ~~~~~~~~~~~~~~
 * Modifiers
 * ~~~~~~~~~~~~~~
 */

/*
 * Pushes an item at
 * the beginning of the list,
 * increasing its size by 1.
 */
void
ll_push_front(List l, ListValue val);

/*
 * Pops and returns the first
 * value in the list.
 * WARNING: If the list is
 * empty, calling this function
 * causes undefined behaviour.
 */
ListValue
ll_pop_front(List l);

/*
 * Clears the list,
 * returning it to
 * 0 size.
 */
void
ll_clear(List l);

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
ListIt
ll_begin(List l);

/*
 * Returns an iterator
 * that points to the
 * past-the-end item
 * in the list.
 */
ListIt
ll_end(List v);

/*
 * Returns an iterator
 * to the next item
 * from the one the
 * given iterator points to.
 */
ListIt
ll_next(ListIt it);

/*
 * Returns the item
 * pointed to by the
 * iterator.
 */
ListValue
ll_at(ListIt it);

#endif /* LINKED_LIST_H */
