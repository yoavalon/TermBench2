#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

std::vector<std::string> tokenize(const std::string& text) {
    std::regex re("\\b\\w+\\b");
    std::sregex_iterator begin(text.begin(), text.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        tokens.push_back(match.str().to_lower());
    }
    return tokens;
}

std::vector<int> vectorize(const std::vector<std::string>& tokens, const std::unordered_map<std::string, int>& dictionary) {
    std::vector<int> vector(dictionary.size(), 0);
    for (const std::string& token : tokens) {
        if (dictionary.find(token) != dictionary.end()) {
            vector[dictionary.at(token)] += 1;
        }
    }
    return vector;
}

void main() {
    std::string text = "Natural language processing is fascinating";
    std::unordered_map<std::string, int> dictionary = {{"natural", 0}, {"language", 1}, {"processing", 2}, {"is", 3}, {"fascinating", 4}};
    std::vector<std::string> tokens = tokenize(text);
    std::vector<int> vector = vectorize(tokens, dictionary);
    for (int v : vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}