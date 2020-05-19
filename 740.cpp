/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 65647
 * Submitted at:  2018-10-08 22:43:30
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    740
 * Problem Name:  Manipulate List
 */

#include <iostream>
using namespace std;

class LinkedList;    
class ListNode {
private:
	int data;
	ListNode *next;
public:
	ListNode() :data(0), next(0) {};
	ListNode(int a) :data(a), next(0) {};

	friend class LinkedList;
};

class LinkedList {
private:
	ListNode * first;
public:
	LinkedList() :first(0) {};
	void AddNew(int x, int y);
	void SetNew(int x);
	void Delete(int x);
	void Print(int x);
	void Reverse(int x, int y);
};

void LinkedList::SetNew(int x) {

	ListNode *newNode = new ListNode(x);

	if (first == 0) {
		first = newNode;
		return;
	}

	ListNode *current = first;
	while (current->next != 0) {
		current = current->next;
	}
	current->next = newNode;
}

void LinkedList::AddNew(int pos, int input) {
	ListNode *newNode = new ListNode(input);
	ListNode *current = first;
	ListNode *temp;
	for (int i = 0;i < pos - 1;i++)
	{
		current = current->next;
	}
	temp = current->next;
	current->next = newNode;
	current->next->next = temp;
}

void LinkedList::Delete(int x) {
	ListNode *current = first;
	if (x == 1)
	{
		first = first->next;
	}
	else
	{
		for (int i = 0;i < x - 2;i++)
		{
			current = current->next;
		}
		current->next = current->next->next;

	}

}
void LinkedList::Reverse(int x, int y){
	if (first == 0 || first->next == 0) {
		return;
	}



	ListNode *previous = NULL,
		*current = first,
		*firstStartPoint,
		*secondStartPoint,
		*secondEndPoint = first,
		*preceding,
		*firstEndPoint = first;
	for (int i = 0;i < x - 1;i++)
	{
		current = current->next;
	}
	preceding = current->next;
	for (int i = 0;i < x - 2;i++)
	{
		firstEndPoint = firstEndPoint->next;
	}
	firstStartPoint = firstEndPoint->next;
	for (int i = 0;i < y - 1;i++)
	{
		secondEndPoint = secondEndPoint->next;
	}
	secondStartPoint = secondEndPoint->next;
	firstEndPoint->next = NULL;
	secondEndPoint->next = NULL;
	while (preceding != 0) {
		current->next = previous;
		previous = current;
		current = preceding;
		preceding = preceding->next;
	}
	current->next = previous;
	firstEndPoint->next = secondEndPoint;
	firstStartPoint->next = secondStartPoint;



}

void LinkedList::Print(int x) {

	ListNode *current = first;
	for (int i = 0;i < x - 1;i++)
	{
		current = current->next;
	}
	cout << current->data;
	cout << endl;
}




int main(){
	LinkedList list;
	int inputNum;
	cin >> inputNum;
	for (int i = 0;i < inputNum;i++)
	{
		int n;
		cin >> n;
		list.SetNew(n);
	}
	int inputTimes;
	cin >> inputTimes;

	for (int i = 0;i < inputTimes;i++)
	{
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
			int pos, input;
			cin >> pos >> input;
			list.AddNew(pos, input);
			break;
		case 2:
			int pos2;
			cin >> pos2;
			list.Delete(pos2);
			break;
		case 3:
			int start, end;
			cin >> start >> end;
			list.Reverse(start, end);
			break;
		case 4:
			int pos4;
			cin >> pos4;
			list.Print(pos4);
			break;

		}
	}

    return 0;
}
