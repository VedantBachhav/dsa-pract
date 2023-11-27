#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 100

class JobQueue {
private:
    string jobs[MAX_SIZE];
    int front, rear;

public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void addJob(const string &job) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more jobs." << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            jobs[++rear] = job;
            cout << "Job '" << job << "' added to the queue." << endl;
        }
    }

    void deleteJob() {
        if (isEmpty()) {
            cout << "Queue is empty. No job to delete." << endl;
        } else {
            string deletedJob = jobs[front++];
            cout << "Job '" << deletedJob << "' deleted from the queue." << endl;
        }
    }

    void displayJobs() {
        if (isEmpty()) {
            cout << "Queue is empty. No jobs to display." << endl;
        } else {
            cout << "Jobs in the queue:" << endl;
            for (int i = front; i <= rear; i++) {
                cout << "'" << jobs[i] << "' ";
            }
            cout << endl;
        }
    }
};

int main() {
    JobQueue jobQueue;

    int choice;
    string jobName;

    do {
        cout << "\nJob Queue Simulation" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name to add: ";
                cin.ignore(); 
                getline(cin, jobName);
                jobQueue.addJob(jobName);
                break;
            case 2:
                jobQueue.deleteJob();
                break;
            case 3:
                jobQueue.displayJobs();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
