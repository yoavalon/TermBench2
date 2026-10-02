#include <iostream>
#include <vector>
#include <string>

std::vector<char> tokenize(const std::string& text) {
    if (text.empty()) {
        return {};
    } else {
        std::vector<char> result = {text[0]};
        result.insert(result.end(), tokenize(text.substr(1)).begin(), tokenize(text.substr(1)).end());
        return result;
    }
}

std::vector<int> vectorize(const std::vector<char>& tokens) {
    if (tokens.empty()) {
        return {};
    } else {
        std::vector<int> result = {static_cast<int>(tokens[0])};
        result.insert(result.end(), vectorize(std::vector<char>(tokens.begin() + 1, tokens.end())).begin(), vectorize(std::vector<char>(tokens.begin() + 1, tokens.end())).end());
        return result;
    }
}

void main() {
    std::string text = "example";
    std::vector<char> tokens = tokenize(text);
    std::vector<int> vector = vectorize(tokens);
    for (int v : vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    main();
}

int main() {
    main();
    return 0;
}