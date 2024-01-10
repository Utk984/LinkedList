#include <iostream>

using namespace std;

class Node
{
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
				next = NULL;
		}
};

class Linkedlist
{
		Node* head;
		public:
		Linkedlist() { head = NULL; }
		void insert(int);
		void print();
		void swapNodes(int,int);
};

void Linkedlist::insert(int data)
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

void Linkedlist::print()
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

void Linkedlist::swapNodes(int x, int y)
{
		Node *prevX = head, *prevY = head;
		Node *temp = head;
		while(temp->next!=NULL)
		{
				if(temp->next->data==x)
						prevX = temp;
				if(temp->next->data==y)
						prevY = temp;
				temp = temp->next;
		}
		temp = prevX->next;
		Node *temp2 = prevY->next, *temp3 = prevY->next->next;
		prevX->next = temp2;
		temp2->next = temp->next;
		prevY->next = temp;
		temp->next = temp3;
}

int main()
{
		Linkedlist list;
    	int num=0;

    	do
    	{
            cout << "Enter a number: ";
            cin >> num;
            list.insert(num);
    	}while(num!=0);

    	cout << "\nElements of the list are: ";
    	list.print();
    	cout << endl;
    
		cout << "\nEnter elements to swap: \n";
		int x,y;
		cin >> x;
		cin >> y;
		list.swapNodes(x,y);

		cout << "\nElements of the list are: ";
    	list.print();
    	cout << endl;
    	return 0;		
}
