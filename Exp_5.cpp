#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Deque {
private:
    int dequeArray[MAX_SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = 0;
    }

    bool isFull() {
        return ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at front." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front = front - 1;
        }

        dequeArray[front] = key;
        cout << "Inserted " << key << " at the front of the deque." << endl;
    }

    void insertRear(int key) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at rear." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }

        dequeArray[rear] = key;
        cout << "Inserted " << key << " at the rear of the deque." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. No element to delete from the front." << endl;
            return;
        }

        cout << "Deleted " << dequeArray[front] << " from the front of the deque." << endl;

        if (front == rear) {
            front = -1;
            rear = 0;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. No element to delete from the rear." << endl;
            return;
        }

        cout << "Deleted " << dequeArray[rear] << " from the rear of the deque." << endl;

        if (front == rear) {
            front = -1;
            rear = 0;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear = rear - 1;
        }
    }

    void displayDeque() {
        if (isEmpty()) {
            cout << "Deque is empty. No elements to display." << endl;
            return;
        }

        cout << "Elements in the deque: ";
        int i = front;
        do {
            cout << dequeArray[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main() {
    Deque deque;

    int choice, element;

    do {
        cout << "\nDeque Simulation" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Display Deque" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at the front: ";
                cin >> element;
                deque.insertFront(element);
                break;
            case 2:
                cout << "Enter element to insert at the rear: ";
                cin >> element;
                deque.insertRear(element);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.displayDeque();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}
