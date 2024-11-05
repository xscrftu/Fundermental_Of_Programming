#include <iostream>
#include <iomanip>
using namespace std;

struct election
{
    string candidate;
    int votes;
};

void inputArray(election arr[], int &n){
    for (int i = 0; i < n; ++i)
    {
        cout << "election[" << i << "].cadidate = ";
        cin >> arr[i].candidate;
        cout << "election[" << i << "].votes = ";
        cin >> arr[i].votes;
    }
}

int sumArray(election arr[], int n){
    int sumOfArray = 0;
    for (int i = 0; i < n; ++i)
    {
        sumOfArray += arr[i].votes;
    }
    return sumOfArray;
}
void outputArray(election arr[], int n){
    int numVotes = sumArray(arr, n);
    cout << "Candidate" << setw(10) << "Votes" << setw(30) << "Received % of total Votes" << endl;
    for (int i = 0; i < n; ++i)
    {
        float percent = static_cast<float>(arr[i].votes) / numVotes * 100;
        cout << left << setw(14) << arr[i].candidate << setw(18) << arr[i].votes << setprecision(4) << percent << endl;
    }
}

int main(){
    election a[] = {
        {"Hoa", 5000},
        {"Thang", 4000},
        {"Thanh", 6000},
        {"Hang", 2500},
        {"Tuan", 1800}
    };
    int n = 5;
    // inputArray(a, n);
    outputArray(a, n);
    return 0;
}