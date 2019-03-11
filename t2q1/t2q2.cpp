#include "Rational.h"

int main() {
	cout << "Enter two rational numbers" << endl;
	char str[40];
	cout << "a: ";
	cin.getline(str, 40);
	cout << endl;
	Rational a(str);
	cout << "b: ";
	cin.getline(str, 40);
	Rational b(str);
	cout << endl;
	//printing as requierd:
	cout << "b-a: ";
	(b - a).print();

	cout << "a!=b: ";
	(a !=b) ? cout << "true\n" : cout << "false\n";
	
	cout << "a<b: ";
	(a < b) ? cout << "true\n" : cout << "false\n";
	
	cout << "a>b: ";
	(a > b) ? cout << "true\n" : cout << "false\n";
	
	cout << "a>=b: ";
	(a >= b) ? cout << "true\n" : cout << "false\n";
	
	cout << "a++: ";
	a++.print();
	
	cout << "--a: ";
	(--a).print();
	
	cout << "a--: ";
	a--.print();

	b=a;

	cout << "b-a: ";
	(b - a).print();

	cout << "b/a: ";
	(b/a).print();

	cout << "a!=b: ";
	(a != b) ? cout << "true\n" : cout << "false\n";

	cout << "a<b: ";
	(a < b) ? cout << "true\n" : cout << "false\n";

	cout << "a>=b: ";
	(a >= b) ? cout << "true\n" : cout << "false\n";

	return 0;
}
//cout << "a: " 2/3
//b: 3/4
//b-a: 1/12
//cout << "a!=b: "true
//cout << "a<b: "true
//cout << "a>b: "false
//cout << "a>=b: "false
//cout << "a++: "2/3
//cout << "--a: "2/3
//cout << "a--: "2/3
////b=aכאן יש לבצע הצבה של 
//b-a: 0
//b/a: 1
//a!=b: false
//a<b: false
//a>=b: true
