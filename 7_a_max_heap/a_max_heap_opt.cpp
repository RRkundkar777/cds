/* Operations on max heap */

#ifndef A_MAX_HEAP_OPT_H
#define A_MAX_HEAP_OPT_H

// Max Heap ADT
#include "a_max_heap.h"

// Constructor
a_max_heap::a_max_heap(lint capacity)
{
	lint *new_arr = new lint[capacity];
	this->capacity = capacity;
	this->hparr = new_arr;
	this->heap_size = 0;
}

// Parent
lint a_max_heap::parent(lint index)
{
	return (index - 1)/2;
}

// Children
lint a_max_heap::leftchild(lint index)
{
	return 2*index + 1;
}

lint a_max_heap::rightchild(lint index)
{
	return 2*index + 2;
}

// Returns max element
lint a_max_heap::get_max()
{
	if(this->heap_size != 0)
		return hparr[0];
	return LLONG_MAX;
}

// Inserting an element in heap
void a_max_heap::insert(lint item)
{
	// Heap is full
	if(heap_size == capacity)
		return;

	// Insertion at the end
	this->heap_size++;
	lint i = this->heap_size - 1;
	this->hparr[i] = item;

	// Fixing max heap property
	while(i != 0 && (hparr[i] > hparr[parent(i)]))
	{
		swap(hparr[i],hparr[parent(i)]);
		i = parent(i);
	}

	return;
}

// Displaying the heap
void a_max_heap::display()
{
	int cnt0 = 1;
	int i = 0;
	while(i < heap_size)
	{
		cout << " " << hparr[i] << " ";
		if(i + 2 == pow(2,cnt0))
		{
			cout << endl;
			cnt0++;
		}
		i++;
	}
	cout << endl;
}

// Increasing an existing key
void a_max_heap::increase_key(lint index, lint value)
{
	if(index >= heap_size)
		return;

	this->hparr[index] = value;
	while(index != 0 && (hparr[index] > hparr[parent(index)]))
	{
		swap(hparr[index],hparr[parent(index)]);
		index = parent(index);
	}
	return;
}

// Heapify a subtree with a given root
void a_max_heap::heapify(int index)
{
	int l = leftchild(index);
	int r = rightchild(index);
	int greatest = index;

	if(l < heap_size && hparr[l] > hparr[index])
		greatest = l;
	if(r < heap_size && hparr[r] > hparr[greatest])
		greatest = r;

	if(greatest != index)
	{
		swap(hparr[greatest],hparr[index]);
		heapify(greatest);
	}
}

// Extracting maximum element
lint a_max_heap::extract_max()
{
	if(heap_size <= 0)
		return LLONG_MIN;
	if(heap_size == 1)
	{
		heap_size--;
		return hparr[heap_size];
	}

	lint res = hparr[0];
	hparr[0] = hparr[heap_size - 1];
	heap_size--;
	this->heapify(0);

	return res;
}

// Deleting a key
void a_max_heap::delete_key(lint value)
{
	increase_key(value,LLONG_MAX);
	extract_max();
}

#endif