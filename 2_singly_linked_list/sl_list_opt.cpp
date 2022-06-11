/* Operations on singly linked list */

#ifndef SL_LIST_OPT_H
#define SL_LIST_OPT_H

// List ADT
#include "sl_list.h"

// Initialize a list node
sl_list_node::sl_list_node(lint val)
{
	this->value = val;
	this->next = NULL;
}

// Initialize a list
sl_list::sl_list()
{
	this->head = NULL;
}

// Prepend an element to a list
void sl_list::prepend(lint new_val)
{
	sl_list_node *newnode = new sl_list_node(new_val);
	newnode->next = this->head;
	this->head = newnode;
}

// Append a node to list
void sl_list::append(lint new_val)
{
	sl_list_node *newnode = new sl_list_node(new_val);
	sl_list_node * traveller = this->head;

	if(this->head == NULL)
	{
		this->head = newnode;
		return;
	}

	while(traveller->next)
	{
		traveller = traveller->next;
	}

	traveller->next = newnode;
	return;
}

// Insert after a specific node in a list
void sl_list::insert_after(lint ref_val, lint new_val)
{
	if(this->head == NULL)
	{
		return;
	}

	sl_list_node *backward = this->head, *forward = NULL;
	while(backward->next && backward->value != ref_val)
	{
		backward = backward->next;
		forward =  backward->next;
	}

	if(backward->value == ref_val)
	{
		sl_list_node *newnode = new sl_list_node(new_val);
		if(backward == this->head)
		{
			forward = backward->next;
		}
		backward->next = newnode;
		newnode->next = forward;
		return;
	}
	return;
}

// Traverse the list forward or backward
void sl_list::traverse(bool reverse)
{
	if(!reverse)
		simple_traverse();
	else
		rev_traverse(this->head);
}

// Simply Traverse the linked list
void sl_list::simple_traverse()
{
	sl_list_node *traveller = this->head;
	while(traveller)
	{
		cout << traveller->value << "->";
		traveller = traveller->next;
	}
	cout << "NULL" << endl;
}

// Number of non NULL elements in list
lint sl_list::length(bool iter)
{
	if(iter)
		return find_length_iterative();
	else
		return find_length_recursive(this->head);
}

// Iteratively find length of list
lint sl_list::find_length_iterative()
{
	sl_list_node *traveller = this->head;
	lint size = 0;
	while(traveller)
	{
		size++;
		traveller = traveller->next;
	}
	return size;	
}

// Recursively find length of list
lint sl_list::find_length_recursive(sl_list_node *head)
{
	if(head == NULL)
		return 0;
	else
		return 1 + find_length_recursive(head->next);
}

// Search an element in linked list
bool sl_list::search(lint key,bool iter)
{
	if(iter)
		return search_iterative(key);
	else
		return search_recursive(key,this->head);
}

// Iteratively search an element in list
bool sl_list::search_iterative(lint key)
{
	sl_list_node *traveller = this->head;

	while(traveller)
	{
		if(traveller->value == key)
			return true;
		traveller = traveller->next;
	}
	return false;
}

// Recursively search an element in list
bool sl_list::search_recursive(lint key,sl_list_node *head)
{
	if(head == NULL)
		return false;
	if(head->value == key)
		return true;
	return search_recursive(key,head->next);
}

// Return an element at an index in a list
lint sl_list::find_at_index(lint index)
{
	lint count = 0;
	sl_list_node *traveller = this->head;
	while(traveller)
	{
		if(count == index)
			return traveller->value;
		count++;
		traveller = traveller->next;
	}
	return INT_MIN;
}

lint sl_list::find_from_last(lint index)
{
	sl_list_node *main = this->head;
	sl_list_node *ref = this->head;

	if(this->head == NULL)
		return INT_MIN;

	for (int i = 0; i < index; ++i)
	{
		if(ref == NULL)
			return INT_MIN;
		ref = ref->next;
	}

	while(ref != NULL && ref->next != NULL)
	{
		ref = ref->next;
		main = main->next;
	}

	return main->value;
}

// Delete a list node by key
void sl_list::delete_by_key(lint key)
{
	sl_list_node *temp = this->head;
	sl_list_node *prev = NULL;

	// Head is the node 
	if(temp != NULL && temp->value == key)
	{
		this->head = temp->next;
		delete temp;
		return;
	}

	while(temp != NULL && temp->value != key)
	{
		prev = temp;
		temp = temp->next;
	}

	// Key not found
	if(temp == NULL)
		return;

	// Unlink and free the node
	prev->next = temp->next;
	delete temp;

	return;
}

// Delete list node by position
void sl_list::delete_by_index(lint posit)
{
	if(this->head == NULL)
		return;

	sl_list_node *temp = this->head;

	// Index of head node
	if(posit == 0)
	{
		this->head = temp->next;
		delete temp;
		return;
	}

	// find posit - 1 node
	for (int i = 0; i < posit - 1; i++)
	{
		temp = temp->next;
	}

	// posit + 1 node
	sl_list_node *next = temp->next->next;
	// delete posit node
	delete temp->next;
	// link posit - 1 and posit + 1 nodes
	temp->next = next;
	
	return;
}

// Destruction of complete linked list
sl_list::~sl_list()
{
	sl_list_node *temp;
	while(this->head)
	{
		temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
	
	if(!this->head)
		cout << "Was I a good list ryusaki?\n";
}

#endif