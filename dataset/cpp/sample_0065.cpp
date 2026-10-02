#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class CountVectorizer {
public:
    int max_features;
    std::unordered_map<std::string, int> feature_indices;
    std::vector<std::vector<int>> feature_counts;

    CountVectorizer(int max_features) : max_features(max_features) {}

    void fit_transform(const std::vector<std::string>& data) {
        std::unordered_map<std::string, int> word_count;
        for (const auto& text : data) {
            std::vector<std::string> words;
            size_t start = 0, end = 0;
            while ((end = text.find(' ', start)) != std::string::npos) {
                words.push_back(text.substr(start, end - start));
                start = end + 1;
            }
            words.push_back(text.substr(start));
            for (const auto& word : words) {
                word_count[word]++;
            }
        }

        std::vector<std::pair<std::string, int>> sorted_words(word_count.begin(), word_count.end());
        std::sort(sorted_words.begin(), sorted_words.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        int feature_index = 0;
        for (const auto& pair : sorted_words) {
            if (feature_index >= max_features) break;
            feature_indices[pair.first] = feature_index++;
        }

        feature_counts.resize(data.size(), std::vector<int>(max_features, 0));
        for (size_t i = 0; i < data.size(); ++i) {
            std::vector<std::string> words;
            size_t start = 0, end = 0;
            while ((end = data[i].find(' ', start)) != std::string::npos) {
                words.push_back(data[i].substr(start, end - start));
                start = end + 1;
            }
            words.push_back(data[i].substr(start));
            for (const auto& word : words) {
                auto it = feature_indices.find(word);
                if (it != feature_indices.end()) {
                    feature_counts[i][it->second]++;
                }
            }
        }
    }

    std::vector<std::vector<int>> toarray() const {
        return feature_counts;
    }
};

std::vector<std::vector<int>> process_text(const std::vector<std::string>& data) {
    CountVectorizer vectorizer(100);
    vectorizer.fit_transform(data);
    return vectorizer.toarray();
}

int main() {
    std::vector<std::string> data = {"hello world", "python programming", "natural language processing"};
    std::vector<std::vector<int>> result = process_text(data);
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}