/* Code to test the max heap data structure */

// Max Heap data structure
#include "a_max_heap.h"

int main()
{
    std::cout << "Success\n";
    a_max_heap h3(8);
    h3.insert(1);
    h3.insert(2);
    h3.insert(3);
    h3.insert(4);
    h3.insert(5);
    h3.insert(6);
    h3.insert(7);
    h3.insert(0);
    h3.insert(119);
    h3.display();
    cout << endl;
    h3.increase_key(5, 9);
    h3.display();
    cout << endl;
    h3.extract_max();
    h3.display();
    cout << endl;
    h3.delete_key(2);
    h3.display();
    cout << endl;
    cout << h3.get_max() << endl;
}