#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data) {}

    std::vector<double> normalize(const std::vector<double>& vector) {
        double magnitude = 0.0;
        for (double x : vector) {
            magnitude += x * x;
        }
        magnitude = std::sqrt(magnitude);
        if (magnitude == 0.0) {
            return std::vector<double>(vector.size(), 0.0);
        }
        std::vector<double> normalized_vector;
        for (double x : vector) {
            normalized_vector.push_back(x / magnitude);
        }
        return normalized_vector;
    }

    std::vector<std::vector<double>> vectorize() {
        std::vector<std::vector<double>> vectors;
        for (const std::string& item : data) {
            std::vector<double> vector;
            for (char char : item) {
                vector.push_back(static_cast<double>(char) / 1000.0);
            }
            std::vector<double> normalized_vector = normalize(vector);
            vectors.push_back(normalized_vector);
        }
        return vectors;
    }

private:
    std::vector<std::string> data;
};

class Processor {
public:
    Processor(const std::vector<std::vector<double>>& vectors) : vectors(vectors) {}

    double cosine_similarity(const std::vector<double>& vec1, const std::vector<double>& vec2) {
        double dot_product = 0.0;
        for (size_t i = 0; i < vec1.size(); ++i) {
            dot_product += vec1[i] * vec2[i];
        }
        double norm1 = std::sqrt(std::accumulate(vec1.begin(), vec1.end(), 0.0, [](double a, double b) { return a + b * b; }));
        double norm2 = std::sqrt(std::accumulate(vec2.begin(), vec2.end(), 0.0, [](double a, double b) { return a + b * b; }));
        if (norm1 == 0.0 || norm2 == 0.0) {
            return 0.0;
        }
        return dot_product / (norm1 * norm2);
    }

    std::vector<std::tuple<int, int, double>> compare() {
        std::vector<std::tuple<int, int, double>> results;
        for (size_t i = 0; i < vectors.size(); ++i) {
            for (size_t j = i + 1; j < vectors.size(); ++j) {
                double similarity = cosine_similarity(vectors[i], vectors[j]);
                results.emplace_back(i, j, similarity);
            }
        }
        return results;
    }

private:
    std::vector<std::vector<double>> vectors;
};

int main() {
    std::vector<std::string> data = {"hello", "world", "python", "programming"};
    Vectorizer vectorizer(data);
    std::vector<std::vector<double>> vectors = vectorizer.vectorize();
    Processor processor(vectors);
    std::vector<std::tuple<int, int, double>> results = processor.compare();
    for (const auto& result : results) {
        std::cout << "Similarity between item " << std::get<0>(result) << " and " << std::get<1>(result) << ": " << std::fixed << std::setprecision(4) << std::get<2>(result) << std::endl;
    }
    return 0;
}