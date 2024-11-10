#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class MinHeap {
private:
    Node* root;

    void heapify(Node* node) {
        if (!node) return;

        Node* smallest = node;
        if (node->left && node->left->data < smallest->data)
            smallest = node->left;

        if (node->right && node->right->data < smallest->data)
            smallest = node->right;

        if (smallest != node) {
            swap(node->data, smallest->data);
            heapify(smallest);
        }
    }

    void insert(Node*& node, int value) {
        if (!node) {
            node = new Node(value);
            return;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = new Node(value);
                return;
            } else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = new Node(value);
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    MinHeap() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
        heapify(root);
    }

    void heapSort() {
        vector<int> values;
        inorder(root);

        Node* temp = root;
        while (temp) {
            values.push_back(temp->data);
            temp = temp->left;
        }

        sort(values.begin(), values.end());
        
        temp = root;
        for (int value : values) {
            temp->data = value;
            temp = temp->left;
        }
    }

    void print() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    heap.insert(4);
    heap.insert(10);
    heap.insert(3);
    heap.insert(5);
    heap.insert(1);

    heap.heapSort();
    heap.print();
    return 0;
}
