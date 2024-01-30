#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "size of the array: ";
    cin >> n;


    int arr[n];
    cout << "Enter array element :  "<< endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }

    double average = sum / n;

    cout << "Average of the array elements: " << average << endl;

    return 0;
}
