/* Code to test the list data structure */

// List data structure
#include "sl_list.h"

int main()
{
    sl_list ls;
    ls.traverse();
    ls.append(4);
    ls.prepend(9);
    ls.prepend(1001);
    ls.traverse();
    ls.append(999);
    ls.traverse();
    ls.insert_after(9,10);
    ls.traverse();
    ls.insert_after(102,10);
    ls.traverse();
    ls.insert_after(1001,1002);
    ls.traverse();
    cout << "Number of non-zero elements are: " << ls.length() << endl;
    cout << "Number of non-zero elements are: " << ls.length(false) << endl;
    cout << ls.search(1000,false) << endl;
    cout << ls.find_at_index(0) << endl;
    cout << ls.find_from_last(6) << endl;

    cout << endl;
    ls.traverse();
    ls.reverse();
    ls.traverse();
    ls.rotate_left(1);
    ls.traverse();
    ls.delete_by_key(1002);
    ls.traverse();
    ls.delete_by_index(3);
    ls.traverse();
    return 0;
}