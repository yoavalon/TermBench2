#include <iostream>
#include <vector>

std::vector<char> tokenize(const std::string& text, std::vector<char> tokens = std::vector<char>()) {
    if (text == "") {
        return tokens;
    } else {
        tokens.push_back(text[0]);
        return tokenize(text.substr(1), tokens);
    }
}

int main() {
    std::vector<char> result = tokenize("hello world");
    for (char c : result) {
        std::cout << c << " ";
    }
    return 0;
}