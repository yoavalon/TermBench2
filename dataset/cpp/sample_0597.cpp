#include <iostream>
#include <vector>

class CoordinateTransformer {
public:
    CoordinateTransformer(const std::vector<std::vector<double>>& matrix) : matrix(matrix) {}

    std::vector<double> transform(const std::vector<double>& vector) {
        std::vector<double> result(3, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
        return result;
    }

private:
    std::vector<std::vector<double>> matrix;
};

class TransformationChain {
public:
    TransformationChain(const std::vector<CoordinateTransformer>& transformers) : transformers(transformers) {}

    std::vector<double> apply_transformations(const std::vector<double>& vector) {
        std::vector<double> transformed_vector = vector;
        for (const auto& transformer : transformers) {
            transformed_vector = transformer.transform(transformed_vector);
        }
        return transformed_vector;
    }

private:
    std::vector<CoordinateTransformer> transformers;
};

class ContinuousTransformation {
public:
    ContinuousTransformation(const TransformationChain& chain, double scale) : chain(chain), scale(scale) {}

    void process(std::vector<double>& vector) {
        while (true) {
            vector = chain.apply_transformations(vector);
            for (int i = 0; i < 3; ++i) {
                vector[i] *= scale;
            }
        }
    }

private:
    TransformationChain chain;
    double scale;
};

int main() {
    std::vector<std::vector<double>> matrix1 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<double>> matrix2 = {{0, 1, 0}, {1, 0, 0}, {0, 0, 1}};
    CoordinateTransformer transformer1(matrix1);
    CoordinateTransformer transformer2(matrix2);
    std::vector<CoordinateTransformer> transformers = {transformer1, transformer2};
    TransformationChain chain(transformers);
    ContinuousTransformation continuous(chain, 1.05);
    std::vector<double> initial_vector = {1, 1, 1};
    continuous.process(initial_vector);
    return 0;
}