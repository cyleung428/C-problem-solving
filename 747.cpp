/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 70599
 * Submitted at:  2018-10-29 21:30:51
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    747
 * Problem Name:  Boring job
 */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class num {
public:
	int no;
	int pos;
	num(int n, int p)
	{
		no = n;
		pos = p;
	}
};



int main()
{
	int times;
	cin >> times;
	for (int i = 0; i < times; i++)
	{
		int magic;
		int numsize;
		list<num> lt;
		cin >> numsize >> magic;
		for (int i = 0; i < numsize; i++)
		{
			int nu;
			cin >> nu;
			lt.push_back(num(nu, i + 1));
		}
		list<int> result;
		while (!lt.empty())
		{
			int max = lt.front().no;
			int pos = lt.front().pos;
			list<num>temp;
			if (lt.size() >= magic)
			{
				for (int i = 0; i < magic; i++)
				{
					if (lt.front().no > max)
					{
						max = lt.front().no;
						pos = lt.front().pos;
					}
					//else if (lt.front().no == max)
					//{
					//	if (lt.front().pos < pos)
					//	{
					//		pos = lt.front().pos;
					//	}
					//}
					temp.push_back(num(lt.front().no, lt.front().pos));
					lt.pop_front();
				}

			}
			else
			{
				while (!lt.empty())
				{
					if (lt.front().no > max)
					{
						max = lt.front().no;
						pos = lt.front().pos;
					}
					/*else if (lt.front().no == max)
					{
						if (lt.front().pos < pos)
						{
							pos = lt.front().pos;
						}
					}*/
					temp.push_back(num(lt.front().no, lt.front().pos));
					lt.pop_front();
				}
			}
			result.push_back(pos);
			while (!temp.empty())
			{
				if (temp.front().pos != pos)
				{
					lt.push_back(num(temp.front().no - 1, temp.front().pos));
					temp.pop_front();
				}
				else
				{
					temp.pop_front();
				}
			}

		}
		cout << result.front();
		result.pop_front();
		while(!result.empty())
		{
			cout << " "<< result.front() ;
			result.pop_front();
		}
		cout << endl;

	}
    return 0;
}