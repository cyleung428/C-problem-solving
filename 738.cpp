/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 62958
 * Submitted at:  2018-09-15 15:19:18
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    738
 * Problem Name:  Last digit of Fibonacci Number
 */

#include <iostream>
using namespace std;





int main()
{
	int i;
	int num[1000];
	num[0] = 0;
	num[1] = 1;
	int fNext;
	int fZero = 0;
	int fOne = 1;
	for (int i = 2;i <= 1000;i++)
	{
		fNext = (fOne + fZero) % 10;
		fZero = fOne;
		fOne = fNext;
		num[i] = fNext;
	}

	while (cin>>i)
	{
		cout << num[i] << endl;;
	}
	return 0;
}