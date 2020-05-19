/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 68511
 * Submitted at:  2018-10-26 13:32:14
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    752
 * Problem Name:  Task Manager
 */

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class people {
public:
	int start;
	int end;
	int finish;
	int pos;
	people(int s, int e,int p)
	{
		start = s;
		end = e;
		pos = p;
	}
	int getStart()
	{
		return start;
	}
	int getEnd()
	{
		return end;
	}
	int getPos()
	{
		return pos;
	}


};






int main()
{
	int times;
	while (cin >> times)
	{
		list<people> q0;
		list<people> q1;
		int st, end, pri;
		for (int i = 0; i < times; i++)
		{
			cin >> st >> end >> pri;
			people temp = people(st, end,i);
			if (pri == 0)
			{
				q0.push_back(temp);
			}
			else
			{
				q1.push_back(temp);
			}
		}
		int finishTime = 0;
		int f[1100];
		while (!q0.empty() && !q1.empty())
		{
			if (finishTime >= q0.front().getStart())
			{
				int pos = q0.front().getPos();
				f[pos] = q0.front().getEnd() + finishTime;
				q0.pop_front();
				finishTime = f[pos];
			}
			else if (finishTime >= q1.front().getStart())
			{
				int pos = q1.front().getPos();
				f[pos] = q1.front().getEnd() + finishTime;
				q1.pop_front();
				finishTime = f[pos];
			}
			else if (q0.front().getStart() <= q1.front().getStart())
			{
				int pos = q0.front().getPos();
				f[pos] = q0.front().getEnd() + q0.front().getStart();
				q0.pop_front();
				finishTime = f[pos];
			}
			else
			{
				int pos = q1.front().getPos();
				f[pos] = q1.front().getEnd() + q1.front().getStart();
				q1.pop_front();
				finishTime = f[pos];
			}
		}
		while (!q0.empty())
		{
			if (finishTime >= q0.front().getStart())
			{
				int pos = q0.front().getPos();
				f[pos] = q0.front().getEnd() + finishTime;
				q0.pop_front();
				finishTime = f[pos];
			}
			else
			{
				int pos = q0.front().getPos();
				f[pos] = q0.front().getEnd() + q0.front().getStart();
				q0.pop_front();
				finishTime = f[pos];
			}
		}
		while (!q1.empty())
		{
			if (finishTime >= q1.front().getStart())
			{
				int pos = q1.front().getPos();
				f[pos] = q1.front().getEnd() + finishTime;
				q1.pop_front();
				finishTime = f[pos];
			}
			else
			{
				int pos = q1.front().getPos();
				f[pos] = q1.front().getEnd() + q1.front().getStart();
				q1.pop_front();
				finishTime = f[pos];
			}
		}
		cout << f[0];
		for (int i = 1; i < times; i++)
		{
			cout << " " << f[i];
		}
		cout << endl;

	}
    return 0;
}