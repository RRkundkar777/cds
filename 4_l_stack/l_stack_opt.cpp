/* Operations on stack */

#ifndef L_STACK_OPT_H
#define L_STACK_OPT_H

// Stack ADT
#include "l_stack.h"

// Create a new stack node
l_stack_node::l_stack_node(lint data)
{
	this->item = data;
	this->next = NULL;
}

// Initialize a stack
l_stack::l_stack()
{
	this->top = NULL;
}

// Push into stack
void l_stack::push(lint item)
{
	l_stack_node *newnode = new l_stack_node(item);
	newnode->next = this->top;
	this->top = newnode;
}

// Check if stack is empty
bool l_stack::is_empty()
{
	return !(this->top);
}

// Pop from stack
lint l_stack::pop()
{
	if(this->is_empty())
		return LLONG_MIN;

	l_stack_node *temp = this->top;
	this->top = this->top->next;
	
	lint res = temp->item;
	
	delete temp;
	return res;	
}

// Top of stack
lint l_stack::peek()
{
	if(this->is_empty())
		return LLONG_MIN;
	return this->top->item;
}

// Size of stack
lint l_stack::size()
{
	l_stack_node *traveller = this->top;
	lint count = 0;
	while(traveller)
	{
		count++;
		traveller = traveller->next;
	}
	return count;
}

// Destruction of stack
l_stack::~l_stack()
{
	l_stack_node *temp;
	while(this->top)
	{
		temp = this->top;
		this->top = this->top->next;
		delete temp;
	}
	
	if(this->top)
		cout << "I am not destroyed yet\n";
}

#endif