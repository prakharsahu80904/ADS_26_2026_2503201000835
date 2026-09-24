#include <iostream>
using namespace std;

#define SIZE 5

class LinearQueue {
    int arr[SIZE];
    int front, rear;

public:

    LinearQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
        cout << x << " inserted\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front++] << " deleted\n";
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Final Queue: ";

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {

    LinearQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();

    q.enqueue(40);
    q.enqueue(50);

    q.display();

    return 0;
}