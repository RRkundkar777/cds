/* ADT of max heap data structure */

#ifndef A_MAX_HEAP_H
#define A_MAX_HEAP_H

// Global configurations
#include "../aes-config.h"

// System Libraries
#include <iostream>
#include <climits>
#include <cmath>

// Class declaration
class a_max_heap
{
public:
	lint *hparr;
	lint capacity;
	lint heap_size;
public:
	a_max_heap(lint capacity);
	lint parent(lint index);
	lint leftchild(lint index);
	lint rightchild(lint index);
	lint get_max();
	void insert(lint item);
	void display();
	void increase_key(lint index, lint value);
	void heapify(int index);
	lint extract_max();
	void delete_key(lint value);
};

#endif