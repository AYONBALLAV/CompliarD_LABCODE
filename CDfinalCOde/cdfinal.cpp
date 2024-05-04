#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    LITERAL,
    PUNCTUATOR,
    END
};

struct Token {
    TokenType type;
    string value;
};

class Lexer {
private:
    string text;
    size_t pos;
    char current_char;

    void advance() {
        pos++;
        if (pos < text.size()) {
            current_char = text[pos];
        } else {
            current_char = '\0';
        }
    }

    Token parse_identifier() {
        stringstream stream;
        while (isalnum(current_char) || current_char == '_') {
            stream << current_char;
            advance();
        }
        return {TokenType::IDENTIFIER, stream.str()};
    }

    Token parse_literal() {
        stringstream stream;
        while (isdigit(current_char)) {
            stream << current_char;
            advance();
        }
        return {TokenType::LITERAL, stream.str()};
    }

public:
    Lexer(const string& t) : text(t), pos(0), current_char(text[0]) {}

    Token get_next_token() {
        while (current_char != '\0') {
            if (isspace(current_char)) {
                advance();
                continue;
            } else if (isalpha(current_char) || current_char == '_') {
                return parse_identifier();
            } else if (isdigit(current_char)) {
                return parse_literal();
            } else if (current_char == '+' || current_char == '-' || current_char == '*' || current_char == '/') {
                string op(1, current_char);
                advance();
                return {TokenType::OPERATOR, op};
            } else if (current_char == '(' || current_char == ')') {
                string punc(1, current_char);
                advance();
                return {TokenType::PUNCTUATOR, punc};
            } else {
                throw invalid_argument("Invalid character");
            }
        }
        return {TokenType::END, ""};
    }
};

int main() {
    ifstream file("cd.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string input = buffer.str();

    Lexer lexer(input);
    Token token = lexer.get_next_token();

    while (token.type != TokenType::END) {
        cout << "(" << static_cast<int>(token.type) << ", " << token.value << ") ";
        token = lexer.get_next_token();
    }

    return 0;
}
