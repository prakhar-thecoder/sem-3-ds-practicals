#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node (int n) {
            this->data = n;
            this->next = nullptr;
        }
        Node (int n, Node *next) {
            this->data = n;
            this->next = next;
        }
};

Node *head;

Node* insert_front (int n) {
    head = new Node(n, head);
    return head;
}

void insert_rear (int n) {
    Node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(n);
}

int delete_front () {
    int n = head->data;
    Node *temp = head;
    head = head->next;
    free(temp);
    return n;
}

int delete_rear () {
    Node *temp = head, *prev = temp;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    int n = temp->data;
    free(temp);
    prev->next = nullptr;
    return n;
}

void display (Node *head) {
    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main () {
    head = new Node(-1);

    cout << "Display: "; display(head);

    insert_front(1);
    insert_rear(2);
    insert_front(3);

    cout << "Display: "; display(head);

    cout << "Delete Front: " << delete_front() << endl;
    cout << "Delete Front: " << delete_front() << endl;

    cout << "Display: "; display(head);

    cout << "Delete Rear: " << delete_rear() << endl;
    cout << "Delete Rear: " << delete_rear() << endl;

    cout << "Display: "; display(head);
    
    return 0;
}