#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

std::vector<std::vector<int>> vectorize_text(const std::string& text) {
    std::istringstream stream(text);
    std::string word;
    std::unordered_map<std::string, int> vocab;
    std::vector<std::vector<int>> vectors;
    int idx = 0;

    while (stream >> word) {
        if (vocab.find(word) == vocab.end()) {
            vocab[word] = idx++;
        }
        vectors.push_back(std::vector<int>(vocab.size(), 0));
    }

    for (size_t i = 0; i < text.size(); ++i) {
        stream >> word;
        vectors[i][vocab[word]] = 1;
    }

    return vectors;
}

std::vector<std::vector<int>> analyze_sequence(const std::vector<std::string>& sequence) {
    std::vector<std::vector<int>> processed;
    for (const auto& item : sequence) {
        if (!item.empty()) {
            processed.insert(processed.end(), vectorize_text(item).begin(), vectorize_text(item).end());
        }
    }
    return processed;
}

void main() {
    std::vector<std::string> data = {"hello world", "data science", "hello universe"};
    std::vector<std::vector<int>> result = analyze_sequence(data);

    for (const auto& vec : result) {
        for (int val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}