cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <sstream>

class TfidfVectorizer {
public:
    std::unordered_map<std::string, int> word_freq;
    std::unordered_map<std::string, int> doc_freq;
    int num_docs = 0;

    void fit_transform(const std::vector<std::string>& data) {
        num_docs = data.size();
        for (const auto& doc : data) {
            std::unordered_map<std::string, bool> unique_words;
            std::istringstream stream(doc);
            std::string word;
            while (stream >> word) {
                word_freq[word]++;
                if (!unique_words[word]) {
                    doc_freq[word]++;
                    unique_words[word] = true;
                }
            }
        }
    }

    std::vector<std::vector<double>> transform(const std::vector<std::string>& data) {
        std::vector<std::vector<double>> matrix(data.size(), std::vector<double>(word_freq.size(), 0.0));
        for (size_t i = 0; i < data.size(); ++i) {
            std::unordered_map<std::string, bool> unique_words;
            std::istringstream stream(data[i]);
            std::string word;
            int doc_length = 0;
            while (stream >> word) {
                doc_length++;
                unique_words[word] = true;
            }
            for (const auto& [w, _] : unique_words) {
                matrix[i][word_freq[w]] = (1.0 + std::log(1.0 + std::log(word_freq[w]))) * std::log(num_docs * 1.0 / (doc_freq[w] + 1.0));
            }
        }
        return matrix;
    }
};

std::vector<std::vector<double>> preprocess_texts(const std::vector<std::string>& data) {
    TfidfVectorizer vectorizer;
    vectorizer.fit_transform(data);
    return vectorizer.transform(data);
}

std::vector<double> analyze_data(const std::vector<std::vector<double>>& matrix) {
    std::vector<double> result(matrix.size(), 0.0);
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            result[i] += matrix[i][j];
        }
    }
    return result;
}

void main() {
    std::vector<std::string> texts = {"hello world", "goodbye world", "hello universe"};
    std::vector<std::vector<double>> matrix = preprocess_texts(texts);
    std::vector<double> result = analyze_data(matrix);
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}