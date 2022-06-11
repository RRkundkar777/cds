/* Testing all data structures concurrently */

// System Libraries
#include<iostream>

// Configuration
#include"aes-config.h"

// Data Structures
#include "1_array/array.h"
#include "2_singly_linked_list/sl_list.h"
#include "3_a_stack/a_stack.h"
#include "4_l_stack/l_stack.h"

int main(int argc, char const *argv[])
{
    vector<lint> v1{0,1,2,3,9,8,7,6};
    array a1;
    a1.display_array(v1);
    a1.merge_sort(v1,0,v1.size() - 1);
    a1.display_array(v1);




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




    a_stack s;    
    lint count = 0;
    while(true)
    {
        s.push(count);
        if(s.peek() != count)
        {
            cout << s.peek() << "  " << count << endl;
            break;
        }
        count++;
    }
    cout << "Size: " << s.size() << endl;
    cout << "Isfull: " << s.is_full() << endl;
    cout << "IsEmpty: " << s.is_empty() << endl;




    l_stack l;
    cout << "Size is: " << l.size() << endl;
    cout << "Empty?: " << l.is_empty() << endl;
    cout << "Popping: " << l.pop() << endl;
    cout << "Top of stack: " << l.peek() << endl;

    for (int i = 0; i < 35; i++)
    {
        l.push(2*i);
    }

    cout << endl;
    cout << "Size is: " << l.size() << endl;
    cout << "Empty?: " << l.is_empty() << endl;
    cout << "Popping: " << l.pop() << endl;
    cout << "Top of stack: " << l.peek() << endl;
    return 0;
}