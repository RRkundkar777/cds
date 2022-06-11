/* ADT of stack data structure */

#ifndef L_STACK_H
#define L_STACK_H

// Global configurations
#include "../aes-config.h"

// System Libraries
#include <iostream>
#include <climits>

// Class declaration
class l_stack_node
{
public:
	lint item;
	l_stack_node *next;

public:
	l_stack_node(lint data);
};

// Stack class
class l_stack
{
	l_stack_node *top;

public:
	l_stack();
	void push(lint item);
	bool is_empty();
	lint pop();
	lint peek();
	lint size();
	~l_stack();
};

#endif