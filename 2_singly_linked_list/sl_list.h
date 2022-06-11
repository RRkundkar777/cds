/* ADT of singly linked list data structure */

#ifndef SL_LIST_H
#define SL_LIST_H

// Global configurations
#include "../aes-config.h"

// System Libraries
#include <iostream>
#include <climits>

// Class declarations
class sl_list_node
{
public:
	lint value;
	sl_list_node *next;

public:
	sl_list_node(lint val);
};

// List class
class sl_list
{
	sl_list_node *head;
public:
	sl_list();
	~sl_list();
	void prepend(lint new_val);
	void traverse(bool reverse = false);
	void append(lint new_val);
	void insert_after(lint ref_val, lint new_val);
	lint length(bool iter = true);
	bool search(lint key,bool iter = true);
	lint find_at_index(lint index);
	lint find_from_last(lint index);
	void reverse();
	void rotate_left(lint pos);
	void delete_by_key(lint key);
	void delete_by_index(lint posit);

private:
	bool search_iterative(lint key);
	bool search_recursive(lint key,sl_list_node *head);
	lint find_length_iterative();
	lint find_length_recursive(sl_list_node *head);
	void simple_traverse();
	void rev_traverse(sl_list_node *head, bool newline = true);
};

#endif