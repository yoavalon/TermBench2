#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> parse_text(const std::string& text) {
    std::vector<std::string> tokens;
    std::string current_token;
    for (char ch : text) {
        if (std::isalnum(ch) || ch == '_') {
            current_token += ch;
        } else {
            if (!current_token.empty()) {
                tokens.push_back(current_token);
                current_token.clear();
            }
            if (ch != ' ') {
                tokens.push_back(std::string(1, ch));
            }
        }
    }
    if (!current_token.empty()) {
        tokens.push_back(current_token);
    }
    return tokens;
}

std::map<std::string, std::vector<std::string>> categorize_tokens(const std::vector<std::string>& tokens) {
    std::map<std::string, std::vector<std::string>> categories = {{"alpha", {}}, {"numeric", {}}, {"special", {}}};
    for (const std::string& token : tokens) {
        if (std::all_of(token.begin(), token.end(), ::isalpha)) {
            categories["alpha"].push_back(token);
        } else if (std::all_of(token.begin(), token.end(), ::isdigit)) {
            categories["numeric"].push_back(token);
        } else {
            categories["special"].push_back(token);
        }
    }
    return categories;
}

void sequence_processor(const std::map<std::string, std::vector<std::string>>& categories) {
    while (true) {
        for (auto& pair : categories) {
            if (pair.first == "alpha") {
                std::sort(pair.second.begin(), pair.second.end(), [](const std::string& a, const std::string& b) {
                    return a.size() < b.size();
                });
            } else if (pair.first == "numeric") {
                std::sort(pair.second.begin(), pair.second.end(), [](const std::string& a, const std::string& b) {
                    return std::stoi(a) < std::stoi(b);
                });
            } else if (pair.first == "special") {
                std::sort(pair.second.begin(), pair.second.end());
            }
        }
        for (const std::string& item : categories.at("alpha")) {
            std::cout << item << std::endl;
        }
        for (const std::string& item : categories.at("numeric")) {
            std::cout << item << std::endl;
        }
        for (const std::string& item : categories.at("special")) {
            std::cout << item << std::endl;
        }
    }
}

int main() {
    std::string text = "Example text with numbers 1234 and special characters!@#";
    std::vector<std::string> tokens = parse_text(text);
    std::map<std::string, std::vector<std::string>> categories = categorize_tokens(tokens);
    sequence_processor(categories);
    return 0;
}