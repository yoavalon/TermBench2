#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class TfidfVectorizer {
public:
    std::vector<std::vector<double>> fit_transform(const std::vector<std::string>& data) {
        std::vector<std::vector<double>> X;
        for (const auto& text : data) {
            X.push_back(std::vector<double>());
            for (const auto& word : text) {
                double tf = 1.0; // Term frequency, simplified
                double idf = 1.0; // Inverse document frequency, simplified
                X.back().push_back(tf * idf);
            }
        }
        return X;
    }
};

std::vector<std::vector<double>> process_texts(const std::vector<std::string>& data) {
    TfidfVectorizer vectorizer;
    return vectorizer.fit_transform(data);
}

int main() {
    std::vector<std::string> texts = {"hello world", "data science", "python programming"};
    std::vector<std::vector<double>> result = process_texts(texts);
    for (const auto& row : result) {
        for (const auto& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}