#ifndef QUEUE_H
#define QUEUE_H
#include <stddef.h>

/*
 * Queue module.
 *
 * To change the type of
 * items the queue takes,
 * change the QueueValue typedef.
 *
 * Brief usage:
 * To construct a Queue item do
 *
 * ~~~~~~~~~~~~~~
 * Queue q;
 * q = qu_new();
 * ~~~~~~~~~~~~~~
 *
 * And to free it do
 *
 * ~~~~~~~~~~~~~~
 * qu_free(q);
 * ~~~~~~~~~~~~~~
 *
 * Discover all the other functions
 * below and enjoy :D
 */

typedef int QueueValue;

typedef struct Queue *Queue;

/*
 * ~~~~~~~~~~~~~~
 * Constructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Constructs a Queue.
 * The returned valued must
 * be freed with qu_free when
 * no longed needed.
 */
Queue
qu_new(void);

/*
 * ~~~~~~~~~~~~~~
 * Destructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Frees a Queue value.
 */
void
qu_free(Queue q);

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
qu_size(Queue q);

/*
 * Returns the next
 * item in the queue.
 * WARNING: If the queue
 * is empty, this function
 * causes undefined behaviour.
 */
QueueValue
qu_top(Queue q);

/*
 * ~~~~~~~~~~~~~~
 * Modifiers
 * ~~~~~~~~~~~~~~
 */

/*
 * Pushes an item in
 * the queue, increasing
 * its size by 1.
 */
void
qu_push(Queue q, QueueValue val);

/*
 * Pops and returns the value
 * that was first inserted
 * in the queue.
 * WARNING: If the queue is
 * empty, calling this function
 * causes undefined behaviour.
 */
QueueValue
qu_pop(Queue q);

/*
 * Clears the queue,
 * returning it to
 * 0 size.
 */
void
qu_clear(Queue q);

#endif /* QUEUE_H */
