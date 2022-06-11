/* Operations on array */

#ifndef ARRAY_OPT_H
#define ARRAY_OPT_H

// Array ADT
#include "array.h"

// Function to display an array as a list
void array::display_array(vector<lint> &vect)
{
	cout << "[";
	if(vect.size())
	{
		for (int i = 0; i < vect.size(); i++)
		{
			cout << vect[i];
			cout << ",";
		}
		cout << "\b";
	}
	cout << "]\n";
}

#endif