/* Code to test the stack data structure */

// Stack data structure
#include "l_stack.h"

int main()
{
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

	for (int i = 0; i < 30; i++)
	{
		cout << l.pop() << " ";
	}
	cout << endl;

	cout << "Size is: " << l.size() << endl;
	cout << "Empty?: " << l.is_empty() << endl;
	cout << "Popping: " << l.pop() << endl;
	cout << "Top of stack: " << l.peek() << endl;

	cout << endl;
	l.pop() ; l.pop();

	cout << "Size is: " << l.size() << endl;
	cout << "Empty?: " << l.is_empty() << endl;
	cout << "Popping: " << l.pop() << endl;
	cout << "Top of stack: " << l.peek() << endl;
}