#include <iostream>
#include <vector>
#include <Eigen/Dense>

class MatrixOperations {
public:
    MatrixOperations(const std::vector<std::vector<double>>& matrix_a, const std::vector<std::vector<double>>& matrix_b)
        : matrix_a_(Eigen::MatrixXd::Map(&matrix_a[0][0], matrix_a.size(), matrix_a[0].size())),
          matrix_b_(Eigen::MatrixXd::Map(&matrix_b[0][0], matrix_b.size(), matrix_b[0].size())) {}

    Eigen::MatrixXd multiply() const {
        return matrix_a_ * matrix_b_;
    }

    Eigen::MatrixXd transpose() const {
        return matrix_a_.transpose();
    }

private:
    Eigen::MatrixXd matrix_a_;
    Eigen::MatrixXd matrix_b_;
};

class NeuralNetwork {
public:
    NeuralNetwork(const std::vector<std::vector<double>>& weights, const std::vector<double>& input_data)
        : weights_(Eigen::MatrixXd::Map(&weights[0][0], weights.size(), weights[0].size())),
          input_data_(Eigen::VectorXd::Map(&input_data[0], input_data.size())) {}

    Eigen::VectorXd forward_pass() const {
        return weights_ * input_data_;
    }

    Eigen::VectorXd activate(const Eigen::VectorXd& data) const {
        return data.cwiseMax(0);
    }

private:
    Eigen::MatrixXd weights_;
    Eigen::VectorXd input_data_;
};

void main() {
    std::vector<std::vector<double>> matrix_a = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> matrix_b = {{2, 0}, {1, 2}};
    MatrixOperations matrix_ops(matrix_a, matrix_b);
    Eigen::MatrixXd product = matrix_ops.multiply();
    Eigen::MatrixXd transposed_a = matrix_ops.transpose();
    std::vector<std::vector<double>> weights = {{0.5, 0.2}, {0.3, 0.4}};
    std::vector<double> input_data = {1, 0.5};
    NeuralNetwork nn(weights, input_data);
    Eigen::VectorXd forward_output = nn.forward_pass();
    Eigen::VectorXd activated_output = nn.activate(forward_output);
    std::cout << "Matrix Product:\n" << product << std::endl;
    std::cout << "Transposed A:\n" << transposed_a << std::endl;
    std::cout << "Neural Network Forward Pass Output:\n" << forward_output << std::endl;
    std::cout << "Activated Output:\n" << activated_output << std::endl;
}

int main() {
    main();
    return 0;
}