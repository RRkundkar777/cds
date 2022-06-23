/* Code to test the min heap data structure */

// Min Heap data structure
#include "a_min_heap.h"

int main()
{
    std::cout << "Success\n";
    a_min_heap h1(9);
    h1.insert(1);
    h1.insert(2);
    h1.insert(3);
    h1.insert(4);
    h1.insert(5);
    h1.insert(5);
    h1.insert(5);
    h1.insert(0);
    h1.display();
    h1.decrease_key(7, -3);
    cout << endl;
    h1.display();
    cout << endl;
    h1.extract_min();
    h1.display();
    cout << endl;
    h1.delete_key(5);
    h1.display();





}