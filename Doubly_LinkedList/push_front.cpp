#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
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

    void printLL() {
        Node* temp = head;
        cout << "NULL <=> ";
        while(temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {

    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);

    dll.printLL();

    return 0;
}