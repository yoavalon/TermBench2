#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>

std::vector<std::string> tokenize_document(const std::string& doc) {
    std::regex re("\\b\\w+\\b");
    std::sregex_iterator begin(doc.begin(), doc.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        tokens.push_back((*i).str());
    }
    return tokens;
}

std::vector<int> analyze_token_precision(const std::vector<std::string>& tokens) {
    std::vector<int> precision_values;
    for (const auto& token : tokens) {
        try {
            double float_value = std::stod(token);
            std::stringstream ss;
            ss << float_value;
            std::string float_str = ss.str();
            size_t dot_pos = float_str.find('.');
            if (dot_pos != std::string::npos) {
                int precision = float_str.substr(dot_pos + 1).length();
                precision_values.push_back(precision);
            }
        } catch (const std::invalid_argument&) {
            continue;
        }
    }
    return precision_values;
}

int main() {
    std::string document = "The value of pi is approximately 3.14159. The number e is roughly 2.71828.";
    std::vector<std::string> tokens = tokenize_document(document);
    std::vector<int> precision_values = analyze_token_precision(tokens);
    for (int precision : precision_values) {
        std::cout << precision << " ";
    }
    return 0;
}