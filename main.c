#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50


char cities[MAX_CITIES][50];
int cityCount = 0;

int distances[MAX_CITIES][MAX_CITIES];


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


char vehicleTypes[3][20] = {"Van", "Truck", "Lorry"};
int vehicleCapacity[3] = {1000, 5000, 10000};
int vehicleRate[3] = {30, 40, 80};
int vehicleSpeed[3] = {60, 50, 45};
int vehicleEfficiency[3] = {12, 8, 4};


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

    printf("  LOGISTICS MANAGEMENT SYSTEM\n");

    while(1) {
        mainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

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

    printf("           MAIN MENU\n");

    printf("1. City Management\n");
    printf("2. Distance Management\n");
    printf("3. Vehicle Information\n");
    printf("4. Delivery Request\n");
    printf("5. Performance Reports\n");
    printf("6. Exit\n");

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

void addCity() {
    int i;
    char newCity[50];

    if(cityCount >= MAX_CITIES) {
        printf("\nCannot add more cities! Maximum limit is 30.\n");
        return;
    }

    printf("\nEnter city name: ");
    scanf("%s", newCity);


    for(i = 0; i < cityCount; i++) {
        if(strcasecmp(cities[i], newCity) == 0) {
            printf("This city already exists!\n");
            return;
        }
    }


    strcpy(cities[cityCount], newCity);


    for(i = 0; i <= cityCount; i++) {
        distances[cityCount][i] = 0;
        distances[i][cityCount] = 0;
    }

    cityCount++;
    printf("City '%s' added successfully!\n", newCity);
    printf("Total cities: %d\n", cityCount);
}

void removeCity() {
    int i, j, cityNum;

    if(cityCount == 0) {
        printf("\nNo cities to remove!\n");
        return;
    }

    showCities();
    printf("\nEnter city number to remove: ");
    scanf("%d", &cityNum);

    if(cityNum < 1 || cityNum > cityCount) {
        printf("Invalid city number!\n");
        return;
    }

    cityNum = cityNum - 1;

    printf("Removing city '%s'...\n", cities[cityNum]);


    for(i = cityNum; i < cityCount - 1; i++) {
        strcpy(cities[i], cities[i + 1]);


        for(j = 0; j < cityCount; j++) {
            distances[i][j] = distances[i + 1][j];
            distances[j][i] = distances[j][i + 1];
        }
    }

    cityCount--;
    printf("City removed! Total cities: %d\n", cityCount);
}

void renameCity() {

    int cityNum;
    char newName[50];

    if(cityCount == 0) {
        printf("\nNo cities to rename!\n");
        return;
    }

    showCities();
    printf("\nEnter city number to rename: ");
    scanf("%d", &cityNum);

    if(cityNum < 1 || cityNum > cityCount) {
        printf("Invalid city number!\n");
        return;
    }

    cityNum = cityNum - 1;

    printf("Enter new name for '%s': ", cities[cityNum]);
    scanf("%s", newName);

    strcpy(cities[cityNum], newName);
    printf("City renamed successfully!\n");
}

void showCities() {
    int i;

    if(cityCount == 0) {
        printf("\nNo cities available!\n");
        return;
    }

    printf("\n--- LIST OF CITIES ---\n");
    for(i = 0; i < cityCount; i++) {
        printf("%d. %s\n", i + 1, cities[i]);
    }
    printf("Total: %d cities\n", cityCount);
}

