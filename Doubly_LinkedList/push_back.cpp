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

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);

    dll.printLL();

    return 0;
}