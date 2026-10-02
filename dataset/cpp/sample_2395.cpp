#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cctype>

class TextVectorizor {
public:
    TextVectorizor(const std::vector<std::string>& corpus) : corpus(corpus) {
        tokenized = tokenize();
        vocabulary = build_vocabulary();
        vectorized = vectorize();
    }

    std::vector<std::string> tokenize() {
        std::vector<std::string> tokens;
        for (const auto& text : corpus) {
            std::string lower_text = to_lower(text);
            std::istringstream iss(lower_text);
            std::string word;
            while (iss >> word) {
                tokens.push_back(word);
            }
        }
        return tokens;
    }

    std::unordered_map<std::string, int> build_vocabulary() {
        std::set<std::string> unique_tokens(tokenized.begin(), tokenized.end());
        std::unordered_map<std::string, int> vocabulary;
        int idx = 0;
        for (const auto& word : unique_tokens) {
            vocabulary[word] = idx++;
        }
        return vocabulary;
    }

    std::vector<std::vector<int>> vectorize() {
        std::vector<std::vector<int>> vectors;
        for (const auto& text : corpus) {
            std::string lower_text = to_lower(text);
            std::istringstream iss(lower_text);
            std::string word;
            std::vector<int> vector(vocabulary.size(), 0);
            while (iss >> word) {
                if (vocabulary.find(word) != vocabulary.end()) {
                    vector[vocabulary[word]] += 1;
                }
            }
            vectors.push_back(vector);
        }
        return vectors;
    }

private:
    std::vector<std::string> corpus;
    std::vector<std::string> tokenized;
    std::unordered_map<std::string, int> vocabulary;
    std::vector<std::vector<int>> vectorized;

    std::string to_lower(const std::string& str) {
        std::string lower_str = str;
        std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
        return lower_str;
    }
};

std::vector<std::vector<int>> process_data() {
    std::vector<std::string> corpus = {"The quick brown fox jumps over the lazy dog", "Never jump over the lazy dog quickly", "Quickly brown foxes never jump"};
    TextVectorizor vectorizor(corpus);
    return vectorizor.vectorized;
}

std::vector<int> analyze_vectors(const std::vector<std::vector<int>>& vectors) {
    std::vector<int> analysis;
    for (const auto& vector : vectors) {
        analysis.push_back(std::accumulate(vector.begin(), vector.end(), 0));
    }
    return analysis;
}

int main() {
    std::vector<std::vector<int>> vectors = process_data();
    std::vector<int> analysis = analyze_vectors(vectors);
    while (true) {
        std::vector<std::vector<int>> new_vectors = process_data();
        std::vector<int> new_analysis = analyze_vectors(new_vectors);
        if (analysis != new_analysis) {
            analysis = new_analysis;
            for (int count : analysis) {
                std::cout << count << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}