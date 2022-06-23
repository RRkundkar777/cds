/* ADT of min heap data structure */

#ifndef A_MIN_HEAP_H
#define A_MIN_HEAP_H

// Global configurations
#include "../aes-config.h"

// System Libraries
#include <iostream>
#include <climits>
#include <cmath>

// Class declaration
class a_min_heap
{
public:
	lint *hparr;
	lint capacity;
	lint heap_size;
public:
	a_min_heap(lint capacity);
	lint parent(lint index);
	lint leftchild(lint index);
	lint rightchild(lint index);
	lint get_min();
	void insert(lint item);
	void display();
	void decrease_key(lint index, lint value);
	void heapify(int index);
	lint extract_min();
	void delete_key(lint value);
};

#endif