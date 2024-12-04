#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;
struct Player {
    char name[16];
    int numAssists, numGoals;
};
vector<Player> player;
const string filename = "data-1-2.txt";
void readDatabase(const string filename);
void displayPlayer();
void addPlayer();
void removePlayer();
void updatePlayer();
void findBestPlayer();
int main() {
    int choice;
    string filename = "data-1-2.txt";

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readDatabase(filename);
                break;
            case 2:
                displayPlayer();
                break;
            case 3:
                addPlayer();
                break;
            case 4: 
                removePlayer();
                break;
            case 5: 
                updatePlayer();
                break;
            case 6: 
                findBestPlayer();
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
void showMenu() {
    cout << "Car Management System" << endl;
    cout << "1. Read Database" << endl;
    cout << "2. Display Inventory" << endl;
    cout << "3. Add New Car" << endl;
    cout << "4. Sell Car" << endl;
    cout << "5. Remove Car" << endl;
    cout << "4. Exit" << endl;
}
void readDatabase(const string& file){
    ifstream fin(file);
    if (!fin.is_open()){
        cerr << "Can not open file";
        return;
    }
    // bo qua dong dau tien
    string ignoreLine;
    getline(fin, ignoreLine);

    string s1, s2, s3;
    while (getline(fin, s1, ',')){
        Player temp;

        strncpy(temp.name, s1.c_str(), sizeof(temp.name) - 1);
        temp.name[sizeof(temp.name) - 1] = '\0';

        getline(fin, s2, ',');
        temp.numAssists = stoi(s2);

        getline(fin, s3);
        temp.numGoals = stoi(s3);

        player.push_back(temp);
    }
    fin.close();
}

void displayPlayer(){
    cout << setw(20) << left << "Name" 
         << setw(20) << left << "Number of assists"
         << setw(15) << right << "Number of goals" << endl;
    for (auto &p : player){
        cout << setw(20) << left << p.name
             << setw(20) << left << p.numAssists
             << setw(15) << right << p.numGoals << endl;
    }
}

void addPlayer(){
    Player temp;
    string namePlayer;

    cout << "Name of player: ";
    getline(cin, namePlayer);
    strncpy(temp.name, namePlayer.c_str(), sizeof(temp.name) - 1);
    temp.name[sizeof(temp.name) - 1] = '\0';

    cout << "Number of assists: ";
    // cin >> temp.numAssists;

    cout << "Number of goals: ";
    cin >> temp.numGoals;
    player.push_back(temp);

    ofstream fout(filename, ios::app);
    if (!fout.is_open()){
        cerr << "Can not open file";
        return;
    }
    fout << endl << player.back().name << ", " 
         << player.back().numAssists   << ", "
         << player.back().numGoals << endl;
    fout.close();
}

void removePlayer(){
    string str;
    cout << "Enter your player you want remove: ";
    getline(cin, str);

    bool found = false;
    for (auto it = player.begin(); it != player.end(); ++it){
        if (string(it->name) == str){
            player.erase(it);
            found = true;
            cout << "Player " << str << " has been removed\n";
            break;
        }
    }
    if (!found){
        cout << "Player " << str << " not found in the list\n";
        return;
    }
    
    ofstream fout(filename);
    if (!fout.is_open()){
        cerr << "Can not open file";
        return;
    }
    for (const auto &p : player)
    {
        fout << p.name << ", " << p.numAssists << ", " << p.numGoals << endl;
    }
    fout.close();
}
