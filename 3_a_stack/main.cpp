/* Code to test the stack data structure */

// Stack data structure
#include "a_stack.h"

int main()
{
	a_stack s;
	if(s.is_empty())
		cout << "I am really lonely\n";
	
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

	count--;
	cout << endl;
	while(true)
	{
		if(s.pop() != count)
		{
			cout << s.peek() << "  "<< count << endl;
			break;
		}
		count--;
	}

	cout << "Size: " << s.size() << endl;
	cout << "Isfull: " << s.is_full() << endl;
	cout << "IsEmpty: " << s.is_empty() << endl;
}