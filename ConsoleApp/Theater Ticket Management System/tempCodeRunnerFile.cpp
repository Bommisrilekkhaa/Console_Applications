#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to represent a ticket
struct Ticket {
    int ticketId;
    string customerName;
    int seatNumber;
    bool booked;
};

// Function to display the seating arrangement
void displaySeatingArrangement(const vector<Ticket>& tickets) {
    cout << "Seating Arrangement:" << endl;
    for (const auto& ticket : tickets) {
        cout << "Seat " << ticket.seatNumber << ": ";
        if (ticket.booked) {
            cout << "Booked by " << ticket.customerName << endl;
        } else {
            cout << "Available" << endl;
        }
    }
}

// Function to book a ticket
void bookTicket(vector<Ticket>& tickets) {
    int seat;
    string name;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter seat number to book: ";
    cin >> seat;

    // Check if seat is available
    for (auto& ticket : tickets) {
        if (ticket.seatNumber == seat) {
            if (ticket.booked) {
                cout << "Seat " << seat << " is already booked." << endl;
                return;
            } else {
                ticket.booked = true;
                ticket.customerName = name;
                cout << "Seat " << seat << " booked successfully by " << name << "." << endl;
                return;
            }
        }
    }

    cout << "Invalid seat number." << endl;
}

// Admin function to view all bookings
void viewBookings(const vector<Ticket>& tickets) {
    cout << "All Bookings:" << endl;
    for (const auto& ticket : tickets) {
        if (ticket.booked) {
            cout << "Ticket ID: " << ticket.ticketId << " | Seat: " << ticket.seatNumber << " | Booked by: " << ticket.customerName << endl;
        }
    }
}

int main() {
    const int totalSeats = 10;
    vector<Ticket> tickets;

    // Initialize seating arrangement
    for (int i = 1; i <= totalSeats; ++i) {
        Ticket ticket;
        ticket.ticketId = i;
        ticket.seatNumber = i;
        ticket.booked = false;
        tickets.push_back(ticket);
    }

    bool isAdmin = false;
    while (true) {
        cout << "\n------------ Theater Ticket Booking System ------------" << endl;
        cout << "1. View Seating Arrangement" << endl;
        cout << "2. Book Ticket" << endl;
        cout << "3. Admin Panel" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter option: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeatingArrangement(tickets);
                break;
            case 2:
                bookTicket(tickets);
                break;
            case 3:
                if (isAdmin) {
                    viewBookings(tickets);
                } else {
                    string password;
                    cout << "Enter Admin Password: ";
                    cin >> password;
                    if (password == "adminpassword") {
                        isAdmin = true;
                        cout << "Admin Panel Activated." << endl;
                    } else {
                        cout << "Incorrect Password. Access Denied." << endl;
                    }
                }
                break;
            case 4:
                cout << "Exiting... Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
