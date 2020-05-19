/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 68632
 * Submitted at:  2018-10-26 17:57:54
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    753
 * Problem Name:  Amazing Tree
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class c {

public:
	char label;
	int pos;
	c(char l, int p)
	{
		label = l;
		pos = p;
	}


};






int calcu(string T) {
	if (T == "()")
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < T.size() - 1; i++)
		{
			if (T.at(i) == '('&&T.at(i + 1) == ')')
			{
				T.erase(i, 2);
				return 1 + calcu(T);
			}
		}
		return 0;
	}



}


int main()
{
	string s;
	while (cin >> s)
	{
		vector<int> times;
		list<c> temp;
		while (!s.empty())
		{
			temp.push_back(c(s.at(0), 0));
			int pos = 1;
			int last;
			while (!temp.empty())
			{
				if (s.at(pos) == ')')
				{
					temp.pop_back();
					last = pos;
				}
				else
				{
					temp.push_back(c(s.at(pos), pos));
				}
				pos++;
			}
			string thesub = s.substr(0, last);
			times.push_back(1+calcu(thesub));
			s.erase(s.begin()+last);
			s.erase(s.begin());

		}

		int xVal = times.front();
		for (int i = 1; i < times.size(); i++)
		{
			xVal = xVal ^ times.at(i);
		}
		cout << xVal << endl;


	}

	return 0;
}
