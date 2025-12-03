#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularSinglyLL {
    Node* head;
    Node* tail;

public:
    CircularSinglyLL() {
        head = tail = NULL;
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
    }

    void push_back(int value) {

        Node* newNode = new Node(value);

        if(head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    void insert(int value, int pos) {
        if(pos < 1) {
            cout << "Invalid Position!" << endl;
            return;
        }
        if(pos == 1) {
            push_front(value);
            return;
        }
        Node* temp = head;
        for(int i=1; i<pos-1; i++) {
            temp = temp->next;
        }
        if(temp->next == head) {
            push_back(value);
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void print() {
        Node* temp = head;
        
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(back to head)" << endl;

        cout << "tail->next->data: " << tail->next->data << endl;
        cout << "Head: " << head->data << " & Tail: " << tail->data << endl;
    }
};

int main() {

    CircularSinglyLL ll;

    ll.push_front(10);    
    ll.push_front(20);
    ll.push_front(30);
    // ll.push_front(40);

    // ll.push_back(1);
    // ll.push_back(2);
    // ll.push_back(3);
    // ll.push_back(4);

    ll.print();

    ll.insert(1000, 5);
    ll.print();

    return 0;
}