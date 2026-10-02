cpp
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> tokenize(const std::string& sentence, int index = 0, std::vector<std::string> tokens = {}) {
    if (index >= sentence.length() || sentence[index] == ' ') {
        return tokens;
    }
    if (index == 0 || sentence[index - 1] == ' ') {
        int start = index;
        while (index < sentence.length() && sentence[index] != ' ') {
            index += 1;
        }
        tokens.push_back(sentence.substr(start, index - start));
    }
    return tokenize(sentence, index, tokens);
}

int main() {
    std::string sentence = "example sentence for tokenization";
    std::vector<std::string> result = tokenize(sentence);
    for (const auto& token : result) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return 0;
}