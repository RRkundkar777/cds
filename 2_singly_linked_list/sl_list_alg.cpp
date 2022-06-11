/* List algorithms */

#ifndef SL_LIST_ALG_H
#define SL_LIST_ALG_H

// List ADT
#include "sl_list.h"

// Reverse a linked list
void sl_list::reverse()
{
	sl_list_node *current = this->head;
	sl_list_node *prev = NULL, *next = NULL;

	while(current != NULL)
	{
		// Initialize next pointer
		next = current->next;
		
		// Change linking
		current->next = prev;
		
		// Move pointers current and prev
		prev = current;
		current = next;
	}
	// Change head to last element of linked list
	this->head = prev;
}

// Traverse a linked list reverse
void sl_list::rev_traverse(sl_list_node *head, bool newline)
{
	if(head == NULL)
	{
		cout << "NULL" << "<-";
		return;
	}

	rev_traverse(head->next,false);
	
	if(newline)
	{
		cout <<  head->value  << endl;
	}
	else
	{
		cout << head->value << "<-";
	}
}

// Rotate a list to right by pos nodes
void sl_list::rotate_left(lint pos)
{
	if(pos == 0)
		return;

	sl_list_node *traveller = this->head;
	lint count = 1;

	// Find kth node
	while(count < pos && traveller != NULL)
	{
		traveller = traveller->next;
		count++;
	}

	// If k > length 
	if(traveller == NULL)
		return;

	// kth node
	sl_list_node *pos_node = traveller;

	// Find last node
	while(traveller->next)
		traveller = traveller->next;

	// Rotating by changing links
	traveller->next = this->head;
	this->head = pos_node->next;
	pos_node->next = NULL;

	return;
}


#endif