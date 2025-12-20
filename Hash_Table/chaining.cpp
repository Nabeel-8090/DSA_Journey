#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int size;
    list<int>* table;

public:
    HashTable(int s) {
        size = s;
        table = new list<int>[size];
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) { // Worst Case TC: O(n) & Average Case TC: O(1)
        int index = hashFunction(key);
        for(int x : table[index]) {
            if(x == key) {
                return true;
            }
        }
        return false;
    }

    void deletion(int key) { // Worst Case TC: O(n) & Average Case TC: O(1)
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void display() {
        for(int i=0; i<size; i++) {
            cout << i << " : ";
            for(int x : table[i]) {
                cout << x << " -> ";
            }
            cout << endl;
        }
    }
};

int main() {

    HashTable ht(5);

    ht.insert(134);
    ht.insert(64);
    ht.insert(55);
    ht.insert(111);
    ht.insert(93);
    ht.insert(2);

    ht.display();

    cout << endl;
    cout << ht.search(134) << endl;
    cout << ht.search(45) << endl;
    cout << endl;

    ht.deletion(2);

    ht.display();

    return 0;
}