// Include standard libraries
#include <iostream>
#include<limits.h>

// Hash Table ADTs
#include "hashTable.h"

/* Constructors */
hashTable::hashTable(int buckets)
{
    this->BUCKET = buckets;
    this->table = new list<int>[this->BUCKET];
}

hashTable::~hashTable()
{
}

/* Basic Operations */

// Hashing mechanism
int hashTable::hashFunction(int value)
{
    return (value % BUCKET);
}

// Function to insert element into hashTable
void hashTable::insert(int value)
{
    int index = hashFunction(value);
    this->table[index].push_back(value);
}

// Function to remove an element from hashTable
void hashTable::remove(int value)
{
    // get the hash index of key
    int index = hashFunction(value);

    // find the key in (inex)th list
    list<int>::iterator iter;

    for (iter = table[index].begin(); iter != table[index].end(); iter++)
    {
        if (*iter == value)
        {
            break;
        }
    }

    // if key is found in hash table, remove it
    if (iter != table[index].end())
    {
        table[index].erase(iter);
    }
}

// Function to display hashTable
void hashTable::display()
{
    // Iterate through complete array
    for (int i = 0; i < this->BUCKET; i++)
    {
        // Traverse through the list
        list<int>::iterator iter;

        cout << i << ":";
        for (iter = table[i].begin(); iter != table[i].end(); iter++)
        {
            cout << "-->" << *iter;
        }
        cout << endl;
    }
}

// Function to search for an element in a hash table
int hashTable::search(int value)
{
    // Iterate through complete array
    for (int i = 0; i < this->BUCKET; i++)
    {
        // Traverse through the list
        list<int>::iterator iter;

        for (iter = table[i].begin(); iter != table[i].end(); iter++)
        {
            if(*iter == value)
            {
                return i;
            }
        }
    }
    return INT_MIN;
}