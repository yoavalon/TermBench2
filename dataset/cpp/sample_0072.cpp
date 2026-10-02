#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> process_text(const std::string& data) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(data.begin(), data.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();
    std::vector<std::string> tokens;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        tokens.push_back((*i).str());
        if (tokens.size() == 10) {
            break;
        }
    }
    return tokens;
}

int main() {
    std::string sample_text = "This is a sample text for tokenization. Let's see how it works.";
    std::vector<std::string> result = process_text(sample_text);
    for (const std::string& token : result) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return 0;
}