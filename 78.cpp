/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 64441
 * Submitted at:  2018-09-26 16:16:47
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    78
 * Problem Name:  Largest Subsequence
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	char input[52];
	while (cin >> input)
	{
		char output[52];
		int j = 0;
		char a = input[0];
		int count = 0;
		int largest;
		while (j < strlen(input))
		{
			largest = j;
			a = input[j];
			for (int k = j+1;k < strlen(input);k++)
			{
				
				if (int(input[k] > int(a)))
				{
					a = input[k];
					largest = k;
				}
				
			}
			j = largest+1;
			if (int(a) >= 97 && int(a) <= 122)
			{
				output[count] = a;
				count++;
			}
			



		}
		if (count != 0)
		{
			for (int i = 0;i < count;i++)
			{
				cout << output[i];
			}
			cout << endl;
		}
	}
	return 0;
}
