#ifndef STACK_H
#define STACK_H
#include <stddef.h>

/*
 * Stack module.
 *
 * To change the type of
 * items the stack takes,
 * change the StackValue typedef.
 *
 * Brief usage:
 * To construct a Stack item do
 *
 * ~~~~~~~~~~~~~~
 * Stack s;
 * s = stk_new();
 * ~~~~~~~~~~~~~~
 *
 * And to free it do
 *
 * ~~~~~~~~~~~~~~
 * stk_free(v);
 * ~~~~~~~~~~~~~~
 *
 * To push and top pop
 * items do:
 *
 * ~~~~~~~~~~~~~~
 * stk_push(s, 1);
 * StackValue i = stk_pop(s);
 * ~~~~~~~~~~~~~~
 *
 * Discover all the other functions
 * below and enjoy :D
 */

typedef int StackValue;

typedef struct Stack *Stk;

/*
 * ~~~~~~~~~~~~~~
 * Constructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Construct a Stack.
 * The returned valued must
 * be freed with stk_free when
 * no longed needed.
 */
Stk
stk_new(void);

/*
 * Construct a Stack with
 * the given capacity.
 * The returned valued must
 * be freed with stk_free when
 * no longed needed.
 */
Stk
stk_new_with_capacity(size_t capacity);

/*
 * ~~~~~~~~~~~~~~
 * Destructors
 * ~~~~~~~~~~~~~~
 */

/*
 * Frees a Stack value.
 */
void
stk_free(Stk s);

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
stk_size(Stk s);

/*
 * Returns the top
 * item in the stack.
 * WARNING: If the stack
 * is empty, this function
 * causes undefined behaviour.
 */
StackValue
stk_top(Stk s);

/*
 * ~~~~~~~~~~~~~~
 * Modifiers
 * ~~~~~~~~~~~~~~
 */

/*
 * Pushes an item at
 * the top of the stack,
 * increasing its size by 1.
 */
void
stk_push(Stk s, StackValue val);

/*
 * Pops and returns the last
 * value in the stack.
 * WARNING: If the stack is
 * empty, calling this function
 * causes undefined behaviour.
 */
StackValue
stk_pop(Stk s);

/*
 * Clears the stack,
 * returning it to the
 * default capacity and
 * to 0 size.
 */
void
stk_clear(Stk s);

#endif /* STACK_H */
