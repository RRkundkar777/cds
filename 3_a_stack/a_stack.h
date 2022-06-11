/* ADT of stack data structure */

#ifndef A_STACK_H
#define A_STACK_H

// Global configurations
#include "../aes-config.h"

// System Libraries
#include <iostream>
#include <climits>

// Macros
#define MAX_STACK_SIZE 922337

// Class declaration
class a_stack
{
	lint top;
public:
	lint st_array[MAX_STACK_SIZE];

public:
	a_stack();
	bool push(lint item);
	lint pop();
	lint peek();
	lint size();
	bool is_empty();
	bool is_full();
};

#endif