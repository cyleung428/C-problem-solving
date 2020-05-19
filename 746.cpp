/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 67351
 * Submitted at:  2018-10-19 00:07:51
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    746
 * Problem Name:  Fast Food Restaurant
 */

#include <iostream>
using namespace std;

class MyQueue
{
private:
	int front=0;
	int rear=0;
	int finishTime[200000];
	int TOTAL_SLOTS = 200000;
public: 		
	bool isEmpty();
	bool isFull();
	void enqueue(int a);
	int dequeue();
	int getSlots();
	int getFront();
};
int MyQueue::getSlots()
{
	return (rear - front);
}
bool MyQueue::isEmpty()
{
	return (front == rear);
}
bool MyQueue::isFull()
{
	return((rear + 1) % TOTAL_SLOTS == front);
}

void MyQueue::enqueue(int data)
{
	if (!isFull())
	{
		finishTime[rear] = data;
		rear = (rear + 1);
	}
}
int MyQueue::dequeue()
{
	int ret_val;
	if (!isEmpty())
	{
		ret_val = finishTime[front];
		front = (front + 1) % TOTAL_SLOTS;
		return ret_val;
	}
}

int MyQueue::getFront()
{
	return finishTime[front];
}



int main()
{
	
	int testTimes;
	while (cin >> testTimes)
	{
		bool state = true;
		MyQueue q;
		int nextFinish;
		int startTime, runTime, waitNo;
		cin >> startTime >> runTime >> waitNo;
		nextFinish = startTime + runTime;
		q.enqueue(nextFinish);
		for (int i = 0; i < testTimes-1;i++)
		{
			cin >> startTime >> runTime >> waitNo;
			while (q.getFront() <= startTime&&!q.isEmpty())
			{
				q.dequeue();
			}
			if (waitNo >= q.getSlots())
			{
				state = true;
				if (q.isEmpty())
				{
					q.enqueue(startTime + runTime);
					nextFinish = (startTime + runTime);
				}
				else
				{
					if (startTime >= nextFinish)
					{
						while (!q.isEmpty())
						{
							q.dequeue();
						}
						nextFinish = (startTime + runTime);
						q.enqueue(nextFinish);
					}
					else
					{
						nextFinish += runTime;
						q.enqueue(nextFinish);
					}
				}
			}
			else
			{
				state = false;
			}
		}
		if (state == true)
		{
			cout << (nextFinish - runTime) << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
		
	}
	return 0;
}
