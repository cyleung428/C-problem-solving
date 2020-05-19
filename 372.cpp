/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 68288
 * Submitted at:  2018-10-25 21:36:56
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    372
 * Problem Name:  Jumping Mario
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	int times;
	cin >> times;
	for (int i = 0; i < times; i++)
	{
		int high = 0;
		int low = 0;
		int thiswall;
		int nextwall;
		int wallNo;
		cin >> wallNo;
		cin >> thiswall;
		for (int i = 1; i < wallNo; i++)
		{
			cin >> nextwall;
			if (thiswall > nextwall)
			{
				low++;
			}else if(thiswall<nextwall)
			{
				high++;
			}
			thiswall = nextwall;
		}









		cout << "Case " << i + 1 << ": " << high << " " << low << endl;;
	}
    return 0;
}