/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 72116
 * Submitted at:  2018-11-21 12:53:22
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    756
 * Problem Name:  Max-Heap
 */


#include <iostream>
using namespace std;

class MyHeap
{
private:
	int size = 0;
	int items[100000];
public:
	void Insert(int key);
	int pop();
	void print();
};

void MyHeap::Insert(int key)
{
	int temp;
	int i = size;
	items[i] = key;
	while (items[i]>items[(i - 1) / 2] && i != 0)
	{
		temp = items[i];
		items[i] = items[(i - 1) / 2];
		items[(i - 1) / 2] = temp;
		i = (i - 1) / 2;
	}
	size++;
}

int MyHeap::pop()
{
	int temp, value;
	int i = size;
	value = items[0];
	items[0] = items[i - 1];
	int hole = 0;
	temp = items[hole];
	int child = hole * 2 + 1;
	for (; hole * 2 + 1 < size;hole = child)
	{
		child = hole * 2 + 1;
		if (child+1<size &&items[child + 1]>items[child])
			child++;
		if (items[child] > items[hole])
		{
			temp=items[hole];
			items[hole] = items[child];
			items[child] = temp;
		}
		else
		{
			size--;
			return value;
			break;
		}
	}
	size--;
	return value;
}

void MyHeap::print()
{
	int j = 0;
	for (int k = 0;k < size;k++)
	{
		j += items[k];
	}
	cout << j << endl;;
}



int main()
{
	int times;
	while (cin >> times)
	{
		MyHeap h = MyHeap();
		for (int i = 0;i < times;i++)
		{
			char oper;
			cin >> oper;
			if (oper == 'a')
			{
				int num;
				cin >> num;
				h.Insert(num);
			}
			else if (oper == 'p')
			{
				h.pop();
			}
			else
			{
				h.print();
			}

		}
	}
    return 0;
}