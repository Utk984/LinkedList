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
public:
  Node* head;
	Linkedlist() { head = NULL; }
	void insertNode(int);
	void printList();
	void deleteNode(int);
	void reverseList();
  Linkedlist addList(Linkedlist);
};

void Linkedlist::deleteNode(int nodeOffset)
{
	Node *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}

	if (ListLen < nodeOffset) {
		cout << "Index out of range"
			<< endl;
		return;
	}

	temp1 = head;

	if (nodeOffset == 1) {

		head = head->next;
		delete temp1;
		return;
	}

	while (nodeOffset-- > 1) {

		temp2 = temp1;
		temp1 = temp1->next;
	}

	temp2->next = temp1->next;

	delete temp1;
}

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

void Linkedlist::reverseList()
{
	Node *temp = head->next,*temp2;

	if(head==NULL)
	{
			cout << "List empty" << endl;
			return;
	}
	head->next = NULL;
	while(temp!=NULL)
	{
			temp2 = temp->next;
			temp->next = head;
			head = temp;
			temp = temp2;
	}
}

Linkedlist Linkedlist::addList(Linkedlist l)
{
    Node *list = l.head;
    Node *list2 = head; int num1=0,num2=0;
    while(list!=NULL)
    {
        num1 = num1*10 + list->data;
        list = list->next;
    }
    while(list2!=NULL)
    {
        num2 = num2*10 + list2->data;
        list2 = list2->next;
    }
    int sum = num1 + num2;
    Linkedlist ListN;
    while(sum!=0)
    {
         ListN.insertNode(sum%10);
         sum/=10;
    }
    return ListN;
}

int main()
{
	Linkedlist list,list2,listN;
	int num=0;
  cout << "Enter elements of list 1: " << endl;
	do
	{
			cin >> num;
			list.insertNode(num);
	}while(num!=0);

  cout << "\nEnter elements of list 2: " << endl;
	do
	{
			cin >> num;
			list2.insertNode(num);
	}while(num!=0);

	cout << "\nList 1: ";
	list.printList();
	cout << endl;

	cout << "\nList 2: ";
	list2.printList();
	cout << endl;
  list.reverseList();
  list2.reverseList();
	listN = list.addList(list2);
	cout << "\nNew list: ";
	listN.printList();
	cout << endl;
	return 0;
}

