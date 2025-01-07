//          QUESTION 2(LAB 0)


#include <iostream>
using namespace std;

class Stack {
    int arr[5];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top >= 4) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = x;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
        } else {
            top--;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.displayTop();
    s.pop();
    s.displayTop();

    return 0;
}

