/*
Title: HashTable ADT
Author: Rushikesh (@RRkundkar777)
Description: Hash Table using chaining for collision prevention. Hash function = value % BUCKETS
*/

// Include Standard Library
#include<list>

using namespace std;

// hashTable class
class hashTable
{
private:
        // No. of buckets
        int BUCKET;   
        
        // Pointer to array of list
        list<int> *table; 
        
        // The Hash function
        int hashFunction(int value); 

public:
    /* Constructors */
    hashTable(int buckets);
    ~hashTable();

    /* Basic Operations on hashTable */

    // Function to insert into hashTable
    void insert(int value);

    // Function to delete from hashTable
    void remove(int value);

    // Function to search from a hashTable
    int search(int value);

    // Function to display the hashTable
    void display();
};


