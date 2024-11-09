#include <iostream>
using namespace std;

class TicketQueue {
private:
    int *queue;
    int front, rear, max_size;

public:
    TicketQueue(int size = 5) {
        max_size = size;
        queue = new int[max_size];
        front = -1;
        rear = -1;
    }

    ~TicketQueue() {
        delete[] queue;
    }

    void insert(int ticket_number) {
        if (rear == max_size - 1) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) front = 0; // First element
            rear++;
            queue[rear] = ticket_number;
            cout << "Inserted " << ticket_number << " into the queue" << endl;
        }
    }

    void deleteTicket() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Deleted " << queue[front] << " from the queue" << endl;
            front++;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Tickets in the queue: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TicketQueue ticketQueue;
    int option, ticket_number;

    while (true) {
        cout << "\nSelect an option:" << endl;
        cout << "1. Insert a ticket" << endl;
        cout << "2. Delete a ticket" << endl;
        cout << "3. Display tickets" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter ticket number to insert: ";
                cin >> ticket_number;
                ticketQueue.insert(ticket_number);
                break;

            case 2:
                ticketQueue.deleteTicket();
                break;

            case 3:
                ticketQueue.display();
                break;

            case 4:
                cout << "Exiting the program" << endl;
                return 0;

            default:
                cout << "Invalid option" << endl;
        }
    }

    return 0;
}