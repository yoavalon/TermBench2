#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

std::pair<std::vector<std::string>, std::unordered_map<std::string, int>> tokenize(const std::string& text) {
    std::vector<std::string> words;
    std::unordered_map<std::string, int> word_index;
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
        if (word_index.find(word) == word_index.end()) {
            word_index[word] = word_index.size();
        }
    }
    return {words, word_index};
}

std::vector<std::vector<int>> vectorize(const std::vector<std::string>& words, const std::unordered_map<std::string, int>& word_index) {
    int vector_size = word_index.size();
    std::vector<std::vector<int>> vectors(words.size(), std::vector<int>(vector_size, 0));
    for (size_t i = 0; i < words.size(); ++i) {
        vectors[i][word_index.at(words[i])] += 1;
    }
    return vectors;
}

void main() {
    std::string text = "hello world hello";
    auto [words, word_index] = tokenize(text);
    auto vectors = vectorize(words, word_index);
    for (const auto& vector : vectors) {
        for (int val : vector) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}