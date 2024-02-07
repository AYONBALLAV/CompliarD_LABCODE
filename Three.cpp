
#include <iostream>
#include <string>

int main() {
    using namespace std;

    cout << "Enter a line of code: ";
    string userInput;
    cin >> userInput;

    if (userInput.length() >= 2 && userInput[0] == '/' && userInput[1] == '/') {
        cout << userInput << " is a comment." << endl;
    } else if (userInput.length() >= 4 && userInput[0] == '/' && userInput[1] == '*' &&
               userInput[userInput.length() - 2] == '*' && userInput[userInput.length() - 1] == '/') {
        cout << userInput << " is a comment." << endl;
    } else {
        cout << userInput << " is not a comment." << endl;
    }

    return 0;
}
