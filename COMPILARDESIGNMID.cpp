#include <iostream>
#include <fstream>
using namespace std;

bool isValidIdentifier(string input) {
    if (input.empty()) {
        return false;
    }
    if (!((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z') 
                   || (input[0] == '_'))) 
   {
        return false;
    }

    for (int i = 1; i < input.length(); ++i) {
        if (!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') 
             || (input[i] == '_'))) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;

    ifstream in("keyword.txt");
    if (!in.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (getline(in, input)) {
        if (isValidIdentifier(input)) {
            cout << "'" << input << "' is a valid identifier" << endl;
        }
        else {
            cout << "'" << input << "' is an invalid identifier" << endl;
        }
    }

    return 0;
}
