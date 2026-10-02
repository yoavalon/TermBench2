#include <iostream>
#include <string>
#include <map>
#include <sstream>

std::map<std::string, int> vectorize_text(const std::string& text, std::map<std::string, int>* vec = nullptr) {
    if (vec == nullptr) {
        vec = new std::map<std::string, int>();
    }
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        if (vec->find(word) != vec->end()) {
            vec->at(word) += 1;
        } else {
            vec->insert({word, 1});
        }
    }
    return vectorize_text(text, vec);
}

void main() {
    std::string text = "hello world hello";
    std::map<std::string, int> result = vectorize_text(text);
    for (const auto& pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}