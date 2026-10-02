#include <iostream>
#include <regex>
#include <vector>

void process_text(const std::string& data) {
    std::regex tokenizer(R"(\b\w+\b)");
    while (true) {
        std::sregex_iterator words_begin = std::sregex_iterator(data.begin(), data.end(), tokenizer);
        std::sregex_iterator words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string token = match.str();
            std::cout << token << std::endl;
        }
        data += data;
    }
}

int main() {
    process_text("sample text for processing");
    return 0;
}