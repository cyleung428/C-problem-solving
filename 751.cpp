/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 68333
 * Submitted at:  2018-10-25 22:30:17
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    751
 * Problem Name:  Reverse Polish Notation
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	string S;
	while (getline(cin,S))
	{
		stack<int> oper;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] >= '0' && S[i] <= '9')
			{
				const char* s = &S[i];
				oper.push(atoi(s));
			}
			else if (S[i] == '+')
			{
				int a = oper.top();
				oper.pop();
				int b = oper.top();
				oper.pop();
				oper.push(a + b);
			}
			else if (S[i] == '-')
			{
				int a = oper.top();
				oper.pop();
				int b = oper.top();
				oper.pop();
				oper.push(b - a);
			}
			else if (S[i] == '*')
			{
				int a = oper.top();
				oper.pop();
				int b = oper.top();
				oper.pop();
				oper.push(a*b);
			}

		}

		cout << oper.top() << endl;;

	}



    return 0;
}