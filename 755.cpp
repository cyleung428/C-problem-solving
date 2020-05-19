/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 72132
 * Submitted at:  2018-11-21 14:05:06
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    755
 * Problem Name:  Stock Market
 */


#include <iostream>
#include <stack> 
using namespace std;
long long int getMaxArea(long long int hist[], int n)
{
	stack<long long int> s;

	long long int max_area = 0;
	int tp;  // To store top of stack 
	long long int area_with_top; // To store area with top bar 
					   // as the smallest bar 

					   // Run through all bars of given histogram 
	int i = 0;
	while (i < n)
	{
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);
		else
		{
			tp = s.top();
			s.pop();
			area_with_top = hist[tp] * (s.empty() ? i :
				i - s.top() - 1);

			// update max area, if needed 
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate 
	// area with every popped bar as the smallest bar 
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i :
			i - s.top() - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}



int main()
{
	int times;
	cin >> times;
	for (int i = 0;i < times;i++)
	{
		long long int a[100001];
		int size;
		cin >> size;
		for (int i = 0;i < size;i++)
		{
			cin >> a[i];
		}
		cout << getMaxArea(a, size) << endl;
	}

    return 0;
}
