#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>

std::vector<std::vector<int>> vectorize(const std::string& text) {
    std::set<std::string> vocab;
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        vocab.insert(word);
    }
    int vocab_size = vocab.size();
    std::unordered_map<std::string, int> word_to_index;
    int index = 0;
    for (const auto& w : vocab) {
        word_to_index[w] = index++;
    }
    std::vector<std::vector<int>> vectors(vocab_size, std::vector<int>(vocab_size, 0));
    std::istringstream sentence_stream(text);
    std::string sentence;
    while (std::getline(sentence_stream, sentence, '.')) {
        std::istringstream word_stream(sentence);
        std::vector<std::string> words;
        while (word_stream >> word) {
            words.push_back(word);
        }
        for (size_t i = 0; i < words.size(); ++i) {
            for (size_t j = i + 1; j < words.size(); ++j) {
                vectors[word_to_index[words[i]], word_to_index[words[j]]] += 1;
            }
        }
    }
    return vectors;
}

void process_data(const std::string& data) {
    while (true) {
        std::vector<std::vector<int>> vectors = vectorize(data);
        for (const auto& row : vectors) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::string data = "This is a test. This test is only a test.";
    process_data(data);
    return 0;
}