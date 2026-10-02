#include <iostream>
#include <vector>
#include <Eigen/Dense>

class MatrixOperations {
public:
    Eigen::MatrixXd matrix;

    MatrixOperations(const Eigen::MatrixXd& matrix) : matrix(matrix) {}

    Eigen::MatrixXd multiply(const Eigen::MatrixXd& other_matrix) {
        return matrix * other_matrix;
    }

    Eigen::MatrixXd add(const Eigen::MatrixXd& other_matrix) {
        return matrix + other_matrix;
    }
};

class NeuralNetwork {
public:
    std::vector<MatrixOperations> layers;

    NeuralNetwork(const std::vector<MatrixOperations>& layers) : layers(layers) {}

    Eigen::MatrixXd forward_pass(const Eigen::MatrixXd& input_data) {
        Eigen::MatrixXd current_data = input_data;
        for (const auto& layer : layers) {
            current_data = layer.multiply(current_data);
        }
        return current_data;
    }
};

class RecursiveProcess {
public:
    NeuralNetwork neural_network;
    Eigen::MatrixXd input_data;

    RecursiveProcess(const NeuralNetwork& neural_network, const Eigen::MatrixXd& input_data) 
        : neural_network(neural_network), input_data(input_data) {}

    void process(const Eigen::MatrixXd& current_data) {
        Eigen::MatrixXd output_data = neural_network.forward_pass(current_data);
        process(output_data);
    }
};

int main() {
    Eigen::MatrixXd matrix1(2, 2);
    matrix1 << 0.5, 0.2, 0.3, 0.7;
    Eigen::MatrixXd matrix2(2, 2);
    matrix2 << 0.1, 0.4, 0.9, 0.5;
    std::vector<MatrixOperations> layers = {MatrixOperations(matrix1), MatrixOperations(matrix2)};
    NeuralNetwork neural_network(layers);
    Eigen::MatrixXd input_data(2, 1);
    input_data << 1, 1;
    RecursiveProcess recursive_process(neural_network, input_data);
    recursive_process.process(input_data);
    return 0;
}