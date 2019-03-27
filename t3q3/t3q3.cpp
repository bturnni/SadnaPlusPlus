#include "Poligon.h"
using namespace std;
int main()
{
	Poligon a;
	int numOfPoints;
	cin >> numOfPoints;
	while (numOfPoints<0)
	{
		cout << "Error\n";
		cin >> numOfPoints;
	}
	int counter = 0, x, y;
	//counter should be = numpoints
	while ((counter) < numOfPoints)
	{
		cin >> x;
		while (x<0)
		{
			cout << "Error\n";
			cin >> x;
		}
		cin >> y;
		while (x < 0)
		{
			cout << "Error\n";
			cin >> x;
		}
		a.addPoint(Point(x, y));
		counter++;
	}
	a.print();
	cout << a.round()<<endl;

	return 0;
}