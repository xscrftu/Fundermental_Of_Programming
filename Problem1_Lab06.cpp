// #include <iostream>
// #include <vector>
// #include <fstream>
// #include <cstring>
// using namespace std;
// struct Car {
//     char carMake[16];
//     char carModel[16];
//     int yearModel, quantity;
//     double cost;
// };
// int main(){
// //1. Read Database: Read the list of all cars from the file "data-1-1.txt"
//     ifstream fin;
//     fin.open("data-1-1.txt");
//     if (!fin.is_open()) {
//         cerr << "Can not open file";
//         return -1;
//     }
//     string ignore_line = "";
//     getline(fin, ignore_line);
//     vector<Car> car;
//     Car temp;
//     char make[16];
//     char model[16];
//     int ymodel, quan;
//     double co;
//     while (fin >> make >> model >> ymodel >> quan >> co){
//         strcpy(temp.carMake, make);
//         strcpy(temp.carModel, model);
//         temp.yearModel = ymodel;
//         temp.quantity = quan;
//         temp.cost = co;
//         car.push_back(temp);
//     }    
//     fin.close();
//     // Cach nay chac chan hon 
//     // vector<Car> car;
//     // Car temp;
//     // char make[16];
//     // char model[16];
//     // int ymodel, quan;
//     // double co;
//     // while (fin >> make >> model >> ymodel >> quan >> co){
//     //     strncpy(temp.carMake, make, sizeof(temp.carMake) - 1);
//     //     temp.carMake[sizeof(temp.carMake) - 1] = '\0';
//     //     strncpy(temp.carModel, model, sizeof(temp.carModel) - 1);
//     //     temp.carModel[sizeof(temp.carModel) - 1] = '\0';
//     //     temp.yearModel = ymodel;
//     //     temp.quantity = quan;
//     //     temp.cost = co;
//     //     car.push_back(temp);
//     // }    
//     // fin.close();
// //2. Display Inventory: Print a list of all cars.
//     for (const auto& a : car) {
//         cout << a.carMake << "   "
//              << a.carModel << "   "
//              << a.yearModel << "   "
//              << a.cost << "   "
//              << a.quantity << endl;
//     }
// //3. Add a new car.
//     return 0;
// }
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip> 

using namespace std;

struct Car {
    char carMake[16];
    char carModel[16];
    int yearModel;
    double cost;
    int quantity;
};

vector<Car> cars;  // Global vector to store cars

// Function to read the database from the file
void readDatabase(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string header = "";
    getline(file, header);  // Skip the first line (header)

    while (!file.eof()) {
        Car car;
        file >> car.carMake >> car.carModel >> car.yearModel >> car.cost >> car.quantity;
        if (file) {
            cars.push_back(car);  // Add the car to the inventory
        }
    }
    file.close();
}

// Function to display the inventory
void displayInventory() {
    if (cars.empty()) {
        cout << "No cars in inventory." << endl;
        return;
    }

    cout << "Car Inventory:" << endl;
    cout << setw(15) << left << "Make" 
         << setw(10) << left << "Model"
         << setw(10) << right << "Year"
         << setw(10) << right << "Cost"
         << setw(10) << right << "Quantity" << endl;

    for (const auto& car : cars) {
        cout << setw(15) << left << car.carMake 
             << setw(10) << left << car.carModel
             << setw(10) << right << car.yearModel
             << setw(10) << right << fixed << setprecision(2) << car.cost
             << setw(10) << right << car.quantity << endl;
    }
}


// Function to add a new car to the inventory
void addNewCar() {
    Car newCar;

    cout << "Enter car make: ";
    cin >> newCar.carMake;
    cout << "Enter car model: ";
    cin >> newCar.carModel;
    cout << "Enter year model: ";
    cin >> newCar.yearModel;
    cout << "Enter cost: ";
    cin >> newCar.cost;
    cout << "Enter quantity: ";
    cin >> newCar.quantity;

    cars.push_back(newCar);  // Add the new car to the inventory
    ofstream fout;
    fout.open("data-1-1.txt", ios::app);
    if (!fout.is_open()){
        cerr << "Can not open file";
        return;
    }
    fout << endl << newCar.carMake << " " << newCar.carModel << " " << newCar.yearModel << " " << newCar.cost << " " << newCar.quantity;
    fout.close();
    cout << "New car added to inventory!" << endl;
}

// Sell car 
void sellCar() {
    cout << "Enter the car make that you want to buy: ";
    string typecar;
    cin >> typecar;

    bool check = false;
    Car buyCar;

    for (auto& c : cars) {
        string s(c.carMake);  // Chuyển mảng char thành string
        if (s == typecar) {  // Kiểm tra nếu tên xe trùng
            if (c.quantity > 0) {  // Kiểm tra số lượng xe có sẵn
                check = true;
                --c.quantity;  // Giảm số lượng xe
                cout << "Car " << c.carMake << " " << c.carModel << " sold successfully!" << endl;
                break;
            } else {
                cout << "Sorry, the car is out of stock!" << endl;
                check = true;
                break;
            }
        }
    }

    if (!check) {
        cout << "Car not found in the inventory." << endl;        
    }

    // Mở file để ghi lại dữ liệu mới
    ofstream fout;
    fout.open("data-1-1.txt", ios::trunc);
    if (!fout.is_open()){
        cerr << "Can not open";
        return;
    }
    fout << "Make Model Year Cost Quantity\n"; 
    for (const auto& c: cars){
        fout << c.carMake << " " << c.carModel << " " << c.yearModel << " " << c.cost << " " << c.quantity << endl;
    }
    fout.close();
}

void removeCar(){
    cout << "Enter car make to remove: "; 
    string namecar;
    cin >> namecar;
    cin.ignore();
    cout << "Enter car model to remove: ";
    string modelcar;
    getline(cin, modelcar);
    
    bool found = false;
    for (auto it = cars.begin(); it != cars.end(); ++it){
        if (string(it->carMake) == namecar && string(it->carModel) == modelcar){
            cars.erase(it);
            found = true;
            cout << "Car: " << namecar << " " << modelcar << " has removed" << endl;
            break;
        }
    }
    if (!found) {
        cout << "car not found" << endl;
    }
    if (found){
        ofstream fout("data-1-1.txt", ios::trunc);  // Mở file và xóa tất cả nội dung
        if (!fout.is_open()) {
            cerr << "Cannot open the file!" << endl;
            return;
        }

        fout << "Make Model Year Cost Quantity\n";  // Ghi lại tiêu đề vào file

        // Ghi lại toàn bộ xe vào file sau khi xóa
        for (const auto& c : cars) {
            fout << c.carMake << " " << c.carModel << " " << c.yearModel << " " << c.cost << " " << c.quantity << endl;
        }

        fout.close();
    }
}
// Main menu
void showMenu() {
    cout << "Car Management System" << endl;
    cout << "1. Read Database" << endl;
    cout << "2. Display Inventory" << endl;
    cout << "3. Add New Car" << endl;
    cout << "4. Sell Car" << endl;
    cout << "5. Remove Car" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    int choice;
    string filename = "data-1-1.txt";

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readDatabase(filename);
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                addNewCar();
                break;
            case 4: 
                sellCar();
                break;
            case 5: 
                removeCar();
                break;
            case 6:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
