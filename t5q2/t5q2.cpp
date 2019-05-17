#include <iostream>
#include "List.h"
List merge(List lst1, List lst2)
{
	//
	List temp;
	do
	{
		temp.insertWithDuplicates(lst1.head->value);
		lst1.head = lst1.head->next;
	} while (lst1.head);//till null
	do
	{
		temp.insertWithDuplicates(lst2.head->value);
		lst2.head = lst2.head->next;
	} while (lst2.head);//till null
	return temp;
}

void makeSet(List& mergedList){
	List subList = mergedList;
	while (subList.head->next)//till null next element
	{
		int val = subList.head->value;
		subList.head = subList.head->next;//next node
		if(subList.search(val))// search for val in the sub list
		{
			mergedList.remove(val);//remove in MergedList
		}
	} 
}
using namespace std;
int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cin.ignore();
	cout << "enter sorted values for the second list:" << endl;
 	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	return 0;
}