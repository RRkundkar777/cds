/* Operations on min heap */

#ifndef A_MIN_HEAP_OPT_H
#define A_MIN_HEAP_OPT_H

// Min Heap ADT
#include "a_min_heap.h"

// Constructor
a_min_heap::a_min_heap(lint capacity)
{
	lint *new_arr = new lint[capacity];
	this->capacity = capacity;
	this->hparr = new_arr;
	this->heap_size = 0;
}

// Parent
lint a_min_heap::parent(lint index)
{
	return (index - 1)/2;
}

// Children
lint a_min_heap::leftchild(lint index)
{
	return 2*index + 1;
}

lint a_min_heap::rightchild(lint index)
{
	return 2*index + 2;
}

// Returns min element
lint a_min_heap::get_min()
{
	if(this->heap_size != 0)
		return hparr[0];
	return LLONG_MIN;
}

// Inserting an element in heap
void a_min_heap::insert(lint item)
{
	// Heap is full
	if(heap_size == capacity)
		return;

	// Insertion at the end
	this->heap_size++;
	lint i = this->heap_size - 1;
	this->hparr[i] = item;

	// Fixing min heap property
	while(i != 0 && (hparr[i] < hparr[parent(i)]))
	{
		swap(hparr[i],hparr[parent(i)]);
		i = parent(i);
	}

	return;
}

// Displaying the heap
void a_min_heap::display()
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

// Decreasing an existing key
void a_min_heap::decrease_key(lint index, lint value)
{
	if(index >= heap_size)
		return;

	this->hparr[index] = value;
	while(index != 0 && (hparr[index] < hparr[parent(index)]))
	{
		swap(hparr[index],hparr[parent(index)]);
		index = parent(index);
	}
	return;
}

// Heapify a subtree with a given root
void a_min_heap::heapify(int index)
{
	int l = leftchild(index);
	int r = rightchild(index);
	int smallest = index;

	if(l < heap_size && hparr[l] < hparr[index])
		smallest = l;
	if(r < heap_size && hparr[r] < hparr[smallest])
		smallest = r;

	if(smallest != index)
	{
		swap(hparr[smallest],hparr[index]);
		heapify(smallest);
	}
}

// Extracting minimum element
lint a_min_heap::extract_min()
{
	if(heap_size <= 0)
		return LLONG_MAX;
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
void a_min_heap::delete_key(lint value)
{
	decrease_key(value,LLONG_MIN);
	extract_min();
}

#endif