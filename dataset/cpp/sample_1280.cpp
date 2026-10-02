#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>

std::unordered_map<std::string, int> word_index;
std::vector<std::vector<double>> idf_matrix;
int feature_count = 0;

void build_index(const std::vector<std::string>& texts, int max_features) {
    std::unordered_map<std::string, int> word_count;
    for (const auto& text : texts) {
        std::unordered_map<std::string, bool> seen_words;
        for (const auto& word : text) {
            if (!seen_words[word]) {
                seen_words[word] = true;
                word_count[word]++;
            }
        }
    }

    std::vector<std::pair<std::string, int>> sorted_words(word_count.begin(), word_count.end());
    std::sort(sorted_words.begin(), sorted_words.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    feature_count = std::min(max_features, static_cast<int>(sorted_words.size()));
    for (int i = 0; i < feature_count; ++i) {
        word_index[sorted_words[i].first] = i;
    }
}

std::vector<std::vector<double>> vectorize_texts(const std::vector<std::string>& texts, int max_features) {
    build_index(texts, max_features);
    idf_matrix.resize(feature_count, std::vector<double>(texts.size(), 0.0));

    for (int i = 0; i < texts.size(); ++i) {
        std::unordered_map<std::string, int> term_count;
        for (const auto& word : texts[i]) {
            term_count[word]++;
        }

        for (const auto& word : term_count) {
            if (word_index.find(word.first) != word_index.end()) {
                int index = word_index[word.first];
                double tf = static_cast<double>(word.second) / texts[i].size();
                double idf = std::log(1.0 + texts.size() / (1 + word_count[word.first]));
                idf_matrix[index][i] = tf * idf;
            }
        }
    }

    return idf_matrix;
}

void main() {
    std::vector<std::string> texts = {
        "This is a sample text.",
        "Another example of text data.",
        "Natural language processing is fascinating."
    };
    std::vector<std::vector<double>> vectors = vectorize_texts(texts);
    for (const auto& vec : vectors) {
        for (double val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}