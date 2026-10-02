#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>

class TfidfVectorizer {
public:
    std::vector<std::vector<double>> fit_transform(const std::vector<std::string>& data) {
        std::vector<std::vector<double>> tfidf_matrix;
        // Placeholder for actual TF-IDF computation
        for (const auto& text : data) {
            tfidf_matrix.push_back({1.0, 2.0, 3.0}); // Example values
        }
        return tfidf_matrix;
    }
};

std::vector<std::vector<double>> preprocess_data(const std::vector<std::string>& data) {
    TfidfVectorizer vectorizer;
    return vectorizer.fit_transform(data);
}

std::pair<std::vector<double>, std::vector<double>> analyze_vectors(const std::vector<std::vector<double>>& vectors) {
    std::vector<double> mean_vector(vectors[0].size(), 0.0);
    std::vector<double> variance_vector(vectors[0].size(), 0.0);

    for (const auto& vector : vectors) {
        for (size_t i = 0; i < vector.size(); ++i) {
            mean_vector[i] += vector[i];
        }
    }
    for (auto& value : mean_vector) {
        value /= vectors.size();
    }

    for (const auto& vector : vectors) {
        for (size_t i = 0; i < vector.size(); ++i) {
            variance_vector[i] += std::pow(vector[i] - mean_vector[i], 2);
        }
    }
    for (auto& value : variance_vector) {
        value /= vectors.size();
    }

    return {mean_vector, variance_vector};
}

void main() {
    std::vector<std::string> data = {"hello world", "data science", "machine learning"};
    auto vectors = preprocess_data(data);
    auto [mean, variance] = analyze_vectors(vectors);

    std::cout << "Mean Vector: ";
    for (auto value : mean) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Variance Vector: ";
    for (auto value : variance) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}