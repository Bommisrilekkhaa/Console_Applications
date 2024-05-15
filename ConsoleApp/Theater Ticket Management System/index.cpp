#include <bits/stdc++.h>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;


struct Seat {
    int row;
    int col;
    bool reserved;
};

void displaySeats(const vector<vector<Seat>>& theater) {
    cout << "Available Seats:\n";
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (theater[row][col].reserved) {
                cout << "X ";
            } else {
                cout << "O ";
            }
        }
        cout << "\n";
    }
}

void reserveSeat(vector<vector<Seat>>& theater, int row, int col) {
    if (theater[row][col].reserved) {
        cout << "Seat already reserved.\n";
    } else {
        theater[row][col].reserved = true;
        cout << "Seat reserved successfully.\n";
    }
}


void displayTicketSummary(const vector<vector<Seat>>& theater, int row, int col) {
    if (theater[row][col].reserved) {
        cout << "Ticket Summary:\n";
        cout << "Seat: Row " << row + 1 << ", Col " << col + 1 << "\n";
        cout << "Price: Rs190.00\n";
    } else {
        cout << "This seat is not reserved.\n";
    }
}

int main() {
    vector<vector<Seat>> theater(NUM_ROWS, vector<Seat>(NUM_COLS));
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            theater[row][col].row = row;
            theater[row][col].col = col;
            theater[row][col].reserved = false;
        }
    }

    int choice;
    do {
        cout << "\n**** Theater Ticket Booking System ****\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Reserve a Seat\n";
        cout << "3. Ticket Summary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats(theater);
                break;
            case 2:
                int row, col;
                cout << "Enter the row and column of the seat to reserve: ";
                cin >> row >> col;
                if (row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS) {
                    reserveSeat(theater, row - 1, col - 1);
                } else {
                    cout << "Invalid seat selection.\n";
                }
                break;
            case 3:
                cout << "Enter the row and column of the seat for the ticket summary: ";
                cin >> row >> col;
                if (row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS) {
                    displayTicketSummary(theater, row - 1, col - 1);
                } else {
                    cout << "Invalid seat selection.\n";
                }
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
