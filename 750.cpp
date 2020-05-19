/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 72144
 * Submitted at:  2018-11-21 15:29:33
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    750
 * Problem Name:  Closest Common Ancestor
 */


#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
private:
	vector<TreeNode> child;
	int data;

public:
	TreeNode(int a)
	{
		data = a;
	}
	void insert(int a, int d)
	{
		if (d == data)
		{
			TreeNode newNode(a);
			child.push_back(newNode);
		}
		else
		{
			for (int i = 0;i < child.size();i++)
			{
				child.at(i).insert(a, d);
			}
		}
	}
	bool checkIsRoot(int d)
	{
		if (data == d)
			return true;
		else
		{
			for (int i = 0;i < child.size();i++)
			{
				if(child.at(i).checkIsRoot(d))
					return true;
			}
		}
		return false;
	}


	int close(int d1, int d2)
	{
		for (int i = 0;i < child.size();i++)
		{
			if (child.at(i).checkIsRoot(d1) && child.at(i).checkIsRoot(d2))
			{
				return child.at(i).close(d1, d2);
			}
		}
		return data;

	}



};


int main()
{
	int times;
	cin >> times;
	for (int i = 0;i < times;i++)
	{
		int size;
		int d;
		cin >> d>>size;
		TreeNode root(d);
		for (int i = 0;i < size-1;i++)
		{
			int r;
			cin >> d >> r;
			root.insert(d, r);
		}
		int n1, n2;
		cin >> n1>> n2;
		cout << root.close(n1, n2) << endl;;



	}
    return 0;
}