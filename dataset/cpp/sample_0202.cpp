#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& corpus) : corpus(corpus) {
        tokenized = tokenize();
        vocabulary = build_vocabulary();
        vectorized = vectorize();
    }

    std::vector<std::vector<std::string>> tokenize() {
        std::vector<std::vector<std::string>> tokenized_corpus;
        for (const auto& doc : corpus) {
            std::vector<std::string> tokens;
            std::istringstream stream(doc);
            std::string word;
            while (stream >> word) {
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                tokens.push_back(word);
            }
            tokenized_corpus.push_back(tokens);
        }
        return tokenized_corpus;
    }

    std::unordered_map<std::string, int> build_vocabulary() {
        std::unordered_map<std::string, int> vocab;
        for (const auto& doc : tokenized) {
            for (const auto& word : doc) {
                vocab[word] = 0;
            }
        }
        int index = 0;
        for (auto& pair : vocab) {
            pair.second = index++;
        }
        return vocab;
    }

    std::vector<std::vector<int>> vectorize() {
        std::vector<std::vector<int>> vectors;
        for (const auto& doc : tokenized) {
            std::vector<int> vector(vocabulary.size(), 0);
            for (const auto& word : doc) {
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
    std::vector<std::vector<std::string>> tokenized;
    std::unordered_map<std::string, int> vocabulary;
    std::vector<std::vector<int>> vectorized;
};

std::vector<std::string> load_data() {
    return {"This is a sample document", "Another document for testing", "Sample document number three"};
}

std::pair<std::vector<double>, std::vector<int>> analyze_vectors(const std::vector<std::vector<int>>& vectors) {
    std::vector<double> average_vector(vectors[0].size(), 0.0);
    std::vector<int> max_vector(vectors[0].size(), 0);

    for (const auto& vector : vectors) {
        for (size_t i = 0; i < vector.size(); ++i) {
            average_vector[i] += vector[i];
            if (vector[i] > max_vector[i]) {
                max_vector[i] = vector[i];
            }
        }
    }

    for (auto& value : average_vector) {
        value /= vectors.size();
    }

    return {average_vector, max_vector};
}

int main() {
    auto data = load_data();
    Vectorizer vectorizer(data);
    auto [average, maximum] = analyze_vectors(vectorizer.vectorized);

    std::cout << "Average Vector: ";
    for (const auto& value : average) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Maximum Vector: ";
    for (const auto& value : maximum) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}