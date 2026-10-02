#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

std::vector<std::vector<double>> vectorize_text(const std::string& text) {
    std::unordered_map<std::string, int> word_to_index;
    std::istringstream iss(text);
    std::string word;
    int index = 0;
    while (iss >> word) {
        if (word_to_index.find(word) == word_to_index.end()) {
            word_to_index[word] = index++;
        }
    }
    std::vector<int> indices;
    iss.clear();
    iss.seekg(0);
    while (iss >> word) {
        indices.push_back(word_to_index[word]);
    }
    std::vector<std::vector<double>> result(word_to_index.size(), std::vector<double>(word_to_index.size(), 0.0));
    for (int i : indices) {
        result[i][i] = 1.0;
    }
    return result;
}

void process_text(std::vector<std::string>& data) {
    if (data.empty()) {
        process_text(data);
    } else {
        std::vector<std::vector<double>> vector = vectorize_text(data.front());
        data.erase(data.begin());
        for (const auto& row : vector) {
            for (double val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        process_text(data);
    }
}

int main() {
    std::vector<std::string> text_data = {"hello world", "world is vast", "hello vast world"};
    process_text(text_data);
    return 0;
}