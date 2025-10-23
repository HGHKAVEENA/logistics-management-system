#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50

// Global arrays for cities
char cities[MAX_CITIES][50];
int cityCount = 0;

// Global 2D array for distances
int distances[MAX_CITIES][MAX_CITIES];

// Global arrays for deliveries
char deliverySource[MAX_DELIVERIES][50];
char deliveryDestination[MAX_DELIVERIES][50];
int deliveryDistance[MAX_DELIVERIES];
int deliveryWeight[MAX_DELIVERIES];
char deliveryVehicle[MAX_DELIVERIES][20];
double deliveryCost[MAX_DELIVERIES];
double fuelCost[MAX_DELIVERIES];
double totalCost[MAX_DELIVERIES];
double profit[MAX_DELIVERIES];
double customerCharge[MAX_DELIVERIES];
double estimatedTime[MAX_DELIVERIES];
int deliveryCount = 0;

// Vehicle data - simple arrays
char vehicleTypes[3][20] = {"Van", "Truck", "Lorry"};
int vehicleCapacity[3] = {1000, 5000, 10000};
int vehicleRate[3] = {30, 40, 80};
int vehicleSpeed[3] = {60, 50, 45};
int vehicleEfficiency[3] = {12, 8, 4};

// Function declarations
void mainMenu();
void cityMenu();
void distanceMenu();
void vehicleMenu();
void deliveryMenu();
void reportsMenu();
void addCity();
void removeCity();
void renameCity();
void showCities();
void inputDistance();
void showDistances();
void createDelivery();
void showReports();

int main() {
    int choice;

    printf("==========================================\n");
    printf("  LOGISTICS MANAGEMENT SYSTEM\n");
    printf("==========================================\n\n");

    while(1) {
        mainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        if(choice == 1) {
            cityMenu();
        }
        else if(choice == 2) {
            distanceMenu();
        }
        else if(choice == 3) {
            vehicleMenu();
        }
        else if(choice == 4) {
            deliveryMenu();
        }
        else if(choice == 5) {
            reportsMenu();
        }
        else if(choice == 6) {
            printf("\nGoodbye!\n");
            break;
        }
        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

void mainMenu() {
    printf("\n==========================================\n");
    printf("           MAIN MENU\n");
    printf("==========================================\n");
    printf("1. City Management\n");
    printf("2. Distance Management\n");
    printf("3. Vehicle Information\n");
    printf("4. Delivery Request\n");
    printf("5. Performance Reports\n");
    printf("6. Exit\n");
    printf("==========================================\n");
}

void cityMenu() {
    int choice;

    while(1) {
        printf("\n--- CITY MANAGEMENT ---\n");
        printf("1. Add new city\n");
        printf("2. Remove city\n");
        printf("3. Rename city\n");
        printf("4. Show all cities\n");
        printf("5. Back to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if(choice == 1) {
            addCity();
        }
        else if(choice == 2) {
            removeCity();
        }
        else if(choice == 3) {
            renameCity();
        }
        else if(choice == 4) {
            showCities();
        }
        else if(choice == 5) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
}
