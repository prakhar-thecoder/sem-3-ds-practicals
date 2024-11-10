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

int find_index(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

Node* build_tree(int in[], int pre[], int in_start, int in_end, int &pre_index) {
    if (in_start > in_end) return nullptr;

    Node *node = new Node(pre[pre_index++]);

    if (in_start == in_end) return node;

    int in_index = find_index(in, in_start, in_end, node->data);

    node->lptr = build_tree(in, pre, in_start, in_index - 1, pre_index);
    node->rptr = build_tree(in, pre, in_index + 1, in_end, pre_index);

    return node;
}

void in_order(Node *root) {
    if (!root) return;
    in_order(root->lptr);
    cout << root->data << " ";
    in_order(root->rptr);
}

void pre_order(Node *root) {
    if (!root) return;
    cout << root->data << " ";
    pre_order(root->lptr);
    pre_order(root->rptr);
}

void post_order (Node *root) {
    if (!root) return;
    post_order(root->lptr);
    post_order(root->rptr);
    cout << root->data << " ";
}

int main() {
    int in[] = {1, 2, 3, 4, 7, 8, 10};
    int pre[] = {4, 3, 2, 1, 7, 8, 10};
    int n = sizeof(in) / sizeof(in[0]);
    int pre_index = 0;

    Node *root = build_tree(in, pre, 0, n - 1, pre_index);

    cout << "Constructed In Order: ";
    in_order(root);
    cout << endl;

    cout << "Constructed Pre Order: ";
    pre_order(root);
    cout << endl;

    cout << "Constructed Post Order: ";
    post_order(root);
    cout << endl;

    return 0;
}
