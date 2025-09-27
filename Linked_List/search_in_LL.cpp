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

    void push_front(int value) { // O(1)
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    int search(int key) { // O(n)
        Node* temp = head;
        int index = 0;
        while(temp != NULL) {
            if(temp->data == key) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
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

    List ll;
    ll.push_front(300);
    ll.push_front(500);
    ll.push_front(700);

    ll.printLL();

    int index = ll.search(700);
    if(index >= 0) {
        cout << "Found at index: " << index << endl;
    } else {
        cout << "Not Found!" << endl;
    }
    
    return 0;
}