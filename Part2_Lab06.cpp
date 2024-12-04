#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

inline void eatLine() {
    while (cin.get() != '\n') {
        continue;
    }
}

struct Car {
    char carMake[16];
    char carModel[16];
    int yearModel, quantity;
    double cost;
};
vector<Car> cars;

void readDatabase(const char* file) {
    ifstream fin(file, ios::in | ios::binary);
    if (!fin) {
        cerr << "Cannot open file\n";
        return;
    }
    cars.clear();
    Car temp;
    while (fin.read((char*)&temp, sizeof(temp))) {
        cars.push_back(temp);
    }
    fin.close();
}

void display(const char* file) {
    if (cars.empty()) {
        cout << "No data available. Please read database first.\n";
        return;
    }
    cout << setw(15) << left << "Make" 
         << setw(10) << left << "Model"
         << setw(10) << right << "Year"
         << setw(10) << right << "Cost"
         << setw(10) << right  << "Quantity" << endl;
    cout << "-----------------------------------------------------"<< endl;
    for (const auto& car : cars) {
        cout << setw(15) << left << car.carMake
             << setw(10) << left << car.carModel
             << setw(10) << right << car.yearModel
             << setw(10) << right << car.cost
             << setw(10) << right << car.quantity << endl;
    }
}

void addCar(const char* file) {
    ofstream fout(file, ios::out | ios::app | ios::binary);
    if (!fout) {
        cerr << "Cannot open file\n";
        return;
    }
    Car temp;
    cout << "Enter car make (empty to stop): ";
    cin.get(temp.carMake, 16);
    while (temp.carMake[0] != '\0') {
        eatLine();
        cout << "Model: ";
        cin.get(temp.carModel, 16);
        eatLine();
        cout << "Year: ";
        cin >> temp.yearModel;
        cout << "Quantity: ";
        cin >> temp.quantity;
        cout << "Cost: ";
        cin >> temp.cost;
        eatLine();
        fout.write((char*)&temp, sizeof(temp));
        cout << "Enter car make (empty to stop): ";
        cin.get(temp.carMake, 16);
    }
    fout.close();
    readDatabase(file);
}

void sellCar(const char* file) {
    cout << "Make: ";
    char make[16], model[16];
    cin.get(make, 16);
    eatLine();
    cout << "Model: ";
    cin.get(model, 16);
    eatLine();
    cout << "Quantity: ";
    int qty;
    cin >> qty;
    if (qty <= 0) {
        cout << "Invalid quantity!\n";
        return;
    }
    bool found = false;
    for (auto& car : cars) {
        if (strcmp(car.carMake, make) == 0 && strcmp(car.carModel, model) == 0) {
            found = true;
            if (car.quantity < qty) {
                cout << "Insufficient quantity\n";
                return;
            }
            car.quantity -= qty;
            break;
        }
    }
    if (!found) {
        cout << "Car not found\n";
        return;
    }
    ofstream fout(file, ios::trunc | ios::binary);
    for (const auto& car : cars) {
        fout.write((char*)&car, sizeof(car));
    }
    fout.close();
}

void showMenu() {
    cout << "Car Management System\n";
    cout << "1. Read Database\n";
    cout << "2. Display Inventory\n";
    cout << "3. Add New Car\n";
    cout << "4. Sell Car\n";
    cout << "5. Remove Car\n";
    cout << "6. Exit\n";
}

int main() {
    while (true) {
        int choice;
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        eatLine();
        switch (choice) {
            case 1: readDatabase("data-2-1.bin"); break;
            case 2: display("data-2-1.bin"); break;
            case 3: addCar("data-2-1.bin"); break;
            case 4: sellCar("data-2-1.bin"); break;
            case 5: /* Call removeCar here if implemented */ break;
            case 6: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}
