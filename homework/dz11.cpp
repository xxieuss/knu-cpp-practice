#include <iostream>
using namespace std;

void read_array(int arr[], int& n) {
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cout << "Enter element " << i + 1 << ": ";
        cin >> a;
        arr[i] = a;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << " " << endl;
}

// 10.
void elementsShift(int arr[], int n){
    if (n <= 1) return;
    int last = arr[n - 1];
    for (int i = n-1; i>0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

// 12.c
int removeElement(int arr[], int n, int x){
    int size = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] != x){
            arr[size] = arr[i];
            size++;
        }
    }
    return size;
}

// 15.
const int MAX_SIZE = 10;
int insertElement(int arr[], int n, int y){
    int newSize = n;
    for (int i = 0; i < n; i++){
        if (arr[i] == y){
            if (newSize < MAX_SIZE){
                for (int m = newSize; m > i; m--){
                    arr[m] = arr[m - 1];
                }
                arr[i + 1] = 42;
                newSize++;
                i++;
            }
        }
    }
    return newSize;
}

int main(){
    int n, arr[10];
    read_array(arr, n);
    print_array(arr, n);
    // 10.
    elementsShift(arr, n);
    cout << "After shifting elements: ";
    print_array(arr, n);
    // 12.c
    int x;
    cout << "Enter element to remove: ";
    cin >> x;
    n = removeElement(arr, n, x);
    cout << "After removing element " << x << ": ";
    print_array(arr, n);
    // 15.
    int y;
    cout << "Enter element after which to insert: ";
    cin >> y;
    n = insertElement(arr, n, y);
    cout << "After inserting element after " << y << ": ";
    print_array(arr, n);
    return 0;
}