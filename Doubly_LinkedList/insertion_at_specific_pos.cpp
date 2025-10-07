#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = next = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int value) {

        Node* newNode = new Node(value);
        
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int value) {

        Node* newNode = new Node(value);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
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
            if(temp->next == NULL) {
                cout << "Invalid Position!" << endl;
                return;
            }
            temp = temp->next;
        }

        if(temp->next == NULL) {
            push_back(value);
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void print() {

        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
        cout << head->data << " " << tail->data << endl;
    }
};

int main() {

    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.push_back(4);
    dll.push_back(5);

    dll.insert(100, 6);

    dll.print();        

    return 0; 
} 