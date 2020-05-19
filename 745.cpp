/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 67326
 * Submitted at:  2018-10-18 22:03:36
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    745
 * Problem Name:  Poker
 */

#include <iostream>
using namespace std;

class StackArray {
private:
	int top = -1;
	int num[20000];
public:
	void Push(int y);
	void Pop();
	bool IsEmpty();
	int getTop();
};




void StackArray::Push(int y) {
	num[++top] = y;
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

int StackArray::getTop() {

	return num[top];
}


int main()
{
	int caseNum;
	cin >> caseNum;
	for (int i = 0;i < caseNum;i++)
	{
		StackArray Poke;
		int size;
		cin >> size;
		int max = 0;
		for (int i = 0;i < size;i++)
		{
			int a;
			cin >> a;
			if (a > max)
			{
				max = a;
			}
			Poke.Push(max);
		}
		int operation;
		cin >> operation;
		for (int i = 0;i < operation;i++)
		{
			char oper;
			cin >> oper;
			switch (oper)
			{
				case 'm':
					cout << Poke.getTop() << endl;
					break;
				case 'r':
					Poke.Pop();
					break;
				case 'a':
					int a;
					cin >> a;
					if (a > Poke.getTop())
					{
						Poke.Push(a);
					}
					else
					{
						Poke.Push(Poke.getTop());
					}
					break;
			}
		}
	}
    return 0;
}
