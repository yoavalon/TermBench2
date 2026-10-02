#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class TextProcessor {
public:
    TextProcessor(const std::string& text) : text(text), vector(nullptr) {}

    std::vector<std::string> preprocess() {
        std::vector<std::string> words;
        std::string word;
        for (char ch : text) {
            if (std::isalpha(ch)) {
                word += std::tolower(ch);
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        for (auto& w : words) {
            w.erase(std::remove_if(w.begin(), w.end(), [](unsigned char c) {
                return c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':';
            }), w.end());
        }
        return words;
    }

    std::vector<int> create_vector(const std::vector<std::string>& words) {
        std::set<std::string> unique_words(words.begin(), words.end());
        int vector_size = unique_words.size();
        vector = std::make_unique<std::vector<int>>(vector_size, 0);
        std::unordered_map<std::string, int> word_to_index;
        int index = 0;
        for (const auto& word : unique_words) {
            word_to_index[word] = index++;
        }
        for (const auto& word : words) {
            (*vector)[word_to_index[word]] += 1;
        }
        return *vector;
    }

private:
    std::string text;
    std::unique_ptr<std::vector<int>> vector;
};

class VectorAnalyzer {
public:
    VectorAnalyzer(const std::vector<int>& vector) : vector(vector), normalized_vector(nullptr) {}

    std::vector<double> normalize() {
        double norm = 0.0;
        for (int val : vector) {
            norm += val * val;
        }
        norm = std::sqrt(norm);
        normalized_vector = std::make_unique<std::vector<double>>(vector.size(), 0.0);
        for (size_t i = 0; i < vector.size(); ++i) {
            (*normalized_vector)[i] = vector[i] / norm;
        }
        return *normalized_vector;
    }

    double compare(const VectorAnalyzer& other) {
        double similarity = 0.0;
        for (size_t i = 0; i < vector.size(); ++i) {
            similarity += (*normalized_vector)[i] * (*other.normalized_vector)[i];
        }
        return similarity;
    }

private:
    const std::vector<int>& vector;
    std::unique_ptr<std::vector<double>> normalized_vector;
};

int main() {
    std::string text1 = "Natural language processing is fascinating.";
    std::string text2 = "This field involves analyzing text.";
    TextProcessor processor1(text1);
    std::vector<std::string> words1 = processor1.preprocess();
    std::vector<int> vector1 = processor1.create_vector(words1);
    TextProcessor processor2(text2);
    std::vector<std::string> words2 = processor2.preprocess();
    std::vector<int> vector2 = processor2.create_vector(words2);
    VectorAnalyzer analyzer1(vector1);
    std::vector<double> normalized_vector1 = analyzer1.normalize();
    VectorAnalyzer analyzer2(vector2);
    std::vector<double> normalized_vector2 = analyzer2.normalize();
    double similarity = analyzer1.compare(analyzer2);
    std::cout << "Similarity: " << similarity << std::endl;
    while (true) {
        // Non-terminating loop
    }
    return 0;
}