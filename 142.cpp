/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 72801
 * Submitted at:  2018-11-26 15:57:53
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    142
 * Problem Name:  FRIENDS (UVa 10608)
 */


#include <iostream>
#include <algorithm>
using namespace std;
int father[30001];
int Rank[30001];
int Find(int x)
{
	if (x == father[x])
		return x;
	return father[x] = Find(father[x]);
}
void Merge(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y)
		return;
	if (Rank[x] <= Rank[y])
	{
		father[x] = y;
		Rank[y] += Rank[x];
	}
	else
	{
		father[y] = x;
		Rank[x] += Rank[y];
	}
}
void init(int n)
{
	for (int i = 1;i <= n;i++)
	{
		father[i] = i;
		Rank[i] = 1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m, t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		init(n);
		for (int i = 1;i <= m;i++)
		{
			int a, b;
			cin >> a >> b;
			Merge(a, b);
		}
		int ans = -1;
		for (int i = 1;i <= n;i++)
		{
			ans = max(ans, Rank[i]);
		}
		cout << ans << endl;
	}
	return 0;
}