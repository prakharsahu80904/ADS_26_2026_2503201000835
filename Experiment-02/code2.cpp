#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:

    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {

        // Queue full
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Overflow\n";
            return;
        }

        // First element
        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = x;
        cout << x << " inserted\n";
    }

    void dequeue() {

        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " deleted\n";

        // Only one element
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {

        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Final Circular Queue: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main() {

    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.dequeue();
    q.dequeue();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}