#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::vector<std::string> process_text(const std::string& data) {
    std::istringstream iss(data);
    std::string word;
    std::vector<std::string> tokens;
    while (iss >> word) {
        if (std::all_of(word.begin(), word.end(), ::isalpha)) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            tokens.push_back(word);
        }
    }
    return tokens;
}

int main() {
    std::string text = "Mathematical sequences are interesting.";
    std::vector<std::string> result = process_text(text);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    return 0;
}