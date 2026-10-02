#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Vectorizer {
public:
    Vectorizer(int dimension) : dimension(dimension) {}

    std::vector<double> create_random_vector() {
        std::vector<double> vector(dimension);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < dimension; ++i) {
            vector[i] = dis(gen);
        }
        return vector;
    }

    std::vector<double> normalize_vector(const std::vector<double>& vector) {
        double norm = 0.0;
        for (double val : vector) {
            norm += val * val;
        }
        norm = std::sqrt(norm);
        if (norm == 0.0) {
            return vector;
        }
        std::vector<double> normalized_vector(vector.size());
        for (size_t i = 0; i < vector.size(); ++i) {
            normalized_vector[i] = vector[i] / norm;
        }
        return normalized_vector;
    }

private:
    int dimension;
};

class SequenceGenerator {
public:
    SequenceGenerator(const Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    std::vector<std::vector<double>> generate_sequence(int length) {
        std::vector<std::vector<double>> sequence;
        for (int i = 0; i < length; ++i) {
            std::vector<double> vector = vectorizer.create_random_vector();
            std::vector<double> normalized_vector = vectorizer.normalize_vector(vector);
            sequence.push_back(normalized_vector);
        }
        return sequence;
    }

private:
    const Vectorizer& vectorizer;
};

class Processor {
public:
    Processor(const SequenceGenerator& sequence_generator) : sequence_generator(sequence_generator) {}

    std::vector<std::vector<double>> process_sequence(const std::vector<std::vector<double>>& sequence) {
        std::vector<std::vector<double>> processed_sequence;
        for (const std::vector<double>& vector : sequence) {
            std::vector<double> processed_vector(vector.size());
            for (size_t i = 0; i < vector.size(); ++i) {
                processed_vector[i] = std::sin(vector[i]);
            }
            processed_sequence.push_back(processed_vector);
        }
        return processed_sequence;
    }

private:
    const SequenceGenerator& sequence_generator;
};

int main() {
    int dimension = 10;
    int length = 1000;
    Vectorizer vectorizer(dimension);
    SequenceGenerator sequence_generator(vectorizer);
    Processor processor(sequence_generator);
    while (true) {
        std::vector<std::vector<double>> sequence = sequence_generator.generate_sequence(length);
        std::vector<std::vector<double>> processed_sequence = processor.process_sequence(sequence);
    }
    return 0;
}