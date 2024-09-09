#include <iostream>
using namespace std;

int s[10], top = -1, n = 10;

void push (int x) {
    if (top == n) {
        cout << "Stack overflow" << endl;
        return;
    }
    top++;
    s[top] = x;
}

int pop () {
    if (top == -1) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    int x = s[top];
    top--;
    return x;
}

int peek () {
    if (top == -1) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    if (top == n) {
        cout << "Stack overflow" << endl;
        return -1;
    }
    return s[top];
}

int main () {
    push(1);
    push(2);
    push(3);
    cout << peek() << endl;
    pop();
    pop();
    pop();
    cout << peek() << endl;
    return 0;
}
