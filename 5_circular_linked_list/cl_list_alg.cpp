/* List algorithms */

#ifndef CL_LIST_ALG_H
#define CL_LIST_ALG_H

// List ADT
#include "cl_list.h"

// Find the nth element from the last
lint cl_list::find_from_last(lint index)
{
	cl_list_node *main = this->tail->next;
	cl_list_node *ref = this->tail->next;

	if(this->tail == NULL)
		return LLONG_MIN;

	for (int i = 0; i < index; ++i)
	{
		if(ref == NULL)
			return LLONG_MIN;
		ref = ref->next;
	}

	while(ref != tail->next)
	{
		ref = ref->next;
		main = main->next;
	}

	return main->value;
}

// Reverse a list
void cl_list::reverse()
{
	if(this->tail == NULL)
		return;

	cl_list_node *prev = NULL, *curr = this->tail->next, *next = NULL;

	do
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}while(curr != NULL);

	this->tail = prev;
}

// Rotate a list to left by offset
void cl_list::rotate_left(lint offset)
{
	if(this->tail)
	{
		while(offset)
		{
			this->tail = this->tail->next;
			offset--;
		}
		return;
	}
	return;
}

#endif