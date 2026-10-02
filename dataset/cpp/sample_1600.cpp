#include <iostream>
#include <string>
#include <deque>
#include <regex>

void process_data() {
    std::string text = "Sample text for processing. It includes various words and punctuation!";
    std::deque<std::string> queue = {text};
    std::regex word_regex("\\b\\w+\\b");
    while (!queue.empty()) {
        std::string item = queue.front();
        queue.pop_front();
        std::sregex_iterator words_begin = std::sregex_iterator(item.begin(), item.end(), word_regex);
        std::sregex_iterator words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str();
            std::cout << match_str << " ";
        }
        std::cout << std::endl;
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            queue.push_back(match.str());
        }
    }
}

int main() {
    process_data();
    return 0;
}