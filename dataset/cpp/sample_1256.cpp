#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cmath>

class TfidfVectorizer {
public:
    std::vector<std::vector<double>> fit_transform(const std::vector<std::string>& data) {
        std::vector<std::vector<std::string>> tokenized_data;
        std::vector<std::map<std::string, int>> word_counts;
        std::map<std::string, int> word_freq;

        for (const auto& sentence : data) {
            std::vector<std::string> tokens = tokenize(sentence);
            tokenized_data.push_back(tokens);
            std::map<std::string, int> count;
            for (const auto& word : tokens) {
                count[word]++;
                word_freq[word]++;
            }
            word_counts.push_back(count);
        }

        int n_docs = data.size();
        std::vector<std::vector<double>> matrix(n_docs);

        for (int i = 0; i < n_docs; ++i) {
            matrix[i].resize(tokenized_data[i].size());
            for (int j = 0; j < tokenized_data[i].size(); ++j) {
                const std::string& word = tokenized_data[i][j];
                double idf = std::log((n_docs + 1.0) / (word_freq[word] + 1.0)) + 1.0;
                matrix[i][j] = word_counts[i][word] * idf;
            }
        }

        return matrix;
    }

private:
    std::vector<std::string> tokenize(const std::string& sentence) {
        std::istringstream stream(sentence);
        std::vector<std::string> tokens;
        std::string word;
        while (stream >> word) {
            tokens.push_back(word);
        }
        return tokens;
    }
};

std::vector<std::vector<double>> process_data() {
    std::vector<std::string> data = {"example sentence one", "another example", "yet another one"};
    TfidfVectorizer vectorizer;
    return vectorizer.fit_transform(data);
}

int main() {
    std::vector<std::vector<double>> matrix = process_data();
    for (const auto& row : matrix) {
        for (double value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}