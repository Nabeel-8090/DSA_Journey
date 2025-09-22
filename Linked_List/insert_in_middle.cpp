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

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
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

    void insert(int value, int pos) {
        if(pos < 0) {
            cout << "Invalid Postion!" << endl;
            return;
        }

        if(pos == 0) {
            push_front(value);
            return;
        }

        Node* temp = head;
        for(int i=0; i<pos-1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
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

    List L;

    L.push_front(2);
    L.push_front(4);
    L.push_front(6);

    L.push_back(8);

    L.printLL();

    L.insert(10, -1);
    L.printLL();

    return 0;
}