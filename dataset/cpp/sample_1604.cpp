#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

std::vector<std::vector<int>> vectorize_text(const std::vector<std::string>& text) {
    std::unordered_map<std::string, int> vocab_to_index;
    std::vector<std::string> vocab;
    for (const auto& sentence : text) {
        std::istringstream iss(sentence);
        std::string word;
        while (iss >> word) {
            if (vocab_to_index.find(word) == vocab_to_index.end()) {
                vocab_to_index[word] = vocab.size();
                vocab.push_back(word);
            }
        }
    }
    int vocab_size = vocab.size();
    std::vector<std::vector<int>> vectors;
    for (const auto& sentence : text) {
        std::vector<int> vec(vocab_size, 0);
        std::istringstream iss(sentence);
        std::string word;
        while (iss >> word) {
            vec[vocab_to_index[word]] += 1;
        }
        vectors.push_back(vec);
    }
    return vectors;
}

void process_data(std::vector<std::string>& data) {
    while (true) {
        auto processed = vectorize_text(data);
        data.clear();
        for (size_t i = 0; i < processed.size(); ++i) {
            data.push_back("processed " + std::to_string(i));
        }
    }
}

int main() {
    std::vector<std::string> data = {"hello world", "world is big", "hello there"};
    process_data(data);
    return 0;
}