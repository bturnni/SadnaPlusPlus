#include "Date.h"
using namespace std;

int main()
{
	int choice;
	int days, months, years;
	char slash;
	Date d2;
	cout << "Enter a date" << endl;
	cin >> days >> slash >> months >> slash >> years;
	Date d1(days, months, years);
	do {
		cout << "What do you want to do\n";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1://setdate
			cout << "Enter a date" << endl;
			//input
			cin >> days >> slash >> months >> slash >> years;
			d1.setDate(days, months, years);
			d1.print();
			break;
		case 2://++d
			(++d1).print();
			break;
		case 3://d++
			d1++.print();
			break;
		case 4://d+=days
			cout << "Enter #days" << endl;
			int numDay;
			cin >> numDay;
			d1 += numDay;
			d1.print();
			break;
		case 5://d1>d2
			cout << "Enter a date" << endl;
			cin >> days >> slash >> months >> slash >> years;
			d2.setDate(days, months, years);
			cout << ">: ";
			if (d1 > d2)
				cout << "true\n";
			else cout << "false\n";
			break;

		case 6://d1<d2
			cout << "Enter a date" << endl;
			cin >> days >> slash >> months >> slash >> years;
			d2.setDate(days, months, years);
			cout << "<: ";
			if (d1 < d2)
				cout << "true\n";
			else cout << "false\n";
			break;
		case 7://d1==d2
			cout << "Enter a date" << endl;
			cin >> days >> slash >> months >> slash >> years;
			d2.setDate(days, months, years);
			cout << "==: ";
			if (d1 == d2)
				cout << "true\n";
			else cout << "false\n";
			break;
		default:
			break;
		}
	} while (choice != -1);

	return 0;
}