
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
   int min_value = arr[0];
   int max_value = arr[0];

  for (int i = 1; i < n; ++i) {
    if (arr[i] < min_value) {
      min_value = arr[i];
    }
     else if (arr[i] > max_value) {
      max_value = arr[i];
    }
  }

  cout << "Minimum value: " << min_value << endl;
  cout << "Maximum value: " << max_value << endl;

  return 0;
    }
