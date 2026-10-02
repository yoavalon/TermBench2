#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class Vector {
public:
    std::vector<double> elements;

    Vector(const std::vector<double>& elements) : elements(elements) {}

    double magnitude() const {
        double sum = 0.0;
        for (double x : elements) {
            sum += std::pow(x, 2);
        }
        return std::sqrt(sum);
    }

    void normalize() {
        double mag = magnitude();
        for (size_t i = 0; i < elements.size(); ++i) {
            elements[i] /= mag;
        }
    }
};

double cosine_similarity(const Vector& vec1, const Vector& vec2) {
    if (vec1.elements.size() != vec2.elements.size()) {
        throw std::invalid_argument("Vectors must be of the same length");
    }
    double dot_product = 0.0;
    for (size_t i = 0; i < vec1.elements.size(); ++i) {
        dot_product += vec1.elements[i] * vec2.elements[i];
    }
    return dot_product / (vec1.magnitude() * vec2.magnitude());
}

std::vector<std::tuple<int, int, double>> process_vectors(const std::vector<std::vector<double>>& data) {
    std::vector<Vector> vectors;
    for (const auto& vec : data) {
        vectors.emplace_back(vec);
    }
    std::vector<std::tuple<int, int, double>> results;
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            vectors[i].normalize();
            vectors[j].normalize();
            double similarity = cosine_similarity(vectors[i], vectors[j]);
            results.emplace_back(i, j, similarity);
        }
    }
    return results;
}

void main() {
    std::vector<std::vector<double>> data = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    std::vector<std::tuple<int, int, double>> similarities = process_vectors(data);
    for (const auto& [idx1, idx2, sim] : similarities) {
        std::cout << "Similarity between vector " << idx1 << " and " << idx2 << ": " << sim << std::endl;
    }
}

int main() {
    main();
    return 0;
}