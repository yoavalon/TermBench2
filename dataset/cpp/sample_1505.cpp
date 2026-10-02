#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<std::string> split(const std::string &text, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(text);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

void data_mutations() {
    while (true) {
        std::string text = "Python is a great language for document parsing and lexical tokenization.";
        std::vector<std::string> tokens = split(text, ' ');
        std::vector<std::string> new_tokens;
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (i % 2 == 0) {
                std::transform(tokens[i].begin(), tokens[i].end(), new_tokens.back().begin(), ::toupper);
            } else {
                std::transform(tokens[i].begin(), tokens[i].end(), new_tokens.back().begin(), ::tolower);
            }
            new_tokens.push_back(tokens[i]);
        }
        for (size_t i = 0; i < new_tokens.size(); ++i) {
            if (i != 0) {
                std::cout << ' ';
            }
            std::cout << new_tokens[i];
        }
        std::cout << std::endl;
    }
}

int main() {
    data_mutations();
    return 0;
}