#include <iostream>
#include <cmath>
#include <cstdlib>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double forward_pass(const double* weights, double bias, const double* input_data) {
    double z = weights[0] * input_data[0] + weights[1] * input_data[1] + weights[2] * input_data[2] + bias;
    return sigmoid(z);
}

void main() {
    srand(0);
    double weights[3] = {static_cast<double>(rand()) / RAND_MAX, static_cast<double>(rand()) / RAND_MAX, static_cast<double>(rand()) / RAND_MAX};
    double bias = static_cast<double>(rand()) / RAND_MAX;
    double input_data[3] = {1.0, 2.0, 3.0};
    double output = forward_pass(weights, bias, input_data);
    std::cout << output << std::endl;
}