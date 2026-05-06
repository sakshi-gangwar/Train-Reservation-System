#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Structure for Train
struct Train {
    int trainNo;
    char trainName[50];
    int totalSeats;
    int availableSeats;
};

// Structure for Passenger
struct Passenger {
    int trainNo;
    char name[50];
    int seatNo;
};

// Global arrays
struct Train trains[MAX];
struct Passenger passengers[100];

int trainCount = 0;
int passengerCount = 0;

// Add Train
void addTrain() {
    if (trainCount >= MAX) {
        printf("Train limit reached!\n");
        return;
    }

    printf("Enter Train Number: ");
    scanf("%d", &trains[trainCount].trainNo);

    printf("Enter Train Name: ");
    scanf(" %[^\n]", trains[trainCount].trainName);

    printf("Enter Total Seats: ");
    scanf("%d", &trains[trainCount].totalSeats);

    trains[trainCount].availableSeats = trains[trainCount].totalSeats;

    trainCount++;
    printf("Train added successfully!\n");
}

// Display Trains
void displayTrains() {
    printf("\nAvailable Trains:\n");
    int i;
    for  (i = 0; i < trainCount; i++) {
        printf("Train No: %d | Name: %s | Seats Left: %d\n",
            trains[i].trainNo,
            trains[i].trainName,
            trains[i].availableSeats);
    }
}

// Book Ticket
void bookTicket() {
    int trainNo;
    printf("Enter Train Number: ");
    scanf("%d", &trainNo);
int i;
    for (i = 0; i < trainCount; i++) {
        if (trains[i].trainNo == trainNo) {

            if (trains[i].availableSeats <= 0) {
                printf("No seats available!\n");
                return;
            }

            printf("Enter Passenger Name: ");
            scanf(" %[^\n]", passengers[passengerCount].name);

            passengers[passengerCount].trainNo = trainNo;
            passengers[passengerCount].seatNo =
                trains[i].totalSeats - trains[i].availableSeats + 1;

            trains[i].availableSeats--;
            passengerCount++;

            printf("Ticket booked! Seat No: %d\n",
                passengers[passengerCount - 1].seatNo);
            return;
        }
    }

    printf("Train not found!\n");
}

// Cancel Ticket
void cancelTicket() {
    int seatNo, trainNo;

    printf("Enter Train Number: ");
    scanf("%d", &trainNo);

    printf("Enter Seat Number: ");
    scanf("%d", &seatNo);
      int i;
    for (i = 0; i < passengerCount; i++) {
        if (passengers[i].trainNo == trainNo &&
            passengers[i].seatNo == seatNo) {

            printf("Ticket cancelled for %s\n", passengers[i].name);

            // Shift passengers
            int j;
            for ( j = i; j < passengerCount - 1; j++) {
                passengers[j] = passengers[j + 1];
            }

            passengerCount--;

            // Increase seat
            int k;
            for (k = 0; k < trainCount; k++) {
                if (trains[k].trainNo == trainNo) {
                    trains[k].availableSeats++;
                }
            }

            return;
        }
    }

    printf("Ticket not found!\n");
}

// View Passengers
void viewPassengers() {
    printf("\nPassenger List:\n");
    int i;
    for (i = 0; i < passengerCount; i++) {
        printf("Name: %s | Train No: %d | Seat No: %d\n",
            passengers[i].name,
            passengers[i].trainNo,
            passengers[i].seatNo);
    }
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n--- Train Reservation System ---\n");
        printf("1. Add Train\n");
        printf("2. Display Trains\n");
        printf("3. Book Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. View Passengers\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTrain(); break;
            case 2: displayTrains(); break;
            case 3: bookTicket(); break;
            case 4: cancelTicket(); break;
            case 5: viewPassengers(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
