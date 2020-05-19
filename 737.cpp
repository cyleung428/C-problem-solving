/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 63211
 * Submitted at:  2018-09-16 19:05:12
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    737
 * Problem Name:  word count
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	string word[1000];
	string str;
	int position = 0;
	int countTimes[1000];
	for (int i = 0;i < 1000;i++)
	{
		countTimes[i] = 1;
	}
	while (cin>>str)
	{
		bool add = true;
		for (int i=0;i <= position;i++)
		{
			if (word[i] == str)
			{
				countTimes[i]++;
				add = false;
			}
		}
		if (add)
		{
			word[position] = str;
			position++;
		}
	}

	for (int i = 0;i < position;i++)
	{
		for (int j = i;j < position;j++)
		{
			if (word[i] > word[j])
			{
				int tempTimes;
				string tempStr;
				tempStr = word[i];
				tempTimes = countTimes[i];
				word[i] = word[j];
				countTimes[i] = countTimes[j];
				word[j] = tempStr;
				countTimes[j] = tempTimes;

			}

		}


	}

	for (int j = 0;j <position;j++)
	{
		cout << word[j] <<" "<<countTimes[j]<< endl;
	}




    return 0;
}