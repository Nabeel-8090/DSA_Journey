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
        int i = 0;
        while(table[index] != -1) {
            i++;
            index = (hash(key) + i*i) % size;
            if(i > size) {
                cout << "Hash Table Full, cannot insert " << key << endl;
                return;
            }
        }
        table[index] =  key;
    } 

    void deletion(int key) {
        int index = hash(key);
        int i = 0;
        while(i < size) {
            if(table[index] == key) {
                table[index] = -2;
                cout << "Deleted " << key << " from index " << index << endl;
                return;
            }
            i++;
            index = (hash(key) + i*i) % size;
        }
        cout << key << " not found in table" << endl;
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
    ht.insert(70);
    
    ht.display();

    ht.deletion(70);


    ht.display();

    return 0;
}