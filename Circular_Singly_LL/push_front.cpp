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
    
    void print() {
        Node* temp = head;
        
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(back to head)" << endl;

        cout << tail->next->data << endl;
        cout << "Head: " << head->data << " & Tail: " << tail->data << endl;
    }
};

int main() {

    CircularSinglyLL ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.print();

    return 0;
}