/* Operations on stack */

#ifndef A_STACK_OPT_H
#define A_STACK_OPT_H

// Stack ADT
#include "a_stack.h"

// Initialize an empty stack
a_stack::a_stack()
{
	this->top = -1;
}

// Push on stack
bool a_stack::push(lint item)
{
	if(this->top >= MAX_STACK_SIZE - 1)
	{
		return false;
	}
	else
	{
		st_array[++this->top] = item;
		return true;
	}
}

// Pop from stack
lint a_stack::pop()
{
	if(this->top < 0)
	{
		return LLONG_MIN;
	}
	lint res = this->st_array[this->top--];
	return res;
}

// View the top element of stack
lint a_stack::peek()
{
	if(top < 0)
	{
		return LLONG_MIN;
	}
	lint res = this->st_array[this->top];
	return res;
}

// Number of elements in stack
lint a_stack::size()
{
	return this->top + 1;
}

// Check if stack is empty
bool a_stack::is_empty()
{
	return (this->top < 0);
}

// Check if stack is full
bool a_stack::is_full()
{
	return (this->top == MAX_STACK_SIZE - 1);
}
#endif