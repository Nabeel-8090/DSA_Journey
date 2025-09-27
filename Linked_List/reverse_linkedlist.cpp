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
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = tail = newNode; 
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void reverse() {
        if(head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if(head == tail) {
            cout << "There is only one node!" << endl;
            return;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void printLL() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {

    LinkedList ll;

    ll.push_back(2);
    ll.push_back(4);
    ll.push_back(6);
    ll.push_back(8);
    ll.push_back(10);

    ll.reverse();

    ll.printLL();

    return 0;
}