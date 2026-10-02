#include <iostream>
#include <vector>
#include <string>

void parse_doc(const std::vector<std::string>& x, size_t index) {
    if (index < x.size()) {
        std::string token = x[index];
        std::cout << token << std::endl;
        parse_doc(x, index + 1);
    } else {
        parse_doc(x, 0);
    }
}

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> words;
    size_t start = 0;
    size_t end = text.find(' ');
    while (end != std::string::npos) {
        words.push_back(text.substr(start, end - start));
        start = end + 1;
        end = text.find(' ', start);
    }
    words.push_back(text.substr(start));
    return words;
}

int main() {
    std::string input = "This is a non-terminating recursion example";
    std::vector<std::string> words = tokenize(input);
    parse_doc(words, 0);
    return 0;
}