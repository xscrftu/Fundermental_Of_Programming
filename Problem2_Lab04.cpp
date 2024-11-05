#include <iostream>
using namespace std;
const int MAX = 100;
void input2dArray(int arr[][MAX], int m, int n){
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "arr[" << i << "]" << "[" << j << "] = ";
            cin >> arr[i][j];
        }   
    }   
}

void output2dArray(int arr[][MAX], int m, int n) {
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "arr[" << i << "]" << "[" << j << "] = " << arr[i][j];
        }   
    }   
}
int sumArray(int arr[][MAX], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sum += arr[i][j];
        }   
    }   
    return sum;
}

int sumDiagonal(int arr[][MAX], int m) {
    int sum = 0;
    for (int  i = 0; i < m; ++i)
    {
        sum += arr[i][i] + arr[i][m-i-1];
    }
    return sum - arr[m / 2][m /2];
}

int findMin(int arr[][MAX], int m, int n){
    int min = arr[0][0];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (min > arr[i][j]){
                min = arr[i][j];
            }
        }   
    }   
    return min;
}

int countOccurrences(int arr[][MAX], int m, int n, int x){
    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (x == a[i][j]){
                ++count;
            }
        }   
    }   
    return count;
}
bool checkPrime(int num){
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;   
        }
    }
    return true;
}
int countNumberofPrime(int arr[][MAX], int m, int n){
    int count = 0;
    for (int i = 0; i < m; ++m)
    {
        for (int j = 0; j < n; ++j)
        {
            if (checkPrime(arr[i][j])){
                ++count;
            }
        }   
    }   
    return count;
}
void removeElements(int arr[][MAX], int &m, int &n, int x){
    const int numRow = m, numCol = n;
    bool Row[numRow] = {true};
    bool Col[numCol] = {true};
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (x == arr[i][j]){
                Row[i] = false;
                Col[i] = false;
            }
        }   
    }   
    int k = 0; // new num of row

    for (int  i = 0; i < m; ++i)
    {
        if (Row[i]){
            for (int  j = 0; j < n; ++j)
            {
                arr[k][j] = arr[i][j];
            }
            ++k;
        }
    }
    m = k; // update row

    int h = 0; // new num of col
    for (int  i = 0; i < n; ++i)
    {
        if (Col[i]){
            for (int  j = 0; j < m; ++j)
            {
                arr[j][h] = arr[j][i];
            }
            ++h;
        } 
    }
    n = h;
}


int main(){

    return 0;
}