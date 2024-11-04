#include <iostream>
#include <iomanip>
using namespace std;

void inputArray(int arr[], int &n){
    for (int i = 0; i < n; ++i)
    {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }
}

void outputArray(int arr[], int n){
    cout << "Element" << setw(13) << "Value";
    for (int i = 0; i < n; ++i)
    {
        cout << setw(7) << i << setw(13) << arr[i];
    }
}

int sumArray(int arr[], int n){
    int sumOfArray = 0;
    for (int i = 0; i < n; ++i)
    {
        sumOfArray += arr[i];
    }
    return sumOfArray;
}

int findMin(int arr[], int n){
    int min = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (min < arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

int findIndexOfX(int arr[], int n, int x){
    int index = 0;
    for (int  i = 0; i < n; ++i)
    {
        if (x == arr[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

int countOccurrences(int arr[], int n, int x){
    int count = 0;
    for (int  i = 0; i < n; ++i)
    {
        if (x == arr[i])
        {
            ++count;
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

int countNumberofPrime(int arr[], int n){
    int count = 0;
    for (int  i = 0; i < n; ++i)
    {
        if (checkPrime(arr[i])){
            ++count;
        }
    }
    return count;
}

int isAscendingOrder(int arr[], int n){
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void removeElements(int arr[], int &n, int x){
    int j = 0;
    for (int  i = 0; i < n; ++i)
    {
        if (arr[i] != x){
            arr[j] = arr[i];
            ++j;
        }
    }
    n = j;
}

void removeElementsFromIndex(int arr[], int &n, int idx, int num_del){
    if (idx < 0 || idx >= n || num_del <=0){
        return;
    }
    int actual_del = min(num_del, n - idx);
    
    for (int  i = idx; i < n - actual_del; ++i)
    {
        arr[i] = arr[i + actual_del];
    }
    n -= actual_del;
}

void concatTwoArrays(int a[], int na, int b[], int nb, int c[], int &nc) {
    
}
void interleaveArrays(int a[], int na, int b[], int nb, int c[], int &nc) {
    nc = na + nb;
    int k = 0;
    for (int  i = 0; i < na && i < nb; ++i)
    {
        c[k++] = a[i];
        c[k++] = b[i];
    }
    if (na < nb) {
        for (int i = na; i < nb; i++) { 
            c[k++] = b[i];
        }
    } else {
        for (int i = nb; i < na; i++) { 
            c[k++] = a[i];
        }
    }
    
    
}

int main(){
    
    return 0;
}