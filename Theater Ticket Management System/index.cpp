#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


const int NUM_ROWS = 5;
const int NUM_COLS = 10;


struct Seat {
    int row;
    int col;
    bool reserved;
};

void displaySeats(const std::vector<std::vector<Seat>>& theater) {
    std::cout << "Available Seats:\n";
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (theater[row][col].reserved) {
                std::cout << "X ";
            } else {
                std::cout << "O ";
            }
        }
        std::cout << "\n";
    }
}

void reserveSeat(std::vector<std::vector<Seat>>& theater, int row, int col) {
    if (theater[row][col].reserved) {
        std::cout << "Seat already reserved.\n";
    } else {
        theater[row][col].reserved = true;
        std::cout << "Seat reserved successfully.\n";
    }
}


void displayTicketSummary(const std::vector<std::vector<Seat>>& theater, int row, int col) {
    if (theater[row][col].reserved) {
        std::cout << "Ticket Summary:\n";
        std::cout << "Seat: Row " << row + 1 << ", Col " << col + 1 << "\n";
        std::cout << "Price: Rs190.00\n";
    } else {
        std::cout << "This seat is not reserved.\n";
    }
}

int main() {
    std::vector<std::vector<Seat>> theater(NUM_ROWS, std::vector<Seat>(NUM_COLS));
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            theater[row][col].row = row;
            theater[row][col].col = col;
            theater[row][col].reserved = false;
        }
    }

    int choice;
    do {
        std::cout << "\n**** Theater Ticket Booking System ****\n";
        std::cout << "1. Display Available Seats\n";
        std::cout << "2. Reserve a Seat\n";
        std::cout << "3. Ticket Summary\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displaySeats(theater);
                break;
            case 2:
                int row, col;
                std::cout << "Enter the row and column of the seat to reserve: ";
                std::cin >> row >> col;
                if (row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS) {
                    reserveSeat(theater, row - 1, col - 1);
                } else {
                    std::cout << "Invalid seat selection.\n";
                }
                break;
            case 3:
                std::cout << "Enter the row and column of the seat for the ticket summary: ";
                std::cin >> row >> col;
                if (row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS) {
                    displayTicketSummary(theater, row - 1, col - 1);
                } else {
                    std::cout << "Invalid seat selection.\n";
                }
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
