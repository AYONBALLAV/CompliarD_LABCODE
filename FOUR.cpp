
#include <iostream>

int main() {
    using namespace std;


    cout << "Enter an identifier: ";
    string userInput;
    cin >> userInput;

    bool isIdentifier = true;

    if (!isalpha(userInput[0]) && userInput[0] != '_') {
        isIdentifier = false;
    }


    for (size_t i = 1; i < userInput.length(); ++i) {
        char ch = userInput[i];
        if (!isalnum(ch) && ch != '_') {
            isIdentifier = false;
            break;
        }
    }

    if (isIdentifier) {
        cout << userInput << " is an identifier." << endl;
    } else {
        cout << userInput << " is not an identifier." << endl;
    }

    return 0;
}
