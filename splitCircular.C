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
		Node(int n)
		{
				data = n;
				next = NULL;
		}
};

class Linkedlist
{
		Node *head,*head1,*head2;
		public:
        Linkedlist() { head = NULL; }
		Node* gethead() { return head; }
		void insert(int);
		void print(Node*);
		void separate();/**
		~Linkedlist()
		{
				Node* link = head;
				while(link!=NULL)
				{
						Node* temp = link;
						head = link->next;
        				delete temp;
				}
		}*/
};

void Linkedlist::insert(int data)
{
		Node* newnode = new Node(data);
		if(head == NULL)
		{
				head = newnode;
				head->next = head;
				return;
		}
		Node* temp = head;
		while(temp->next!=head)
				temp = temp->next;
		temp->next = newnode;
		temp->next->next = head;
}

void Linkedlist::print(Node* head)
{
		Node* temp = head;
    	if (head == NULL) {
        		cout << "List empty" << endl;
        		return;
    	}
    	do{
        		cout << temp->data << " ";
        		temp = temp->next;
    	}while (temp != head);
}

void Linkedlist::separate()
{
		if(head==NULL)
		{
				cout << "Linked list is empty" << endl;
				return;
		}
		int length=1;
		Node* temp = head;
		while(temp->next!=head)
		{
				length++;
				temp = temp->next;
		}
		int i=0; temp = head;
		head1 = temp;
		
		while(temp->next!=head)
		{
				if(i==length/2)
				{
						head2 = temp->next;
						temp->next = head1;
						temp = head2;
				}
				temp = temp->next;
				i++;
		}
		cout << "\nList 1: " << endl;
		print(head1);
    	cout << endl;
		temp->next = head2;
		cout << "\nList 2: " << endl;
		print(head2);
		cout << endl;
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
    	} while(num!=0);

    	Node* temp = list.gethead();
		cout << "\nElements of the list are: ";
    	list.print(temp);
    	cout << endl;
		list.separate();
}
