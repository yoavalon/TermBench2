#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::vector<int> process_text(const std::string& data) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(data.begin(), data.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();

    std::vector<int> sequences;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string token = match.str();
        if (!token.empty() && std::all_of(token.begin(), token.end(), ::isdigit)) {
            sequences.push_back(std::stoi(token));
        }
    }
    return sequences;
}

int main() {
    std::string text = "The sequence starts at 1, then 2, 3, and so on until 10.";
    std::vector<int> result = process_text(text);
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}