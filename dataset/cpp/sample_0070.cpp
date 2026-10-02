#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

class CountVectorizer {
public:
    std::vector<std::vector<int>> fit_transform(const std::vector<std::string>& data) {
        std::unordered_map<std::string, int> feature_index;
        std::vector<std::vector<int>> X;

        for (const auto& text : data) {
            std::unordered_map<std::string, int> word_count;
            std::istringstream stream(text);
            std::string word;
            while (stream >> word) {
                word_count[word]++;
            }

            std::vector<int> row(feature_index.size(), 0);
            for (const auto& pair : word_count) {
                auto it = feature_index.find(pair.first);
                if (it == feature_index.end()) {
                    feature_index[pair.first] = feature_index.size();
                    row.push_back(pair.second);
                } else {
                    row[it->second] = pair.second;
                }
            }
            X.push_back(row);
        }

        return X;
    }
};

std::vector<std::vector<int>> process_text(const std::vector<std::string>& data) {
    CountVectorizer vectorizer;
    return vectorizer.fit_transform(data);
}

int main() {
    std::vector<std::string> data = {"hello world", "goodbye world", "hello goodbye"};
    std::vector<std::vector<int>> result = process_text(data);

    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}