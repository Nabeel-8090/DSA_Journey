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

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = tail = NULL;
    }

    void push_back(int value) {
        Node* newNode =  new Node(value);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if(head == NULL) {
            cout << "Linked List is empty\n" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
    
        delete temp;
    }

    void printll() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp =  temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {

    LinkedList ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    ll.printll();
    
    ll.pop_front();
    ll.printll();

    return 0;
}