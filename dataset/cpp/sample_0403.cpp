#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

class TfidfVectorizer {
public:
    std::unordered_map<std::string, std::unordered_map<std::string, double>> idf;
    std::unordered_map<std::string, int> doc_freq;
    int num_docs;

    TfidfVectorizer() : num_docs(0) {}

    void fit(const std::vector<std::string>& data) {
        for (const auto& doc : data) {
            std::unordered_map<std::string, bool> seen;
            for (const auto& word : split(doc)) {
                if (!seen[word]) {
                    doc_freq[word]++;
                    seen[word] = true;
                }
            }
            num_docs++;
        }
        for (const auto& [word, freq] : doc_freq) {
            idf[word] = std::log((num_docs + 1.0) / (freq + 1.0));
        }
    }

    std::vector<std::vector<double>> transform(const std::vector<std::string>& data) {
        std::vector<std::vector<double>> X;
        for (const auto& doc : data) {
            std::vector<double> row;
            for (const auto& word : split(doc)) {
                row.push_back(idf[word]);
            }
            X.push_back(row);
        }
        return X;
    }

private:
    std::vector<std::string> split(const std::string& str) {
        std::vector<std::string> words;
        std::string word;
        for (char c : str) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        return words;
    }
};

std::vector<std::vector<double>> preprocess_data(const std::vector<std::string>& data) {
    TfidfVectorizer vectorizer;
    vectorizer.fit(data);
    return vectorizer.transform(data);
}

void continuous_processing(const std::vector<std::vector<double>>& X) {
    while (true) {
        for (const auto& row : X) {
            std::vector<double> processed_data;
            for (double value : row) {
                processed_data.push_back(std::log(value + 1));
            }
            for (double value : processed_data) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> data_samples = {"Sample text data", "Another example", "NLP vectorization"};
    auto X = preprocess_data(data_samples);
    continuous_processing(X);
    return 0;
}