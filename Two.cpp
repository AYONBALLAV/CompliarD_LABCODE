#include <iostream>


int main() {
    using namespace std;

    cout << "Enter an operator: ";
    string userInput;
    cin >> userInput;

    if (userInput == "+" || userInput == "-" || userInput == "*" || userInput == "/" || userInput == "%") {
        cout << userInput << " is an operator." << endl;
    } else {
        cout << userInput << " is not an operator." << endl;
    }

    return 0;
}
