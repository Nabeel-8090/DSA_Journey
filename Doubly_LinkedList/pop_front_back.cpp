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
        head->prev = NULL;
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

        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }  
    
    void deletion(int pos) {

        if(pos < 1) {
            cout << "List is empty!" << endl;
            return;
        }

        if(pos == 1) {
            pop_front();
            return;
        }

        Node* temp = head;
        for(int i=1; i<pos-1 && temp!=NULL; i++) {
            temp = temp->next;
        }

        if(temp == NULL || temp->next == NULL) {
            cout << "Invalid Position!" << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        if(delNode->next != NULL) {
            delNode->next->prev = temp;
        } else {
            tail = temp;
        }
        delete delNode;
    }

    void printLL() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        cout << "Head: " << head->data << " & Tail: " << tail->data << endl;
    }
};

int main() {

    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);

    dll.printLL();

    dll.pop_front();
    dll.printLL();

    dll.pop_back();
    dll.printLL();

    dll.deletion(3);
    dll.printLL();

    return 0;
}