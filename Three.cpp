#include <iostream>

using namespace std;

int main() {
    const int maxNameLength = 100; 

    char firstName[maxNameLength];
    char lastName[maxNameLength];
    char fullName[2 * maxNameLength + 1];


    cout << "Enter your first name: ";
    cin >> firstName;

    
    cout << "Enter your last name: ";
    cin >> lastName;

    int i, j;

    
    for (i = 0; firstName[i] != '\0'; ++i) {
        fullName[i] = firstName[i];
    }

    fullName[i] = ' ';
    ++i;

    for (j = 0; lastName[j] != '\0'; ++j, ++i) {
        fullName[i] = lastName[j];
    }

   
    fullName[i] = '\0';

    cout << "Full name: " << fullName << endl;

    return 0;
}
