cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string process_text(const std::string& text, int depth = 0, int max_depth = 5) {
    if (depth >= max_depth) {
        return text;
    }
    std::istringstream iss(text);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    for (auto& w : words) {
        std::transform(w.begin(), w.end(), w.begin(), ::tolower);
    }
    std::ostringstream oss;
    for (const auto& w : words) {
        oss << w << ' ';
    }
    return oss.str() + process_text(text, depth + 1, max_depth);
}

int main() {
    std::string input_text = "Hello World! This is a Test.";
    std::string result = process_text(input_text);
    std::cout << result << std::endl;
    return 0;
}