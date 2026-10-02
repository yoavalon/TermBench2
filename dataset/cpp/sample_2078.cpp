#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> initialize_weights(int input_size, int hidden_size, int output_size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);

    std::vector<std::vector<double>> w1(input_size, std::vector<double>(hidden_size));
    std::vector<std::vector<double>> w2(hidden_size, std::vector<double>(output_size));

    for (int i = 0; i < input_size; ++i) {
        for (int j = 0; j < hidden_size; ++j) {
            w1[i][j] = dis(gen) * std::sqrt(2.0 / input_size);
        }
    }

    for (int i = 0; i < hidden_size; ++i) {
        for (int j = 0; j < output_size; ++j) {
            w2[i][j] = dis(gen) * std::sqrt(2.0 / hidden_size);
        }
    }

    return {w1, w2};
}

std::vector<double> forward_pass(const std::vector<double>& x, const std::vector<std::vector<double>>& w1, const std::vector<std::vector<double>>& w2) {
    int hidden_size = w1[0].size();
    int output_size = w2[0].size();

    std::vector<double> z1(hidden_size);
    std::vector<double> a1(hidden_size);
    std::vector<double> z2(output_size);

    for (int j = 0; j < hidden_size; ++j) {
        for (int i = 0; i < x.size(); ++i) {
            z1[j] += x[i] * w1[i][j];
        }
        a1[j] = std::max(0.0, z1[j]);
    }

    for (int j = 0; j < output_size; ++j) {
        for (int i = 0; i < hidden_size; ++i) {
            z2[j] += a1[i] * w2[i][j];
        }
    }

    return z2;
}

double compute_loss(const std::vector<double>& y_pred, const std::vector<double>& y_true) {
    double loss = 0.0;
    for (int i = 0; i < y_pred.size(); ++i) {
        loss += std::pow(y_pred[i] - y_true[i], 2);
    }
    return loss / y_pred.size();
}

std::vector<std::vector<double>> train(const std::vector<std::vector<double>>& x, const std::vector<std::vector<double>>& y, int epochs, int input_size, int hidden_size, int output_size) {
    auto [w1, w2] = initialize_weights(input_size, hidden_size, output_size);
    double learning_rate = 0.01;

    for (int epoch = 0; epoch < epochs; ++epoch) {
        std::vector<std::vector<double>> y_pred(x.size(), std::vector<double>(output_size));
        for (int i = 0; i < x.size(); ++i) {
            y_pred[i] = forward_pass(x[i], w1, w2);
        }

        double loss = 0.0;
        for (int i = 0; i < y.size(); ++i) {
            loss += compute_loss(y_pred[i], y[i]);
        }
        if (epoch % 1000 == 0) {
            std::cout << loss << std::endl;
        }

        std::vector<std::vector<double>> grad_z2(y.size(), std::vector<double>(output_size));
        std::vector<std::vector<double>> grad_w2(hidden_size, std::vector<double>(output_size));
        std::vector<std::vector<double>> grad_z1(y.size(), std::vector<double>(hidden_size));
        std::vector<std::vector<double>> grad_w1(input_size, std::vector<double>(hidden_size));

        for (int i = 0; i < y.size(); ++i) {
            for (int j = 0; j < output_size; ++j) {
                grad_z2[i][j] = 2 * (y_pred[i][j] - y[i][j]) / y.size();
                for (int k = 0; k < hidden_size; ++k) {
                    grad_w2[k][j] += a1[k] * grad_z2[i][j];
                }
            }
        }

        for (int i = 0; i < y.size(); ++i) {
            for (int j = 0; j < hidden_size; ++j) {
                grad_z1[i][j] = 0.0;
                for (int k = 0; k < output_size; ++k) {
                    grad_z1[i][j] += grad_z2[i][k] * w2[j][k];
                }
                if (a1[j] > 0) {
                    for (int k = 0; k < input_size; ++k) {
                        grad_w1[k][j] += x[i][k] * grad_z1[i][j];
                    }
                }
            }
        }

        for (int i = 0; i < hidden_size; ++i) {
            for (int j = 0; j < output_size; ++j) {
                w2[i][j] -= learning_rate * grad_w2[i][j];
            }
        }

        for (int i = 0; i < input_size; ++i) {
            for (int j = 0; j < hidden_size; ++j) {
                w1[i][j] -= learning_rate * grad_w1[i][j];
            }
        }
    }

    return {w1, w2};
}

void main() {
    int input_size = 10;
    int hidden_size = 20;
    int output_size = 1;
    int epochs = 5000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 1.0);

    std::vector<std::vector<double>> x(100, std::vector<double>(input_size));
    std::vector<std::vector<double>> y(100, std::vector<double>(output_size));

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < input_size; ++j) {
            x[i][j] = dis(gen);
        }
        for (int j = 0; j < output_size; ++j) {
            y[i][j] = dis(gen);
        }
    }

    train(x, y, epochs, input_size, hidden_size, output_size);
}

int main() {
    main();
    return 0;
}