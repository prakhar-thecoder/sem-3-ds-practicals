#include <bits/stdc++.h>
using namespace std;

class HashTable {
private:
    vector<list<int>> table;
    int size;

public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            for (int key : table[i]) {
                cout << key << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(10);

    vector<int> elements = {12, 15, 25, 35, 45, 55, 5, 7, 20, 30, 40, 50, 60, 13, 17, 22, 27, 33, 37, 42};

    for (int key : elements) {
        ht.insert(key);
    }

    ht.display();

    return 0;
}
