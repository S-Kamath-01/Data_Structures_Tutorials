#include<iostream>
using namespace std;

class LinkedList{

private:
    struct Node{
        int data;
        Node * next;
        Node(int data):data(data),next(nullptr){}
    }*head; 
public:
    LinkedList():head(nullptr){}

    void insertAtHead(int data){
        Node *newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
    }
    void insertAtTail(int data){
        Node *newNode = new Node(data);
        if (head == nullptr){
            head = newNode;
            return;
        }
        Node * temp = head;
        while(temp->next != nullptr){
            temp = temp -> next;
        }
        temp->next = newNode;
    }
    void insertAtPosition(int data, int position){
        if(position<1){
            cout<<"Position should be greater than or equal to one"<<endl;
            return;
        }
        if(position == 1){
            insertAtHead(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *temp = head;
        for(int i = 1;i<position-1 && temp!=nullptr;i++){
            temp = temp->next;
        }
        if (temp == nullptr){
            cout<<"Postion out of bonds"<<endl;
            delete newNode;
            return;
        }
        newNode ->next = temp -> next;
        temp -> next = newNode;
    }
    void deleteByValue(int data){
        if(head == nullptr){
            cout<<"The List is empty"<<endl;
            return;
        }
        if(head->data == data){
            Node* toDelete = head;
            head = head -> next;
            delete toDelete;
            return;
        }
        Node * temp = head;
        while (temp->next!= nullptr && temp->next->data!=data){
            temp = temp->next;

        }
        if(temp->next == nullptr){
            cout<<"Value not found in the list"<<endl;
            return;
        }
        Node *toDelete = temp -> next;
        temp -> next = temp->next->next;
        delete toDelete;
    }

    bool search(int data) const{
        Node * temp = head;
        while(temp != nullptr){
            if(temp->data == data){
                return true;
            }
            temp = temp->next;

        }
        return false;
    }
    bool isEmpty() const{
        return head == nullptr;
    }

    void printList(){
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"nullptr"<<endl;
    }

    int getNodeAtPosition(int position){
        if(position<1){
            cout<<"Invalid position"<<endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 1;temp!= nullptr && i<position;i++){
            temp = temp->next;
        }
        if(temp){
            return temp->data;
        }else{
            return -1;
        }
    }
    int counter()const{
        int count = 0;
        Node *temp = head;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ~LinkedList(){
        Node* temp = head;;
        while(temp != nullptr){
            Node*next = temp ->next;
            delete temp;
            temp = next;
        }
    }
};



int main(){
    LinkedList list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.insertAtTail(50);

    // Print the list
    list.printList();

    // Retrieve and print a node at a specific position
    int position =3;
    int nodeData = list.getNodeAtPosition(position);
    if (nodeData != -1) {
        std::cout << "Node at position " << position << ": " << nodeData << std::endl;
    } else {
        std::cout << "Position " << position << " is out of range." << std::endl;
    }

    // Print the count of the list
    std::cout << "The list has " << list.counter() << " nodes." << std::endl;

    // Check if the list is empty
    if (list.isEmpty()) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }
    return 0;
}