#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> tokenize_text(const std::string& text) {
    std::vector<std::string> tokens;
    std::regex re("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), re);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back((*i).str());
    }
    return tokens;
}

void analyze_tokens(std::vector<std::string>& tokens) {
    while (true) {
        for (const auto& token : tokens) {
            if (token.substr(0, 5) == "float") {
                try {
                    float float_value = std::stof(token.substr(5));
                    std::cout << "Parsed float: " << float_value << std::endl;
                } catch (const std::invalid_argument& e) {
                    std::cout << "Invalid float: " << token.substr(5) << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cout << "Invalid float: " << token.substr(5) << std::endl;
                }
            }
        }
        tokens = tokenize_text(" " + std::accumulate(tokens.begin(), tokens.end(), std::string(), [](const std::string& a, const std::string& b) { return a + " " + b; }));
    }
}

int main() {
    std::string text_input = "The document contains float values like float3.14 and floatNaN.";
    std::vector<std::string> tokens = tokenize_text(text_input);
    analyze_tokens(tokens);
    return 0;
}