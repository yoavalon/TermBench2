#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class MatrixProcessor {
public:
    MatrixXd data;

    MatrixProcessor(const MatrixXd& data) : data(data) {}

    MatrixXd apply_transformation(const MatrixXd& weights) {
        return data * weights;
    }

    double sigmoid(double x) {
        return 1.0 / (1.0 + exp(-x));
    }

    MatrixXd forward_pass(const MatrixXd& weights) {
        MatrixXd transformed = apply_transformation(weights);
        MatrixXd activated(transformed.rows(), transformed.cols());
        for (int i = 0; i < transformed.rows(); ++i) {
            for (int j = 0; j < transformed.cols(); ++j) {
                activated(i, j) = sigmoid(transformed(i, j));
            }
        }
        return activated;
    }
};

class DataMutator {
public:
    MatrixXd matrix;

    DataMutator(const MatrixXd& matrix) : matrix(matrix) {}

    MatrixXd mutate(double factor) {
        return matrix * factor;
    }

    MatrixXd normalize() {
        return matrix.normalized();
    }

    MatrixXd process(double factor) {
        MatrixXd mutated = mutate(factor);
        MatrixXd normalized = normalize();
        return normalized;
    }
};

class NeuralNetwork {
public:
    MatrixXd input_data;
    MatrixXd weights;

    NeuralNetwork(const MatrixXd& input_data, const MatrixXd& weights) : input_data(input_data), weights(weights) {}

    MatrixXd execute() {
        MatrixProcessor processor(input_data);
        MatrixXd activated_output = processor.forward_pass(weights);
        return activated_output;
    }
};

void main() {
    random_device rd;
    default_random_engine gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    MatrixXd data(10, 5);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            data(i, j) = dist(gen);
        }
    }

    MatrixXd weights(5, 3);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            weights(i, j) = dist(gen);
        }
    }

    double factor = 2.0;
    DataMutator mutator(data);
    MatrixXd processed_data = mutator.process(factor);
    NeuralNetwork network(processed_data, weights);
    MatrixXd output = network.execute();
    cout << output << endl;
}