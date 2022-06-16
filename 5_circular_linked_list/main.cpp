/* Code to test the list data structure */

// List data structure
#include "cl_list.h"

int main()
{
    cl_list cls;
    cls.traverse();
    cls.append(4);
    cls.append(5);
    cls.append(6);
    cls.append(7);
    cls.append(8);
    cout << cls.traverse() << endl;
    cls.prepend(9);
    cls.prepend(1001);
    cls.traverse();
    cls.insert_after(9,11);
    cls.traverse();
    cls.insert_after(778,23);
    cls.insert_after(9,10);
    cls.traverse();
    cout << cls.search(10) << endl;
    cout << cls.find_at_index(3) << endl;
    cout << cls.find_from_last(8) << endl;
    cout << endl << endl;
    cls.traverse();
    cls.reverse();
    cls.traverse();
    cls.reverse();

    cls.rotate_left(10);
    cls.traverse();
    cls.rotate_left(8);
    cls.traverse();
    cls.delete_by_key(1001);
    cls.traverse();
    cls.delete_by_key(11);
    cls.traverse();
    cls.delete_by_key(8);
    cls.traverse();

    // cls.insert_after(102,10);
    // cls.traverse();
    // cls.insert_after(1001,1002);
    // cls.traverse();
    // cout << "Number of non-zero elements are: " << cls.length() << endl;
    // cout << "Number of non-zero elements are: " << cls.length(faclse) << endl;
    // cout << cls.search(1000,faclse) << endl;
    // cout << cls.find_at_index(0) << endl;
    // cout << cls.find_from_last(6) << endl;

    // cout << endl;
    // cls.traverse();
    // cls.reverse();
    // cls.traverse();
    // cls.rotate_left(1);
    // cls.traverse();
    // cls.delete_by_key(1002);
    // cls.traverse();
    // cls.delete_by_index(3);
    // cls.traverse();

    cout << "Success\n";
    return 0;
}