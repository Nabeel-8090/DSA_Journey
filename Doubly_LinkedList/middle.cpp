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

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
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

    void middle() {
        if(head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if(head == tail) {
            cout << "There is only one element in the list!" << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle of the list is: " << slow->data << endl;
    }

    void print() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {

    DoublyLinkedList dll;

    dll.push_front(1);
    dll.push_front(3);
    dll.push_front(5);

    dll.push_back(7);
    dll.push_back(9);

    dll.print();

    dll.middle();

    return 0;
}