/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 66107
 * Submitted at:  2018-10-12 16:12:55
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    742
 * Problem Name:  Simple Quadtree
 */

#include <iostream>
#include <cmath>
using namespace std;

int calculate(char **array, int rowSt, int rowEnd, int colSt, int colEnd)
{
	if (rowEnd == rowSt)
	{
		return 1;
	}
	else
	{
		bool same = true;
		char a = array[rowSt][colSt];
		for (int i = colSt;i <= colEnd;i++)
		{
			for (int j = rowSt;j <= rowEnd;j++)
			{
				if (a != array[j][i])
				{
					same = false;
				}
			}
		}
		if (same == true)
		{
			return 1;
		}
		else
		{
			return 1 + calculate(array, rowSt, (rowSt + rowEnd) / 2, colSt, (colSt + colEnd) / 2) + calculate(array, rowSt, (rowSt + rowEnd) / 2, (colSt + colEnd) / 2 + 1, colEnd) + calculate(array, ((rowSt + rowEnd) / 2) + 1, rowEnd, colSt, (colSt + colEnd) / 2) + calculate(array, (rowSt + rowEnd) / 2 + 1, rowEnd, (colSt + colEnd) / 2 + 1, colEnd);
		}

	}




}
int main()
{
	int k, n;
	while (cin >> k)
	{
		n = pow(2, k);
		char**num = new char*[n];
		for (int i = 0;i < n;i++)
		{
			num[i] = new char[n];
		}
		for (int i = 0;i < n;i++)
		{
			cin >> num[i];
		}
		cout << calculate(num, 0, n - 1, 0, n - 1) << endl;
	}

	return 0;
}
