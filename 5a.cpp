#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *lptr, *rptr;

        Node (int data) {
            this->data = data;
            this->lptr = this->rptr = nullptr;
        }
};

void pre_order (Node *root) {
    if (!root) return;
    cout << root->data << " ";
    pre_order(root->lptr);
    pre_order(root->rptr);
}

void in_order (Node *root) {
    if (!root) return;
    in_order(root->lptr);
    cout << root->data << " ";
    in_order(root->rptr);
}

void post_order (Node *root) {
    if (!root) return;
    post_order(root->lptr);
    post_order(root->rptr);
    cout << root->data << " ";
}

int main () {
    int a[7] = {4, 3, 7, 2, 8, 10, 1};
    Node *root = nullptr;

    for (int i: a) {
        if (root == nullptr) {
            root = new Node(i);
            continue;
        }
        Node *temp = root, *prev = temp;
        while (temp) {
            if (i < temp->data) {
                prev = temp;
                temp = temp->lptr;
            }
            else if (i > temp->data) {
                prev = temp;
                temp = temp->rptr;
            }
            else break;
        }
        if (i < prev->data) prev->lptr = new Node(i);
        else prev->rptr = new Node(i);
    }

    cout << "Pre Order: ";
    pre_order(root);
    cout << endl;

    cout << "In Order: ";
    in_order(root);
    cout << endl;

    cout << "Post Order: ";
    post_order(root);
    cout << endl;
    
    return 0;
}