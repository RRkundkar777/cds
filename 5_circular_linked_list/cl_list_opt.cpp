/* Operations on circular linked list */

#ifndef CL_LIST_OPT_H
#define CL_LIST_OPT_H

// List ADT
#include "cl_list.h"

// Initialize a list node
cl_list_node::cl_list_node(lint val)
{
	this->value = val;
	this->next = this;
}

// Initialize a list
cl_list::cl_list()
{
	this->tail = NULL;
}

// Appending to a list
void cl_list::append(lint val)
{
	cl_list_node *newnode = new cl_list_node(val);
	
	// Empty list
	if(this->tail == NULL)
	{
		this->tail = newnode;
		return;
	}

	// Append to non empty list
	newnode->next = this->tail->next;
	this->tail->next = newnode;
	this->tail = newnode;
	return;
}

// Prepend to a list
void cl_list::prepend(lint val)
{
	cl_list_node *newnode = new cl_list_node(val);

	// Empty list
	if(this->tail == NULL)
	{
		this->tail = newnode;
		return;
	}

	// Linking
	newnode->next = this->tail->next;
	this->tail->next = newnode;
	return;
}

// Insert after a specific element in list
void cl_list::insert_after(lint ref,lint val)
{
	cl_list_node *newnode = new cl_list_node(val);

	// Empty list
	if(this->tail == NULL)
	{
		this->tail = newnode;
		return;
	}

	cl_list_node *traveller = this->tail->next;

	do
	{
		if(traveller->value == ref)
		{
			newnode->next = traveller->next;
			traveller->next = newnode;

			if(traveller == this->tail)
			{
				this->tail = newnode;
			}
			return;
		}

		traveller = traveller->next;
	
	}while(traveller != this->tail->next);

	return;
}

// Traverse a list
lint cl_list::traverse()
{
	// Empty list
	if(!this->tail)
		return 0;
	
	cl_list_node *traveller = this->tail->next;
	lint count = 0;

	do
	{
		cout << traveller->value << "->";
		traveller = traveller->next;
		count++;
	}while(traveller != this->tail->next);
	cout << "\b*" << endl;

	return count;
}

// Search for an item in list
lint cl_list::search(lint item)
{
	cl_list_node *traveller = this->tail->next;
	lint count = 0;

	if(this->tail != NULL)
	{
		do
		{
			if(traveller->value == item)
				return count;
			count++;
			traveller = traveller->next;
		}while(traveller != this->tail->next);
	}
	return -1;
}

// Find an element at a given index
lint cl_list::find_at_index(lint index)
{
	cl_list_node *traveller = this->tail->next;
	lint count = 0;
	if(this->tail != NULL)
	{
		do
		{
			if(count == index)
				return traveller->value;
			count++;
			traveller = traveller->next;
		}while(traveller != this->tail->next);
	}

	return LLONG_MIN;
}

// Delete a list node by 
void cl_list::delete_by_key(int key)
{
	// Empty list
	if(this->tail == NULL)
		return;

	// Singleton list
	if(this->tail->value == key && this->tail->next == this->tail)
	{
		delete this->tail;
		this->tail = NULL;
		return;
	}


	cl_list_node *last = this->tail;

	// Tail of list is to deleted
	if(this->tail->value == key)
	{
		while(last->next != this->tail)
			last = last->next;

		last->next = this->tail->next;

		delete this->tail;
		this->tail = last;
		return;
	}

	// Any other node
	while(last->next != this->tail && last->next->value != key)
	{
		last = last->next;
	}

	if(last->next->value == key)
	{
		cl_list_node *tmp = last->next;
		last->next = tmp->next;
		delete tmp;
		return;
	}
}

// Destruction of a entire list
cl_list::~cl_list()
{
	cl_list_node *destroyer = this->tail->next;
	cl_list_node *next;

	do
	{
		next = destroyer->next;
		delete destroyer;
		destroyer = next;
	}while(destroyer != this->tail);

	delete this->tail;
	this->tail = NULL;
	if(this->tail)
			cout << "I am not destroyed yet\n";
}

#endif