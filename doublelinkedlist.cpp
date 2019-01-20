#include <iostream>
using namespace std;
class Node{
    public:
    // Data
    int data;
    // Pointer to the next Node
    Node * next;
    Node * prev;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};

class DLL{
    public:
    Node * head;
    Node*tail;
    DLL(){
        head = NULL;
	tail = NULL;
    }
//using insert
    void insert(int value){
        // Create a new node
        Node * temp = new Node(value);
        // check if empty list
        if(head == NULL){
            head = temp;
        }
        else{
// If not empty list
		tail->next=temp;
		temp->prev=tail;
            }
	tail=temp;
    }
//using display
    void display(){
        Node *current = head;
        Node *last;
        cout << "Print in order : ";
        while(current!=NULL){
            cout <<current->data<< "->";
            // Store the current in last
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;

    }
//using InsertAt
    void InsertAt(int value, int pos){
        //make a new node
	Node *temp = new Node(value);
	int i=1;
	Node *current=head;
	while(i<pos-1){
		current=current->next;
		i++;
	}
	current->next->prev=temp;
	temp->prev=current;
	temp->next=current->next;
	current->next=temp;
    }
//using the DeleteAt
    void DeleteAt(int pos){
	//reach the pos-1
	int i=1;
	Node *current=head;
	while(i<pos-1){
		current=current->next;
		i++;
	}
	//store the address of node
	Node *temp=current->next;
	//condition for rearrangement of pointers
	current->next=current->next->next;
	current->next->prev=current;
	temp->next=NULL;
	temp->prev=NULL;
	delete temp;
}
//using Delete.
    void Del(){
        //reach the last position
	Node *current=head;
	while(current->next->next != NULL){
		current=current->next;
	}
	//store the address of last one
	Node *temp;
	temp = current->next;
	//break the connection
	current->next->prev=NULL;
	current->next=NULL;
	//finally delete
	delete temp;
    }
//using CountItems.
    void CountItems(){
        Node *current=head;
	int i=1;
	while(current->next!=NULL){
		current=current->next;
		i++;
	}
	cout<<"Numbers of items in the double linked list is "<<i<<endl;
    }

};

int main(){
    DLL dll1;
    dll1.insert(2);
    dll1.insert(4);
    dll1.insert(6);
    dll1.insert(8);
    dll1.insert(10);
    dll1.insert(12);
    dll1.insert(14);
    dll1.insert(16);
    dll1.display();
	dll1.CountItems();
	dll1.InsertAt(34,6);
	dll1.display();
	dll1.CountItems();
	dll1.Del();
	dll1.display();
	dll1.CountItems();
	dll1.DeleteAt(3);
	dll1.display();
return 0;
}
