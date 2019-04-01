#include <string>
#include <iostream>

using namespace std;

int main()
{
	string str;
	getline(cin,str);
	//finds all occurances of ' '
	int a;
	while ((a=str.find(' '))!=-1)
	{
		str[a] = '*';
	}
	cout << str << endl;
	//find last of '*' and cat from the the string
	str.erase(str.find_last_of('*')+1, str.length());
	str = str + "#!!@1234";
	cout << str << endl;
	//deleting each word befor *
	while ((a = str.find('*')) != -1)
	{
		str.erase(0,a+1);
		cout << str << endl;
	}
	return (0);
}