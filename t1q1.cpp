//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//class Rational
//{
//private:
//	int mone;
//	int mechane;
//
//public:
//	Rational(char num1[])
//	{
//		char up[10], down[10];
//		int i = 0;
//		while (num1[i] != '/')
//		{
//			up[i] = num1[i];
//			i++;
//		}
//		up[i] = 0;
//		i = i + 1;
//		int j = 0;
//		while (num1[i] != '\0')
//		{
//			down[j] = num1[i];
//			i++;
//			j++;
//		}
//		down[i-2] = 0;
//		setMone(atoi(up));
//		setMechane(atoi(down));
//	}
//	void setMone(int mMone)
//	{
//		this->mone = mMone;
//	}
//	void setMechane(int mMechane)
//	{
//		if (mMechane == 0)
//		{
//			this->mechane = 1;
//			return;
//		}
//		this->mechane = mMechane;
//	}
//	int getMone()
//	{
//		return this->mone;
//	}
//	int getMechane()
//	{
//		return this->mechane;
//	}
//	void print()
//	{
//		cout << mone << '/' << mechane;
//	}
//	bool operator==(Rational& b) {
//		float a = (float)(this->mone) / (float)(this->mechane);
//		float toCompare = (float)b.getMone() / (float)b.getMechane();
//		return (a == toCompare) ? true : false;
//	}
//};
//
//int main()
//{
//	char temp[20],num1[10], num2[10];
//	cout << "enter two rational numbers" << endl;
//	cin.getline(temp, 20);
//	int i = 0, j=0;
//	while (temp[i] == ' ')
//	{
//		strcpy(temp, temp + 1);
//	}
//	i = 0;
//	while (temp[i]!=' ')
//	{
//		num1[i] = temp[i];
//		i++;
//	}
//	num1[i] = 0;
//	i++;
//	while (temp[i])
//	{
//		num2[j] = temp[i];
//		i++;
//		j++;
//	}
//	num2[j] = 0;
//	Rational a(num1);
//	Rational b(num2);
//	if (a == b)
//	{
//		cout << "equal";
//	}
//	else
//	{
//		cout << "different ";
//		a.print();
//		cout << ' ';
//		b.print();
//	}
//	return 0;
//}// 10/10 2/2
