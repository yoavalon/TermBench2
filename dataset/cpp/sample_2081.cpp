#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::regex re("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), re);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        tokens.push_back(match_str);
    }
    return tokens;
}

std::vector<std::variant<int, float, std::string>> process_tokens(const std::vector<std::string>& tokens) {
    std::vector<std::variant<int, float, std::string>> processed;
    for (const auto& token : tokens) {
        if (std::regex_match(token, std::regex("\\d+"))) {
            processed.push_back(std::stoi(token));
        } else if (std::regex_match(token, std::regex("\\d+\\.\\d+"))) {
            processed.push_back(std::stof(token));
        } else {
            processed.push_back(token);
        }
    }
    return processed;
}

std::map<std::string, int> analyze_data(const std::vector<std::variant<int, float, std::string>>& data) {
    std::map<std::string, int> stats = {{"integers", 0}, {"floats", 0}, {"words", 0}};
    for (const auto& item : data) {
        if (std::holds_alternative<int>(item)) {
            stats["integers"] += 1;
        } else if (std::holds_alternative<float>(item)) {
            stats["floats"] += 1;
        } else {
            stats["words"] += 1;
        }
    }
    return stats;
}

int main() {
    std::string text = "The value of pi is approximately 3.14159. The number 42 is also interesting.";
    std::vector<std::string> tokens = tokenize(text);
    std::vector<std::variant<int, float, std::string>> processed_data = process_tokens(tokens);
    std::map<std::string, int> analysis = analyze_data(processed_data);
    std::cout << "integers: " << analysis["integers"] << ", floats: " << analysis["floats"] << ", words: " << analysis["words"] << std::endl;
    return 0;
}