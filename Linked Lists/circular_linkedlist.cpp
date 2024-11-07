#include<iostream>
using namespace std;

class CircularLinkedList{

private:
    struct Node{
        int data;
        Node* next;
        Node(int data):data(data),next(nullptr){}

    };
    Node *head;
public:
    CircularLinkedList():head(nullptr){}

    bool isEmpty() const{
        return head == nullptr;
    }

    void insertAtBeginning(int data){
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    void insertAtPosition(int data, int position) {
        if (position < 1) {
            cout << "Position should be 1 or greater." << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; ++i) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    int getNodeAtPosition(int position) const {
        if (position < 1 || isEmpty()) {
            cout << "Position out of bounds." << endl;
            return -1;
        }

        Node* temp = head;
        for (int i = 1; i < position && temp->next != head; ++i) {
            temp = temp->next;
        }

        return temp->data;
    }
    bool search(int data) const {
        if (isEmpty()) return false;
        Node* temp = head;
        do {
            if (temp->data == data) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    
    int countNodes() const {
        if (isEmpty()) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    
    void printList() const {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }

    ~CircularLinkedList() {
        if (isEmpty()) return;

        Node* temp = head;
        Node* nextNode;
        do {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
        head = nullptr;
    }

    


};

int main(){
    CircularLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtPosition(15,2);
    list.printList();
}