#include <vector>
#include "PHD.h"
#include "MA.h"
#include "BA.h"

using namespace std;


int main()
{
	vector<Student*> Students;
	// Students data
	float grade[] = { 90,100,90 };
	BA ba1(123, "abe", "avraham", 3, grade);
	float grade2[] = { 100, 100, 90, 100, 90, 100, 90, 100, 90, 100 };
	BA ba2(234, "yitzhak", "avrahamson", 10,grade2);

	float grade3[] = { 90,100,90,100,90,100,90 };
	MA ma1(345, "yaacov", "jacobson", 7, grade3, false);
	MA ma2(456, "sara", "emanu", 7, grade3, true);

	PHD phd1(567, "rivka", "imanu", 1, 30);
	PHD phd2(678, "rachel", "jacobs", 2, 20);
	PHD phd3(789, "leah", "jacobs", 2, 30);
	// push_back students to the vector
	Students.push_back(&ba1);
	Students.push_back(&ba2);
	Students.push_back(&ma1);
	Students.push_back(&ma2);
	Students.push_back(&phd1);
	Students.push_back(&phd2);
	Students.push_back(&phd3);
	
	for (int i = 0; i < 7;i++)
	{
		Students[i]->print();
	}

	return 0;
}