#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<int> process_sequence(const std::string& text) {
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    std::sregex_iterator words_end = std::sregex_iterator();

    std::vector<int> sequence;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string token = match.str();
        if (isdigit(token[0])) {
            sequence.push_back(std::stoi(token));
        }
    }
    return std::vector<int>(sequence.begin(), sequence.begin() + std::min(sequence.size(), 10));
}

int main() {
    std::string data = "The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10.";
    std::vector<int> result = process_sequence(data);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}