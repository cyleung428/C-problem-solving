/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 66981
 * Submitted at:  2018-10-16 18:35:18
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    743
 * Problem Name:  Syntax Checker
 */

#include <iostream>
#include <string.h>
using namespace std;

class StackArray {
private:
	int top = -1;
	int capacity = 100000;
	char stack[100000];
	int num[100000];
public:
	void Push(char x, int y);
	void Pop();
	bool IsEmpty();
	char getTop();
	int getTopNum();
};




void StackArray::Push(char x, int y) {
	num[++top] = y;
	stack[top] = x;
}

void StackArray::Pop() {

	
	top--;

}

bool StackArray::IsEmpty() {

	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
	return (top == -1);
}

char StackArray::getTop() {

	return stack[top];
}

int StackArray::getTopNum()
{
	return num[top];
}

int main()
{
	char s[100000];
	while (cin.getline(s,100000))
	{
		StackArray c = StackArray() ;

		for (int i = 0;i < strlen(s);i++)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				c.Push(s[i], i);
			}
			if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (s[i] == ')' && c.getTop() == '(')
				{
					c.Pop();
				}
				else if (s[i] == ']' && c.getTop() == '[')
				{
					c.Pop();
				}
				else if (s[i] == '}' && c.getTop() == '{')
				{
					c.Pop();
				}
				else
				{
					c.Push(s[i], i);
				}
				
			}
		}
		if (c.IsEmpty())
		{
			cout << "Success" << endl;
		}
		else
		{
			int close = -1, open = -1;
			while (!c.IsEmpty())
			{
				if (c.getTop() == '(' || c.getTop() == '{' || c.getTop() == '[')
				{
					open = c.getTopNum()+1;
				}
				if (c.getTop() == ')' || c.getTop() == '}' || c.getTop() == ']')
				{
					close = c.getTopNum()+1;
				}
				c.Pop();
			}
			if (close != -1)
			{
				cout << close << endl;
			}
			else
			{
				cout << open << endl;
			}
		}

		

	}
	return 0;
}