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
  bool searchList(Linkedlist);
};

void Linkedlist::insertNode(int data)
{
  if(data==0)
    return;
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

bool Linkedlist::searchList(Linkedlist obj)
{
  Node *temp = head, *temp2 = obj.head;
  if (head==NULL || obj.head==NULL){
    cout << "List empty" << endl;
    return false;
  }

  while(temp!=NULL)
  {
    if(temp->data == temp2->data)
      temp2 = temp2->next;
    else
      temp2 = obj.head;
    temp = temp->next;
    if(temp2==NULL)
      return true;
  }
  return false;
}

int main()
{
	Linkedlist list,list2;
	int num=0;
  cout << "Enter list 1: " << endl;
	do
	{
			cin >> num;
			list.insertNode(num);
	}while(num!=0);

  cout << "Enter list 2: " << endl;
	do
	{
			cin >> num;
			list2.insertNode(num);
	}while(num!=0);

	cout << "\nElements of list 1 are: ";
	list.printList();
	cout << endl;

	cout << "\nElements of list 2 are: ";
	list2.printList();
	cout << endl;
  
	bool result = list.searchList(list2);
  if(result)
    cout << "\nLIST FOUND";
  else
    cout << "\nLIST NOT FOUND";
	cout << endl;
	return 0;
}
