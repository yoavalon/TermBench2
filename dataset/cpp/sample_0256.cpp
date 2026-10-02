#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& corpus) : corpus(corpus), vectorized_data() {
        process_corpus();
    }

    void process_corpus() {
        for (const auto& doc : corpus) {
            vectorize_document(doc);
        }
    }

    void vectorize_document(const std::string& document) {
        std::vector<int> document_vector(vocabulary.size(), 0);
        std::istringstream stream(document);
        std::string word;
        while (stream >> word) {
            if (vocabulary.find(word) != vocabulary.end()) {
                document_vector[vocabulary[word]] += 1;
            }
        }
        vectorized_data.push_back(document_vector);
    }

    std::vector<std::vector<int>> get_vectorized_data() const {
        return vectorized_data;
    }

private:
    std::vector<std::string> corpus;
    std::unordered_map<std::string, int> vocabulary;
    std::vector<std::vector<int>> vectorized_data;
};

class Processor {
public:
    Processor(const Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    double compute_similarity(const std::vector<int>& vector1, const std::vector<int>& vector2) {
        int dot_product = 0;
        double norm1 = 0, norm2 = 0;
        for (size_t i = 0; i < vector1.size(); ++i) {
            dot_product += vector1[i] * vector2[i];
            norm1 += vector1[i] * vector1[i];
            norm2 += vector2[i] * vector2[i];
        }
        return dot_product / (std::sqrt(norm1) * std::sqrt(norm2));
    }

    std::vector<double> analyze_boundaries() {
        std::vector<double> similarities;
        for (size_t i = 0; i < vectorizer.get_vectorized_data().size(); ++i) {
            for (size_t j = i + 1; j < vectorizer.get_vectorized_data().size(); ++j) {
                double similarity = compute_similarity(vectorizer.get_vectorized_data()[i], vectorizer.get_vectorized_data()[j]);
                similarities.push_back(similarity);
            }
        }
        return similarities;
    }

private:
    const Vectorizer& vectorizer;
};

int main() {
    std::vector<std::string> corpus = {"the quick brown fox jumps over the lazy dog", "a quick movement of the enemy will jeopardize five gunboats", "the fifth element will jeopardize humanity"};
    Vectorizer vectorizer(corpus);
    Processor processor(vectorizer);
    std::vector<double> similarities = processor.analyze_boundaries();
    for (double similarity : similarities) {
        std::cout << similarity << " ";
    }
    std::cout << std::endl;
    return 0;
}