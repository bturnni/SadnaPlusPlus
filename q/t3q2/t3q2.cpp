#include "Vector.h"
enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast
	//		0	1:=	   2:==	3:* 4:+ 5	6  
};
int main()
{
	Vector  v1(10), v2(10), v3;
	for (int i = 1; i <= 4; i++)
	{
		v1.insert(i);
		v2.insert(i + 4);
	}
	int choice;
	char* str = 0;
	cout << "enter your choice 0-6\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case assignment: v3 = v1;
			break;
		case isEqual:	if (v1 == v2) cout << "v1==v2\n"; else cout << "v1!=v2\n";
			break;
		case mult:
			int mul;
			try
			{
				mul = v1 * v2;
			}
			catch (char* str)
			{
				cout << str;
			}
			if(!str)//check if the exeption thowed
			cout << "v1*v2=" << mul << endl;
			break;
		case add:		v3 = v1 + v2;
			break;
		case clear:		v1.clear();
			break;
		case delLast:	v2.delLast();
			break;
		default: cout << "ERROR";
		}
		v1.print();		v2.print();		v3.print();
		cout << "enter your choice 0-6\n";
		cin >> choice;
	}
	return 0;
}
