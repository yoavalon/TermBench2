#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::vector<std::string> tokenize(const std::string& document) {
    std::vector<std::string> tokens;
    std::string current_token;
    for (char ch : document) {
        if (std::isalnum(ch) || ch == '\'') {
            current_token += ch;
        } else {
            if (!current_token.empty()) {
                tokens.push_back(current_token);
                current_token.clear();
            }
            if (std::isspace(ch)) {
                continue;
            }
            tokens.push_back(std::string(1, ch));
        }
    }
    if (!current_token.empty()) {
        tokens.push_back(current_token);
    }
    return tokens;
}

std::vector<std::string> parse_tokens(const std::vector<std::string>& tokens) {
    std::vector<std::string> parsed_data;
    std::string current_entry;
    for (const std::string& token : tokens) {
        if (std::isalpha(token[0])) {
            current_entry += token + ' ';
        } else if (std::isdigit(token[0])) {
            current_entry += token + ' ';
        } else if (token == "," || token == ".") {
            if (!current_entry.empty()) {
                parsed_data.push_back(current_entry.substr(0, current_entry.length() - 1));
                current_entry.clear();
            }
            parsed_data.push_back(token);
        } else {
            if (!current_entry.empty()) {
                parsed_data.push_back(current_entry.substr(0, current_entry.length() - 1));
                current_entry.clear();
            }
            parsed_data.push_back(token);
        }
    }
    if (!current_entry.empty()) {
        parsed_data.push_back(current_entry.substr(0, current_entry.length() - 1));
    }
    return parsed_data;
}

void process_data(std::vector<std::string>& data) {
    while (true) {
        std::vector<std::string> processed;
        for (const auto& item : data) {
            if (std::isalpha(item[0])) {
                processed.push_back(item);
            } else {
                processed.push_back(item);
            }
        }
        data = processed;
        for (const auto& item : data) {
            if (std::isalpha(item[0])) {
                std::cout << item << ' ';
            } else {
                std::cout << item << ' ';
            }
        }
        std::cout.flush();
    }
}

int main() {
    std::string document = "This is a sample document, with various tokens and numbers like 1234.";
    std::vector<std::string> tokens = tokenize(document);
    std::vector<std::string> parsed_data = parse_tokens(tokens);
    process_data(parsed_data);
    return 0;
}