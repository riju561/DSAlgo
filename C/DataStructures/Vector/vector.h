#ifndef VECTOR_H
#define VECTOR_H

/*
 * Vector module.
 *
 * To change the type of
 * items the vector takes,
 * change the VecValue typedef.
 *
 * Brief usage:
 * To construct a Vec item do
 *
 * ~~~~~~~~~~~~~~
 * Vec v;
 * v = vec_new();
 * ~~~~~~~~~~~~~~
 *
 * And to free it do
 *
 * ~~~~~~~~~~~~~~
 * vec_free(v);
 * ~~~~~~~~~~~~~~
 *
 * This module comes with
 * iterators that are used
 * like so:
 *
 * ~~~~~~~~~~~~~~
 * VecIt it;
 * for (it = vec_begin(v); it != vec_end(v); it = vec_next(it) {
 * 	do_something_with(vec_at(it));
 * }
 * ~~~~~~~~~~~~~~
 *
 * or,equivalently,
 *
 * ~~~~~~~~~~~~~~
 * VecIt it;
 * for_each_in_vec(it, v) {
 * 	do_something_with(vec_at(it));
 * }
 * ~~~~~~~~~~~~~~
 *
 * The same goes about the reverse iterators.
 *
 * ~~~~~~~~~~~~~~
 * VecIt it;
 * for (it = vec_rbegin(v); it != vec_rend(v); it = vec_rnext(it) {
 * 	do_something_with(vec_at(it));
 * }
 *
 * for_each_in_vec_rev(it, v) {
 * 	do_something_with(vec_at(it));
 * }
 * ~~~~~~~~~~~~~~
 *
 * Discover all the other functions
 * below and enjoy :D
 */

typedef int VecValue;

typedef struct Vector *Vec;
typedef VecValue *VecIt;

#define for_each_in_vec(i, v)                                                  \
	for ((i) = vec_begin(v); (i) != vec_end(v); (i) = vec_next(i))

#define for_each_in_vec_rev(i, v)                                              \
	for ((i) = vec_rbegin(v); (i) != vec_rend(v); (i) = vec_rnext(i))

/*
 * ~~~~~~~~~~~~~~
 * Constructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Construct a Vec.
 * The returned valued must
 * be freed with vec_free when
 * no longed needed.
 */
Vec
vec_new(void);

/*
 * Construct a Vec with
 * the given capacity.
 * The returned valued must
 * be freed with vec_free when
 * no longed needed.
 */
Vec
vec_new_with_capacity(size_t capacity);

/*
 * ~~~~~~~~~~~~~~
 * Destructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Frees a Vec value.
 */
void
vec_free(Vec v);

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
vec_size(Vec v);

/*
 * Returns the current
 * capacity of the vector.
 * The capacity changes
 * dynamically as items are
 * added.
 */
size_t
vec_capacity(Vec v);

/*
 * Returns the item at
 * position idx (starting
 * from 0).
 * WARNING: if the vector has
 * less than idx + 1 items,
 * calling this function causes
 * undefined behaviour.
 */
VecValue
vec_at_idx(Vec v, size_t idx);

/*
 * ~~~~~~~~~~~~~~
 * Modifiers
 * ~~~~~~~~~~~~~~
 */

/*
 * Pushes an item at
 * the end of the vector,
 * increasing its size by 1.
 */
void
vec_push(Vec v, VecValue val);

/*
 * Pops and returns the last
 * value in the vector.
 * WARNING: if the vector is
 * empty, calling this function
 * causes undefined behaviour.
 */
VecValue
vec_pop(Vec v);

/*
 * Clears the vector,
 * returning it to the
 * default capacity and
 * to 0 size.
 */
void
vec_clear(Vec v);

/*
 * ~~~~~~~~~~~~~~
 * Iterator
 * ~~~~~~~~~~~~~~
 */

/*
 * Returns an iterator
 * pointing to the beginning
 * of the vector.
 */
VecIt
vec_begin(Vec v);

/*
 * Returns an iterator
 * that points to the
 * past-the-end item
 * in the vector.
 */
VecIt
vec_end(Vec v);

/*
 * Returns an iterator
 * to the next item
 * from the one the
 * given iterator points to.
 */
VecIt
vec_next(VecIt it);

/*
 * Returns an iterator
 * pointing to the
 * reverse beginning
 * of the vector.
 */
VecIt
vec_rbegin(Vec v);

/*
 * Returns an iterator
 * that points to the
 * before-the-start item
 * in the vector.
 */
VecIt
vec_rend(Vec v);

/*
 * Returns an iterator
 * to the previous item
 * from the one the
 * given iterator points to.
 */
VecIt
vec_rnext(VecIt it);

/*
 * Returns the item
 * pointed to by the
 * iterator.
 */
VecValue
vec_at(VecIt it);

#endif /* VECTOR_H */
