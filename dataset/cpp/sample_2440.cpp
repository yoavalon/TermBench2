#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<double>> process_text(const std::string& text) {
    std::vector<std::string> words;
    std::string word;
    for (char ch : text) {
        if (ch == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    std::vector<std::vector<double>> vectorizer(words.size(), std::vector<double>(100));
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = 0; j < 100; ++j) {
            vectorizer[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }
    return vectorizer;
}

void main() {
    std::string text = "Example text for processing";
    std::vector<std::vector<double>> vectors = process_text(text);
    for (const auto& vector : vectors) {
        for (double val : vector) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(time(0));
    main();
    return 0;
}