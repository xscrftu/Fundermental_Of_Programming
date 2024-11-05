#include <iostream>
using namespace std;

void getData(double temps[12][2]);
double averageHigh(double temps[12][2]);
double averageLow(double temps[12][2]);
int indexHighTemp(double temps[12][2]);
int indexLowTemp(double temps[12][2]);

int main() {
    double temps[12][2]; 
    getData(temps);

    double avgHigh = averageHigh(temps);
    double avgLow = averageLow(temps);
    int highIndex = indexHighTemp(temps);
    int lowIndex = indexLowTemp(temps);

    cout << "Average High Temperature: " << avgHigh << "°C" << endl;
    cout << "Average Low Temperature: " << avgLow << "°C" << endl;
    cout << "Highest Temperature: " << temps[highIndex][0] << "°C in Month " << highIndex + 1 << endl;
    cout << "Lowest Temperature: " << temps[lowIndex][1] << "°C in Month " << lowIndex + 1 << endl;

    return 0;
}

void getData(double temps[12][2]) {
    for (int i = 0; i < 12; i++) {
        cout << "Enter the highest temperature for month " << (i + 1) << ": ";
        cin >> temps[i][0]; 
        cout << "Enter the lowest temperature for month " << (i + 1) << ": ";
        cin >> temps[i][1]; 
    }
}

double averageHigh(double temps[12][2]) {
    double totalHigh = 0;
    for (int i = 0; i < 12; i++) {
        totalHigh += temps[i][0];
    }
    return totalHigh / 12; 
}

double averageLow(double temps[12][2]) {
    double totalLow = 0;
    for (int i = 0; i < 12; i++) {
        totalLow += temps[i][1];
    }
    return totalLow / 12; 
}

int indexHighTemp(double temps[12][2]) {
    int highIndex = 0;
    for (int i = 1; i < 12; i++) {
        if (temps[i][0] > temps[highIndex][0]) {
            highIndex = i; 
        }
    }
    return highIndex; 
}

int indexLowTemp(double temps[12][2]) {
    int lowIndex = 0;
    for (int i = 1; i < 12; i++) {
        if (temps[i][1] < temps[lowIndex][1]) {
            lowIndex = i; 
        }
    }
    return lowIndex; 
}
