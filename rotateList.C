#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class Linkedlist {
	Node* head;

public:
	Linkedlist() { head = NULL; }

	void insertNode(int);
	void printList();
	void rotateList(int);
};

void Linkedlist::insertNode(int data)
{
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
}

void Linkedlist::printList()
{
	Node* temp = head;

	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void Linkedlist::rotateList(int k)
{
		Node *temp = head, *temp2 = head;
    	if (head == NULL) {
        	cout << "List empty" << endl;
        	return;
    	}
		for(int i=1;i<k;i++)
				temp = temp->next;
		while(temp2->next!=NULL)
				temp2 = temp2->next;
		temp2->next = head;
		head = temp->next;
		temp->next = NULL;
}

int main()
{
	Linkedlist list;
	int num=0;

	do{
			cout << "Enter a number: ";
			cin >> num;
			list.insertNode(num);
	}while(num!=0);

	cout << "\nElements of the list are: ";
	list.printList();
	cout << endl;
	
	cout << "\nEnter rotation value: ";
	int k=0;
	cin >> k;
	list.rotateList(k);
	cout << endl;

	cout << "\nElements of the list are: ";
	list.printList();
	cout << endl;
	return 0;
}
