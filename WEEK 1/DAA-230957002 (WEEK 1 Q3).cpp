//          QUESTION 3(LAB 0)

#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear >= 4) {
            cout << "Queue Overflow" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            arr[++rear] = x;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
        } else {
            front++;
        }
    }

    void displayFront() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.displayFront();
    q.dequeue();
    q.displayFront();

    return 0;
}



