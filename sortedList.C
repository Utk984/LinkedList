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
};

void Linkedlist::insertNode(int data)
{
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
	if(newNode->data < temp->data)
	{
			head = newNode;
			head->next = temp;
			return;
	}
    while (temp->next != NULL) {
			if(newNode->data < temp->next->data)
			{
					Node* temp2 = temp->next;
					temp->next = newNode;
					temp->next->next = temp2;
					return;
			}
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

int main()
{
    Linkedlist list;
    int num=0;
    do
    {
        cout << "Enter a number: ";
        cin >> num;
        list.insertNode(num);
		list.printList();
		cout << endl;
    } while(num!=0);

    cout << "\nElements of the list are: ";
    list.printList();
    cout << endl;
}
