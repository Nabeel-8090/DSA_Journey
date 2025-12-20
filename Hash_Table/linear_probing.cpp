#include <iostream>
using namespace std;

class HashTable {
    int size;
    int* table;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for(int i=0; i<size; i++) {
            table[i] = -1;
        }
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hash(key);
        int startIndex = index;
        while(table[index] != -1) {
            index = (index + 1) % size;
            if(startIndex == index) {
                cout << "Hash Table Full, cannot insert " << key << endl;
                return;
            }
        }
        table[index] = key;
    }

    void deletion(int key) {
        int index = hash(key);
        int startIndex = index;

        while(true) {
            if(key == table[index]) {
                table[index] = -2;
                cout << "Deleting " << key << " from index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if(index == startIndex) {
                cout << key << " not found in table" << endl;
                return;
            }
        }
    }

    void display() {
        for(int i=0; i<size; i++) {
            cout << i << " : " << table[i] << endl; 
        }
        cout << endl;
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {

    HashTable ht(5);

    ht.insert(55);
    ht.insert(60);
    ht.insert(57);
    ht.insert(58);
    ht.insert(59);

    ht.display();

    ht.deletion(58);
    ht.display();

    
    return 0;
}