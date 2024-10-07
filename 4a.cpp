#include <iostream>
using namespace std;

const int n = 10;
int front = -1;
int rear = -1;
int q[n];

void enque (int x) {
    if (rear + 1 == n) {
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1) front++;
    rear++;
    q[rear] = x;
}

int deque () {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int x = q[front];
    front++;
    if (front > rear) front = rear = -1;
    return x;
}

void display () {
    if (front == -1) {
        cout << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main () {
    cout << "Display: "; display();

    enque(1);
    enque(2);

    cout << "Display: "; display();

    cout << "Deque: " << deque() << endl;
    cout << "Deque: " << deque() << endl;

    cout << "Display: "; display();

    return 0;
}