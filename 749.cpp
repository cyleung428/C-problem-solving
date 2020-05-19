/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 71898
 * Submitted at:  2018-11-19 18:22:15
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    749
 * Problem Name:  Tree reconstruction
 */


#include <iostream> 
using namespace std;

// A utility function to search x in arr[] of size n 
int search(int arr[], int x, int n)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Prints postorder traversal from given inorder and preorder traversals 
void printPostOrder(int in[], int pre[], int n)
{
	// The first element in pre[] is always root, search it 
	// in in[] to find left and right subtrees 
	int root = search(in, pre[0], n);

	// If left subtree is not empty, print left subtree 
	if (root != 0)
	{
		printPostOrder(in, pre + 1, root);
		cout << " ";
	}

	// If right subtree is not empty, print right subtree 
	if (root != n - 1)
	{
		printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
		cout << " ";
	}

	// Print root 
	cout << pre[0];
}

// Driver program to test above functions 
int main()
{
	int times;
	cin >> times;
	for (int i = 0;i < times;i++)
	{
		int in[100];
		int pre[100];
		int num;
		cin >> num;
		for (int i = 0;i < num;i++)
		{
			int a;
			cin >> a;
			pre[i] = a;
		}
		for (int i = 0;i < num;i++)
		{
			int a;
			cin >> a;
			in[i] = a;
		}
		int n = num;
		printPostOrder(in, pre, n);
		cout << endl;
	}
	return 0;
}