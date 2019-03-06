#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "t1q1/Rational.h"
using namespace std;

int main()
{
	char temp[20],num1[10], num2[10];
	cout << "enter two rational numbers" << endl;
	cin.getline(temp, 20);
	int i = 0, j=0;
	while (temp[i] == ' ')
	{
		strcpy(temp, temp + 1);
	}
	i = 0;
	while (temp[i]!=' ')
	{
		num1[i] = temp[i];
		i++;
	}
	num1[i] = 0;
	i++;
	while (temp[i])
	{
		num2[j] = temp[i];
		i++;
		j++;
	}
	num2[j] = 0;
	Rational a(num1);
	Rational b(num2);
	if (a == b)
	{
		cout << "equal";
	}
	else
	{
		cout << "different ";
		a.print();
		cout << ' ';
		b.print();
	}
	return 0;
}// 10/10 2/2
