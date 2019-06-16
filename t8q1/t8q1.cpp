#include <iostream>
#include <stack>
#include <string>
using namespace std;


// Simply determine if character is one of the four standard operators.
bool isOperator(char character) {
	if (character == '+' || character == '-' || character == '*' || character == '/') {
		return true;
	}
	return false;
}


// If the character is not an operator or a parenthesis, then it is assumed to be an operand.
bool isOperand(char c) {
	if (c=='+' || c=='-'|| c=='/'||c=='*') {
		return true;
	}
	return false;
}


// Compare operator precedence of main operators.
// Return 0 if equal, -1 if op2 is less than op1, and 1 if op2 is greater than op1.
int OperandsOrder(char c) {
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string inFixToPostFix(string infix)
{
	stack<char> stk;
	stk.push('@');               //add some extra character to avoid underflow
	string postfix = "";
	int i = 0;
	char ch;
	do {
		ch = infix[i];
		if (ch == '(')
		{
			stk.push('(');
		}
		else if (ch == ')')
		{
			while (stk.top() != '@' && stk.top() != '(') {
				postfix += ' ';
				postfix += stk.top(); //store and pop until ( has found
				stk.pop();
			}
			if (stk.top() == '(')
			{
				stk.pop();//remove '(' from stack
			}
		}
		else if (isOperand(ch))
		{
			while (stk.top() != '@' && OperandsOrder(ch) <= OperandsOrder(stk.top()))
			{
				char c = stk.top();
				stk.pop();
				postfix += ' ';
				postfix += c;
			}
			postfix += ' ';
				stk.push(ch);
		}
		else if (isdigit(ch))//check if ch is a numeric character.
		{
			postfix += ch;
		}
		i++;
	} while (ch);
	while (stk.top() != '@' && !stk.empty())
	{
		char c = stk.top();
		stk.pop();
		postfix += ' ';
		postfix += c;
	}
	return postfix;
}
int CalcPostfix(string postfix)
{
	char ch;
	int temp = 0;
	stack<float> stk;
	while (postfix.length()>0)
	{
		string temp = postfix.substr(0, postfix.find(' '));
		postfix.erase(0, postfix.find(' '));
		postfix.erase(0,1);
		if (isOperand(temp[0]))
		{
			float val2 = stk.top();
			stk.pop();
			float val1 = stk.top();
			stk.pop();
			switch (temp[0])
			{
			case '+':
				stk.push(val1 + val2);
				break;

			case '-':
				stk.push(val1 - val2);
				break;

			case '/':
				stk.push(val1 / val2);
				break;

			case '*':
				stk.push(val1 * val2);
				break;
			default:
				break;
			}		}
		else
		{
			stk.push(atoi(temp.data()));
		}
	}
	return stk.top();
}
int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = inFixToPostFix(exp);
	cout << postfix << endl;
	cout << CalcPostfix(postfix) << endl;
	return 0;
}
