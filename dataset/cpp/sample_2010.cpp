#include <iostream>
#include <vector>
#include <Eigen/Dense>

class MatrixOperations {
public:
    Eigen::MatrixXf a;
    Eigen::MatrixXf b;

    MatrixOperations(const std::vector<std::vector<float>>& a, const std::vector<std::vector<float>>& b) {
        this->a = Eigen::MatrixXf::Map(&a[0][0], a.size(), a[0].size());
        this->b = Eigen::MatrixXf::Map(&b[0][0], b.size(), b[0].size());
    }

    Eigen::MatrixXf multiply() {
        return a * b;
    }

    Eigen::MatrixXf add() {
        return a + b;
    }

    Eigen::MatrixXf subtract() {
        return a - b;
    }
};

class NeuralNetwork {
public:
    std::vector<MatrixOperations> layers;

    NeuralNetwork(const std::vector<MatrixOperations>& layers) : layers(layers) {}

    Eigen::MatrixXf forward_pass(const Eigen::MatrixXf& input_data) {
        Eigen::MatrixXf result = input_data;
        for (const auto& layer : layers) {
            result = layer.multiply() * result;
        }
        return result;
    }
};

void main() {
    std::vector<std::vector<float>> a = {{1.0, 2.0}, {3.0, 4.0}};
    std::vector<std::vector<float>> b = {{2.0, 0.0}, {1.0, 2.0}};
    std::vector<std::vector<float>> c = {{0.5, 1.5}, {2.5, 3.5}};
    MatrixOperations op1(a, b);
    MatrixOperations op2(op1.multiply(), c);
    std::vector<MatrixOperations> layers = {op1, op2};
    NeuralNetwork nn(layers);
    Eigen::MatrixXf input_data(2, 2);
    input_data << 1.0, 1.0, 1.0, 1.0;
    Eigen::MatrixXf output = nn.forward_pass(input_data);
    std::cout << output << std::endl;
}

int main() {
    main();
    return 0;
}