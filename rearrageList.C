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
	void rearrageList();
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

void Linkedlist::rearrageList()
{
		Node *temp1 = head, *temp2 = head->next, *temp3 = head->next;
		while(temp1->next!=NULL)
		{
				if(temp2->next==NULL)
						temp1->next = NULL;
				else{
						temp1->next = temp2->next;
						temp1 = temp1->next;
				}
				if(temp1->next==NULL)
						temp2->next = NULL;
				else{
						temp2->next = temp1->next;
						temp2 = temp2->next;
				}
		}
		temp1->next = temp3;
}

int main()
{
	Linkedlist list;
	int num=0;
	do
	{
		cout << "Enter a number: ";
		cin >> num;
		list.insertNode(num);
	} while(num!=0);

	cout << "\nElements of the list are: ";
	list.printList();
	cout << endl;		

	list.rearrageList();
	cout << "\nElements of the list are: ";
    list.printList();
    cout << endl;
}
