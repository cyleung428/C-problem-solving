/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 67240
 * Submitted at:  2018-10-18 15:24:33
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    744
 * Problem Name:  Stack Shuffling
 */

#include <iostream>
using namespace std;

class StackArray {
private:
	int top = -1;
	int capacity = 3000;
	int num[3000];
public:
	void Push(int y);
	void Pop();
	bool IsEmpty();
	int getTop();
	bool Check(int b[], int bSize);
	void Back(int t);
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

void StackArray::Back(int t)
{
	top = t - 1;
}

bool StackArray::Check(int b[], int bSize)
{
	StackArray S;
	int i = 0;
	bool state = true;
	while (state && i < bSize)
	{

		while (!IsEmpty() && getTop() != b[i] && S.getTop() != b[i])
		{
			S.Push(getTop());
			Pop();
		}
		if (getTop() == b[i])
		{
			Pop();
		}
		else if (S.getTop() == b[i])
		{
			S.Pop();
		}
		else
		{
			state = false;
			return state;
		}
		i++;
	}
	return state;


}



int main() {
	int times;
	cin >> times;
	for (int i = 0;i < times;i++)
	{
		StackArray A;
		int arrSize;
		cin >> arrSize;
		for (int i = 0;i < arrSize;i++)
		{
			int a;
			cin >> a;
			A.Push(a);
		}
		int checkTimes;
		cin >> checkTimes;
		for (int i = 0;i < checkTimes;i++)
		{
			int b[3000];
			for (int i = 0;i < arrSize;i++)
			{
				cin >> b[i];
			}
			if (A.Check(b, arrSize))
			{
				cout << "Aye" << endl;
			}
			else
			{
				cout << "Impossible" << endl;
			}
			A.Back(arrSize);
		}


	}
	return 0;
}