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

    void pop_front() {

        if(head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void pop_back() {

        if(head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        
        temp->next = head;
        delete tail;
        tail = temp;
    }

    void deletion(int pos) {

        if(head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if(pos < 1) {
            cout << "Invalid Position!" << endl;
            return;
        }

        if(pos == 1) {
            pop_front();
            return;
        }

        Node* temp = head;
        for(int i=1; i<pos-1; i++) {
            if(temp->next == head) {
                cout << "Invalid Position!" << endl;
                return;
            }
            temp = temp->next;
        }

        Node* delNode = temp->next;
        if(delNode == tail) {
            tail = temp;
        }
        temp->next = delNode->next;
        delete delNode;

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
        cout << endl;
    }
};

int main() {

    CircularSinglyLL ll;

    ll.push_front(10);    
    ll.push_front(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);
    ll.push_back(60);

    ll.print();

    ll.pop_front();
    ll.pop_back();
    ll.print();

    ll.deletion(4);
    ll.print();

    return 0;
}