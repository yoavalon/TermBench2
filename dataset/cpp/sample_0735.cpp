#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    if (text.empty()) {
        return {};
    }
    std::istringstream iss(text);
    std::string first;
    iss >> first;
    std::string rest((std::istreambuf_iterator<char>(iss)), std::istreambuf_iterator<char>());
    std::vector<std::string> result = {first};
    auto restTokens = tokenize(rest);
    result.insert(result.end(), restTokens.begin(), restTokens.end());
    return result;
}

std::unordered_map<std::string, int> vectorize(const std::vector<std::string>& tokens, std::unordered_map<std::string, int> vec, int index = 0) {
    if (index == tokens.size()) {
        return vec;
    }
    vec[tokens[index]] = vec.find(tokens[index]) != vec.end() ? vec[tokens[index]] + 1 : 1;
    return vectorize(tokens, vec, index + 1);
}

int main() {
    std::string text = "hello world hello";
    std::vector<std::string> tokens = tokenize(text);
    std::unordered_map<std::string, int> vec;
    std::unordered_map<std::string, int> result = vectorize(tokens, vec);
    for (const auto& pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}