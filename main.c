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

void distanceMenu() {
    int choice;

    while(1) {

        printf("\n--- DISTANCE MANAGEMENT ---\n");
        printf("1. Input/Edit distance\n");
        printf("2. Show distance table\n");
        printf("3. Back to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            inputDistance();
        }
        else if(choice == 2) {
            showDistances();
        }
        else if(choice == 3) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
}

void inputDistance() {
    int from, to, distance;

    if(cityCount < 2) {
        printf("\nYou need at least 2 cities!\n");
        return;
    }

    showCities();

    printf("\nEnter source city number: ");
    scanf("%d", &from);
    printf("Enter destination city number: ");
    scanf("%d", &to);

    if(from < 1 || from > cityCount || to < 1 || to > cityCount) {
        printf("Invalid city numbers!\n");
        return;
    }

    if(from == to) {
        printf("Source and destination cannot be same!\n");
        return;
    }

    printf("Enter distance in km: ");
    scanf("%d", &distance);

    from = from - 1; // Convert to array index
    to = to - 1;

    distances[from][to] = distance;
    distances[to][from] = distance; // Make it symmetric

    printf("Distance set successfully!\n");
}

void showDistances() {
    int i, j;

    if(cityCount == 0) {
        printf("\nNo cities available!\n");
        return;
    }

    printf("\n--- DISTANCE TABLE (km) ---\n");
    printf("%-15s", "");

    for(i = 0; i < cityCount; i++) {
        printf("%-10s", cities[i]);
    }
    printf("\n");

    for(i = 0; i < cityCount; i++) {
        printf("%-15s", cities[i]);
        for(j = 0; j < cityCount; j++) {
            printf("%-10d", distances[i][j]);
        }
        printf("\n");
    }
}

void vehicleMenu() {
    int i;
    char dummy;

    printf("\n--- VEHICLE INFORMATION ---\n");
    printf("%-10s %-15s %-15s %-15s %-15s\n",
           "Type", "Capacity(kg)", "Rate(LKR/km)", "Speed(km/h)", "Efficiency(km/l)");


    for(i = 0; i < 3; i++) {
        printf("%-10s %-15d %-15d %-15d %-15d\n",
               vehicleTypes[i], vehicleCapacity[i], vehicleRate[i],
               vehicleSpeed[i], vehicleEfficiency[i]);
    }

    printf("\nPress Enter to continue...");
    scanf("%c", &dummy);
}

void deliveryMenu() {
    createDelivery();
}


void createDelivery()
 {
    int from, to, weight, vehicleChoice;
    double baseCost, fuelUsed, fCost, tCost, prof, charge, time;

    if(cityCount < 2) {
        printf("\nYou need at least 2 cities!\n");

        return;
    }

    if(deliveryCount >= MAX_DELIVERIES) {
        printf("\nMaximum delivery limit reached!\n");

        return;
    }

    showCities();

    printf("\nEnter source city number: ");
    scanf("%d", &from);
    printf("Enter destination city number: ");
    scanf("%d", &to);

    if(from < 1 || from > cityCount || to < 1 || to > cityCount) {
        printf("Invalid city numbers!\n");

        return;
    }

    if(from == to)
        {
        printf("Source and destination cannot be same!\n");

        return;
    }

    from = from - 1;
    to = to - 1;

    if(distances[from][to] == 0)
        {
        printf("Distance not set between these cities!\n");

        return;
    }


     printf("Enter weight in kg: ");
    scanf("%d", &weight);

    printf("\nSelect vehicle:\n");
    printf("1. Van (Capacity: 1000 kg)\n");
    printf("2. Truck (Capacity: 5000 kg)\n");
    printf("3. Lorry (Capacity: 10000 kg)\n");
    printf("Enter choice: ");
    scanf("%d", &vehicleChoice);

    if(vehicleChoice < 1 || vehicleChoice > 3) {
        printf("Invalid vehicle choice!\n");

        return;
    }

    vehicleChoice = vehicleChoice - 1;

    if(weight > vehicleCapacity[vehicleChoice]) {
        printf("Weight exceeds vehicle capacity!\n");

        return;
    }

    baseCost = distances[from][to] * vehicleRate[vehicleChoice] * (1.0 + (double)weight / 10000.0);

    time = (double)distances[from][to] / vehicleSpeed[vehicleChoice];

    fuelUsed = (double)distances[from][to] / vehicleEfficiency[vehicleChoice];

    fCost = fuelUsed * 310.0;

    tCost = baseCost + fCost;

    prof = tCost * 0.25;

    charge = tCost + prof;


    printf("         DELIVERY COST ESTIMATION\n");

    printf("From: %s\n", cities[from]);

    printf("To: %s\n", cities[to]);

    printf("Distance: %d km\n", distances[from][to]);

    printf("Vehicle: %s\n", vehicleTypes[vehicleChoice]);

    printf("Weight: %d kg\n", weight);

    printf("----------------------------------------------------\n");

    printf("Base Cost: %.2f LKR\n", baseCost);

    printf("Fuel Cost: %.2f LKR\n", fCost);

    printf("Total Cost: %.2f LKR\n", tCost);

    printf("Profit: %.2f LKR\n", prof);

    printf("Customer Charge: %.2f LKR\n", charge);

    printf("Estimated Time: %.2f hours\n", time);



     strcpy(deliverySource[deliveryCount], cities[from]);

    strcpy(deliveryDestination[deliveryCount], cities[to]);

    deliveryDistance[deliveryCount] = distances[from][to];

    deliveryWeight[deliveryCount] = weight;

    strcpy(deliveryVehicle[deliveryCount], vehicleTypes[vehicleChoice]);

    deliveryCost[deliveryCount] = baseCost;

    fuelCost[deliveryCount] = fCost;

    totalCost[deliveryCount] = tCost;

    profit[deliveryCount] = prof;

    customerCharge[deliveryCount] = charge;

    estimatedTime[deliveryCount] = time;

    deliveryCount++;

    printf("\nDelivery saved! Total deliveries: %d\n", deliveryCount);
}

void reportsMenu()
 {
    showReports();
}

void showReports()
{
    int i;
    int totalDistance = 0;

    double totalTime = 0;

    double totalRevenue = 0;

    double totalProfit = 0;

    int minDistance, maxDistance;

    if(deliveryCount == 0) {
        printf("\nNo deliveries yet!\n");

        return;
    }

    minDistance = deliveryDistance[0];
    maxDistance = deliveryDistance[0];

    for(i = 0; i < deliveryCount; i++) {
        totalDistance = totalDistance + deliveryDistance[i];
        totalTime = totalTime + estimatedTime[i];
        totalRevenue = totalRevenue + customerCharge[i];
        totalProfit = totalProfit + profit[i];

        if(deliveryDistance[i] < minDistance) {
            minDistance = deliveryDistance[i];
        }
        if(deliveryDistance[i] > maxDistance) {
            maxDistance = deliveryDistance[i];
        }
    }


    printf("       PERFORMANCE REPORTS\n");

    printf("Total Deliveries: %d\n", deliveryCount);

    printf("Total Distance: %d km\n", totalDistance);

    printf("Average Time: %.2f hours\n", totalTime / deliveryCount);

    printf("Total Revenue: %.2f LKR\n", totalRevenue);

    printf("Total Profit: %.2f LKR\n", totalProfit);

    printf("Shortest Route: %d km\n", minDistance);

    printf("Longest Route: %d km\n", maxDistance);
}




