#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <random>
#include <cmath>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& corpus) : corpus(corpus) {
        vocabulary = build_vocabulary();
        inverted_index = create_inverted_index();
    }

    std::unordered_map<std::string, int> build_vocabulary() {
        std::unordered_set<std::string> words;
        for (const auto& document : corpus) {
            std::istringstream iss(document);
            std::string word;
            while (iss >> word) {
                words.insert(word);
            }
        }
        std::unordered_map<std::string, int> vocab;
        int index = 0;
        for (const auto& word : words) {
            vocab[word] = index++;
        }
        return vocab;
    }

    std::unordered_map<std::string, std::vector<int>> create_inverted_index() {
        std::unordered_map<std::string, std::vector<int>> index;
        for (int doc_id = 0; doc_id < corpus.size(); ++doc_id) {
            std::istringstream iss(corpus[doc_id]);
            std::string word;
            while (iss >> word) {
                index[word].push_back(doc_id);
            }
        }
        return index;
    }

    std::vector<double> vectorize_document(const std::string& document) {
        std::vector<double> vector(vocabulary.size(), 0.0);
        std::istringstream iss(document);
        std::string word;
        while (iss >> word) {
            if (vocabulary.find(word) != vocabulary.end()) {
                vector[vocabulary[word]] += 1.0;
            }
        }
        return vector;
    }

private:
    std::vector<std::string> corpus;
    std::unordered_map<std::string, int> vocabulary;
    std::unordered_map<std::string, std::vector<int>> inverted_index;
};

std::vector<std::vector<double>> process_corpus(const std::vector<std::string>& corpus) {
    Vectorizer vectorizer(corpus);
    std::vector<std::vector<double>> vectors;
    for (const auto& doc : corpus) {
        vectors.push_back(vectorizer.vectorize_document(doc));
    }
    return vectors;
}

void analyze_vectors(std::vector<std::vector<double>>& vectors) {
    while (true) {
        for (const auto& vector : vectors) {
            double norm = 0.0;
            for (double val : vector) {
                norm += val * val;
            }
            std::cout << std::sqrt(norm) << std::endl;
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (auto& vector : vectors) {
            for (double& val : vector) {
                val += dis(gen);
            }
        }
    }
}

int main() {
    std::vector<std::string> corpus = {
        "the quick brown fox jumps over the lazy dog",
        "never jump over the lazy dog quickly",
        "foxes are quick and cunning animals"
    };
    std::vector<std::vector<double>> vectors = process_corpus(corpus);
    analyze_vectors(vectors);
    return 0;
}