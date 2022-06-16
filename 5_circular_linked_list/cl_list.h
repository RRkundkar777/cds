/* ADT of circular linked list data structure */

#ifndef CL_LIST_H
#define CL_LIST_H

// Global configurations
#include "../aes-config.h"

// System Libraries
#include <iostream>
#include <climits>

// Class declarations
class cl_list_node
{
public:
	lint value;
	cl_list_node *next;

public:
	cl_list_node(lint val);
};

/*
12. ~cl_list
*/

// List class
class cl_list
{
	cl_list_node *tail;
public:
	cl_list();
	void append(lint val);
	void prepend(lint val);
	lint traverse();
	void insert_after(lint ref,lint val);
	lint search(lint item);
	lint find_at_index(lint index);
	lint find_from_last(lint index);
	void reverse();
	void rotate_left(lint num);
	void delete_by_key(int key);
	~cl_list();
};

#endif