#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> parse_document(const std::string& text) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        tokens.push_back(match_str);
    }
    return tokens;
}

std::vector<double> tokenize_and_convert(const std::vector<std::string>& tokens) {
    std::vector<double> float_tokens;
    for (const auto& token : tokens) {
        try {
            double float_token = std::stod(token);
            float_tokens.push_back(float_token);
        } catch (std::invalid_argument&) {
        } catch (std::out_of_range&) {
        }
    }
    return float_tokens;
}

int main() {
    std::string document = "The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.";
    std::vector<std::string> tokens = parse_document(document);
    std::vector<double> float_tokens = tokenize_and_convert(tokens);
    for (const auto& float_token : float_tokens) {
        std::cout << float_token << " ";
    }
    return 0;
}