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

    // void middle() {
    //     Node* temp = head;
    //     int length = 0;
    //     while(temp != NULL) {
    //         length++;
    //         temp = temp->next;
    //     }
    //     int middle = (length/2)+1;
    //     temp = head;
    //     for(int i=0; i<middle-1; i++) {
    //         temp = temp->next;
    //     }
    //     cout << temp->data;
    // }

    void middle() {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle of the list is: " << slow->data << endl;
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
    ll.push_back(12);

    ll.printLL();
    ll.middle();

    return 0;
}