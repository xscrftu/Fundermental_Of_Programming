#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int LIM = 20;
const string file = "diehiendinhnhan.bin";

struct planet {
    char name[LIM];
    double population;
    double g;
};

inline void eatline() {
    while (cin.get() != '\n') {
        continue;
    }
}

int main() {
    planet pl;
    cout << fixed << right;

    // Mở tệp nhị phân với chế độ đọc/ghi
    fstream finout(file, ios::in | ios::out | ios::binary);
    if (!finout.is_open()) {
        cerr << file << " could not be opened -- bye.\n";
        return -1;
    }

    int ct = 0;
    // Đọc và hiển thị dữ liệu từ tệp
    while (finout.read((char*)&pl, sizeof(pl))) {
        cout << ct++ << ": " << setw(LIM) << pl.name << ": "
             << setprecision(0) << setw(12) << pl.population
             << setprecision(2) << setw(6) << pl.g << endl;
    }
    if (finout.eof()) {
        finout.clear();
    } else {
        cerr << "Error in reading " << file << ".\n";
        return -1;
    }

    // Nhập số bản ghi cần thay đổi
    cout << "Enter the record number you wish to change: ";
    long rec;
    cin >> rec;
    eatline();
    if (rec < 0 || rec >= ct) {
        cerr << "Invalid record number.\n";
        return -1;
    }

    // Tìm vị trí bản ghi trong tệp
    int place = rec * sizeof(pl);
    finout.seekg(place);
    if (finout.fail()) {
        cerr << "Error on attempted seek\n";
        return -1;
    }

    // Đọc bản ghi cũ
    finout.read((char*)&pl, sizeof(pl));
    cout << "Your Selection: \n";
    cout << rec << ": " << setw(LIM) << pl.name << ": "
         << setprecision(0) << setw(12) << pl.population
         << setprecision(2) << setw(6) << pl.g << endl;

    if (finout.eof()) {
        finout.clear();
    }

    // Nhập dữ liệu mới
    cout << "Enter planet name: ";
    cin.getline(pl.name, LIM);
    cout << "Enter planetary population: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;

    // Di chuyển con trỏ ghi và ghi đè bản ghi
    finout.seekp(place);
    finout.write((char*)&pl, sizeof(pl));
    if (finout.fail()) {
        cerr << "Error on attempted write\n";
        return -1;
    }

    // Đóng tệp
    finout.close();
    cout << "Record updated successfully.\n";
    return 0;
}
