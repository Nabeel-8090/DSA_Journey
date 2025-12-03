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

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    ll.print();

    return 0;
}