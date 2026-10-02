#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data) {}

    std::vector<std::vector<int>> fit_transform() {
        std::vector<std::vector<int>> count_matrix;
        for (const auto& sentence : data) {
            std::vector<int> counts(26, 0);
            for (char c : sentence) {
                if (std::isalpha(c)) {
                    counts[std::tolower(c) - 'a']++;
                }
            }
            count_matrix.push_back(counts);
        }
        return count_matrix;
    }

private:
    std::vector<std::string> data;
};

class Processor {
public:
    Processor(const std::vector<std::vector<int>>& vectors) : vectors(vectors) {}

    std::vector<std::vector<double>> normalize() {
        std::vector<std::vector<double>> normalized_vectors;
        for (const auto& vector : vectors) {
            double norm = 0.0;
            for (int value : vector) {
                norm += value * value;
            }
            norm = std::sqrt(norm);
            if (norm == 0) {
                norm = 1;
            }
            std::vector<double> normalized_vector;
            for (int value : vector) {
                normalized_vector.push_back(static_cast<double>(value) / norm);
            }
            normalized_vectors.push_back(normalized_vector);
        }
        return normalized_vectors;
    }

    std::vector<std::vector<int>> filter(int threshold) {
        std::vector<std::vector<int>> filtered_vectors;
        for (const auto& vector : vectors) {
            if (std::any_of(vector.begin(), vector.end(), [threshold](int value) { return value > threshold; })) {
                filtered_vectors.push_back(vector);
            }
        }
        return filtered_vectors;
    }

private:
    std::vector<std::vector<int>> vectors;
};

class Analysis {
public:
    Analysis(const std::vector<std::vector<double>>& processed_data) : data(processed_data) {}

    std::pair<std::vector<double>, std::vector<double>> analyze() {
        std::vector<double> mean_vector(26, 0);
        std::vector<double> variance_vector(26, 0);
        for (const auto& vector : data) {
            for (size_t i = 0; i < vector.size(); ++i) {
                mean_vector[i] += vector[i];
                variance_vector[i] += vector[i] * vector[i];
            }
        }
        for (auto& value : mean_vector) {
            value /= data.size();
        }
        for (size_t i = 0; i < variance_vector.size(); ++i) {
            variance_vector[i] = variance_vector[i] / data.size() - mean_vector[i] * mean_vector[i];
        }
        return {mean_vector, variance_vector};
    }

private:
    std::vector<std::vector<double>> data;
};

void main() {
    std::vector<std::string> data = {
        "Natural language processing is fascinating.",
        "Vectorization is a key technique in NLP.",
        "Machine learning models learn from data.",
        "Data preprocessing is crucial for NLP tasks.",
        "Understanding human language is complex."
    };
    Vectorizer vectorizer(data);
    auto vectors = vectorizer.fit_transform();
    Processor processor(vectors);
    auto normalized_data = processor.normalize();
    auto filtered_data = processor.filter(0.1);
    Analysis analysis(filtered_data);
    auto [mean_vector, variance_vector] = analysis.analyze();
    std::cout << "Mean Vector: ";
    for (double value : mean_vector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "Variance Vector: ";
    for (double value : variance_vector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}