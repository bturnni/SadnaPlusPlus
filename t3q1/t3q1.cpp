#include "String.h"

int main()
{
	char c1[20], c2[20];
	int  index;

	cin >> c1;
	cin >> c2;
	cin >> index;
 
	String a(c1), b(c2);
	if (a > b)
		cout << "a>b\n";
	else if (a < b)
		cout << "a<b\n";
	else
		cout << "a=b\n";

	if (index < 0) {
		cout << "ERROR" << endl;
		return 0;
	}

	String temp = b;
	b.insert(index, c1);
	if (b != temp)
		b.print();

	return 0;
}