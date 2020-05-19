/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 64973
 * Submitted at:  2018-10-03 15:57:10
 *
 * User ID:       539
 * Username:      55211931
 * Problem ID:    739
 * Problem Name:  Circle Game
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
	int size;                
	ListNode * first;     
public:
	LinkedList() :first(0) {};
	void Print(int x);      
	void SetNew(int x);
	void Delete(int x);  
	void AddNew(int x,int y);
};



void LinkedList::Print(int x) {

	ListNode *current = first;
	for (int i = 0;i < x - 1;i++)
	{
		current = current->next;
	}
	cout << current->data;
	ListNode *checkCurrent = first;
	ListNode *lastPoint = first;
	for (int i = 0;i < x - 2;i++)
	{
		lastPoint = lastPoint->next;
	}
	while (checkCurrent->next != 0)
	{
		checkCurrent = checkCurrent->next;
	}
	checkCurrent->next = first;
	first = current;
	lastPoint->next = NULL;

	cout << endl;
}



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

void LinkedList::AddNew(int pos, int input){
	ListNode *newNode = new ListNode(input);
	ListNode *current = first;
	ListNode *temp;
	ListNode *newStart;
	ListNode *endPoint;
	for (int i = 0;i < pos-1;i++)
	{
		current = current->next;
	}
	temp = current->next;
	current->next = newNode;
	current->next->next = temp;
	newStart = current->next;
	ListNode *checkCurrent = first;
	while (checkCurrent->next != 0)
	{
		checkCurrent = checkCurrent->next;
	}
	checkCurrent->next = first;
	first = newStart;
	current->next = NULL;
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

		ListNode *checkCurrent = first;
		while (checkCurrent->next != 0)
		{
			checkCurrent = checkCurrent->next;
		}
		checkCurrent->next = first;
		first = current->next;
		current->next = NULL;

	}




	
}





int main() {
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
			int pos3;
			cin >> pos3;
			list.Print(pos3);
			break;
		}
	}

	return 0;
}