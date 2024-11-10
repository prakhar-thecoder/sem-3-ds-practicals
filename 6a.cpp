#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    string phone;
    Node* left;
    Node* right;
    Node(string name, string phone) : name(name), phone(phone), left(nullptr), right(nullptr) {}
};

class PhoneBook {
private:
    Node* root;

    Node* addEntry(Node* node, string name, string phone) {
        if (!node) return new Node(name, phone);
        if (name < node->name) node->left = addEntry(node->left, name, phone);
        else if (name > node->name) node->right = addEntry(node->right, name, phone);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* removeEntry(Node* node, string name) {
        if (!node) return node;
        if (name < node->name) node->left = removeEntry(node->left, name);
        else if (name > node->name) node->right = removeEntry(node->right, name);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->name = temp->name;
            node->phone = temp->phone;
            node->right = removeEntry(node->right, temp->name);
        }
        return node;
    }

    Node* searchEntry(Node* node, string name) {
        if (!node || node->name == name) return node;
        if (name < node->name) return searchEntry(node->left, name);
        return searchEntry(node->right, name);
    }

    void listAscending(Node* node) {
        if (!node) return;
        listAscending(node->left);
        cout << node->name << ": " << node->phone << endl;
        listAscending(node->right);
    }

    void listDescending(Node* node) {
        if (!node) return;
        listDescending(node->right);
        cout << node->name << ": " << node->phone << endl;
        listDescending(node->left);
    }

public:
    PhoneBook() : root(nullptr) {}

    void addEntry(string name, string phone) {
        root = addEntry(root, name, phone);
    }

    void removeEntry(string name) {
        root = removeEntry(root, name);
    }

    void searchEntry(string name) {
        Node* result = searchEntry(root, name);
        if (result) cout << "Found: " << result->name << ": " << result->phone << endl;
        else cout << "Entry not found" << endl;
    }

    void listAscending() {
        listAscending(root);
    }

    void listDescending() {
        listDescending(root);
    }
};

int main() {
    PhoneBook phoneBook;
    phoneBook.addEntry("Alice", "12345");
    phoneBook.addEntry("Bob", "67890");
    phoneBook.addEntry("Charlie", "54321");

    phoneBook.searchEntry("Bob");
    phoneBook.removeEntry("Alice");
    phoneBook.listAscending();
    phoneBook.listDescending();

    return 0;
}
