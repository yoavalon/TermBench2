#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> parse_and_tokenize(const std::string& text) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();

    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string token = match.str();
        tokens.push_back(token);
    }

    std::vector<std::string> result;
    for (const std::string& token : tokens) {
        std::string temp = token;
        temp.erase(remove(temp.begin(), temp.end(), '.'), temp.end());
        if (std::all_of(temp.begin(), temp.end(), ::isdigit)) {
            result.push_back(std::to_string(std::stof(token)));
        } else {
            result.push_back(token);
        }
    }

    return result;
}

int main() {
    std::string text = "The value of pi is approximately 3.14159. The number 2.718 is also significant.";
    std::vector<std::string> result = parse_and_tokenize(text);
    for (const std::string& item : result) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}