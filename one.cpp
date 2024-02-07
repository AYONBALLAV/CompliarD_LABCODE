
#include <iostream>

int main() {
    using namespace std;

    cout << "Enter a value: ";
    string userInput;
    cin >> userInput;

    bool isNumericConstant = true;

    for (size_t i = 0; i < userInput.length(); ++i) {
        char ch = userInput[i];
        if (!isdigit(ch) && ch != '.') {
            isNumericConstant = false;
            break;
        }
    }

    if (isNumericConstant) {
        cout << userInput << " is a numeric constant." << endl;
    } else {
        cout << userInput << " is not a numeric constant." << endl;
    }

    return 0;
}
