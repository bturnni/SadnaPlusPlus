#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List lst;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-2\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:cout << "enter a value to insert\n";
		if (cin >> val) // if the input is not int;
		{
			lst.insert(val);
		}
		else // empty the istream
		{
			cout << "Error Wrong type\n";
			cin.clear(); // clears the error flags
			// this line discards all the input waiting in the stream
			cin.ignore();
		}
			break;
		case 2:cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (char* msg)
			{
				cout << msg << endl;
			}
			break;
		default:cout << "ERROR\n";
		}
		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}
	return 0;
}
