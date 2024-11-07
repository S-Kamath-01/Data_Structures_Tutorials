#include<iostream>
using namespace std;

class DoublyLinkedList{
private:
    struct Node{
        int data ;
        Node* next;
        Node* prev;

        Node(int data):data(data),next(nullptr),prev(nullptr){}

    };
    Node *head;
public:
    DoublyLinkedList():head(nullptr){}

    bool isEmpty(){
        return head == nullptr;
    }
    void insertAtBeginning(int data ){
        Node * newNode = new Node(data);
        if(head==nullptr){
            head = newNode;

        }
        else{
            newNode ->next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int data){
        Node *newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp ->next = newNode;
        newNode -> prev = temp;

    }
    void insertAtPosition(int data, int position){
        if(position<1){
            cout<<"Position should be greater than 1"<<endl;

        }
        if (position == 1){
            insertAtBeginning(data);
            return;

        }
        Node *newNode = new Node(data);
        Node *temp = head;
        for(int i = 1;i<position-1&&temp!=nullptr;i++){
            temp = temp->next;
        }
        if(temp==nullptr){
            cout<<"Position out of bounds"<<endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        if(temp->next !=nullptr){
            temp->next->prev = newNode;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
    }
    int getNodeAtPosition(int position) const{
        if(position<1){
            cout<<"Position out of bounds"<<endl;
            return -1;
        }
        Node *temp = head ;
        for(int i = 1;i<position && temp!=nullptr;i++){
            temp = temp->next;
        }

        if(temp==nullptr){
            cout<<"Position out of bounds"<<endl;
            return -1;
        }

        return temp ->data;
    }

    bool search(int data){
        Node *temp = head;
        while(temp!=nullptr){
            if(temp->data == data){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int countNodes()const{
        int count = 0;
        Node*temp = head;
        while(temp!=nullptr){
            count++;
            temp = temp->next;

        }
        return count;
    }

    void printList() const{
        Node*temp = head;
        while(temp!= nullptr){
            cout<<temp->data<<"<->";
            temp = temp ->next;
        }
        cout<<"nullptr"<<endl;
    }

    ~DoublyLinkedList(){
        Node *temp =head;
        while(temp!= nullptr){
            Node* next = temp -> next;
            delete temp;
            temp = next;
        }
    }

};
int main(){
    DoublyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtPosition(15,2);
    list.printList();

    cout<<list.getNodeAtPosition(2)<<endl;
    cout<<list.search(15)<<endl;
}