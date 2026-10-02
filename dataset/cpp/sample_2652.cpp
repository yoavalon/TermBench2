#include <iostream>
#include <Eigen/Dense>
#include <cmath>

using namespace Eigen;
using namespace std;

MatrixXf initialize_weights(int size) {
    return MatrixXf::Random(size, size);
}

MatrixXf apply_activation(const MatrixXf& matrix) {
    return matrix.array().tanh();
}

MatrixXf forward_pass(const MatrixXf& input_matrix, const MatrixXf& weights) {
    return apply_activation(input_matrix * weights);
}

float calculate_error(const MatrixXf& output, const MatrixXf& target) {
    return (output - target).squaredNorm() / output.size();
}

MatrixXf update_weights(const MatrixXf& weights, const MatrixXf& input_matrix, const MatrixXf& output, const MatrixXf& target, float learning_rate) {
    MatrixXf error = output - target;
    MatrixXf gradient = input_matrix.transpose() * (error.array() * (1 - output.array().square()));
    return weights - learning_rate * gradient;
}

class NeuralNetwork {
public:
    MatrixXf weights;
    float learning_rate;

    NeuralNetwork(int size, float learning_rate) {
        this->weights = initialize_weights(size);
        this->learning_rate = learning_rate;
    }

    pair<MatrixXf, float> train(const MatrixXf& input_data, const MatrixXf& target_data, int epochs) {
        for (int i = 0; i < epochs; ++i) {
            MatrixXf output = forward_pass(input_data, this->weights);
            float error = calculate_error(output, target_data);
            this->weights = update_weights(this->weights, input_data, output, target_data, this->learning_rate);
        }
        return make_pair(output, error);
    }
};

void main() {
    int size = 4;
    float learning_rate = 0.1;
    int epochs = 100;
    MatrixXf input_data = MatrixXf::Random(1, size);
    MatrixXf target_data = MatrixXf::Random(1, size);
    NeuralNetwork network(size, learning_rate);
    auto result = network.train(input_data, target_data, epochs);
    cout << "Final Output: " << result.first << endl;
    cout << "Final Error: " << result.second << endl;
}

int main() {
    main();
    return 0;
}