/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 71882
 * Submitted at:  2018-11-19 18:01:20
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    754
 * Problem Name:  Hotel Arrangement
 */


#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

bool checkReach(vector<int> v, int c, int d)
{
	int times = 1;
	int current = v.at(0);
	for (std::vector<int>::iterator it = v.begin() + 1; it != v.end(); ++it)
	{
		if (current + d <= *it)
		{
			times++;
			current = *it;
		}
		if (times >= c)
		{
			return true;
		}
	}
	if (times >= c)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int binarySearch(int l, int r,vector<int> v,int c)
{
	
	int mid = l + (r - l) / 2;
	if (checkReach(v, c, mid) && !checkReach(v, c, mid + 1))
	{
		return mid;
	}
	if (!checkReach(v, c, mid))
	{
		return binarySearch(l, mid - 1, v, c);
	}
	if (checkReach(v, c, mid))
	{
		return binarySearch( mid + 1, r, v, c);
	}
}





int main()
{
	int times;
	cin >> times;
	for (int i = 0;i < times;i++)
	{
		int customers;
		int rooms;
		cin >> rooms >> customers;
		vector<int> dis;
		for (int i = 0;i < rooms;i++)
		{
			int a;
			cin >> a;
			dis.push_back(a);
		}
		sort(dis.begin(), dis.end());
		int max = dis.at(dis.size()-1) - dis.at(0);
		int min = dis.at(1)-dis.at(0);
		int first = dis.at(0);
		int second;
		for (std::vector<int>::iterator it = dis.begin() + 1; it != dis.end(); ++it)
		{
			second = *it;
			if (min > second - first)
			{
				min = second - first;
			}
			first = *it;
		}
		if (customers == rooms)
		{
			cout << min << endl;
		}
		else if (min == max)
		{
			cout << min << endl;
		}
		else
		{
			cout << binarySearch(min, max, dis, customers) << endl;
		}


	}

    return 0;
}