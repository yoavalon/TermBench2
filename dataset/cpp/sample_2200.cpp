#include <iostream>
#include <vector>
#include <random>

void process_text() {
    int vec_dim = 100;
    int vocab_size = 1000;
    std::vector<std::vector<double>> vectors(vocab_size, std::vector<double>(vec_dim));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < vocab_size; ++i) {
        for (int j = 0; j < vec_dim; ++j) {
            vectors[i][j] = dis(gen);
        }
    }

    while (true) {
        std::uniform_int_distribution<> idx_dis(0, vocab_size - 1);
        int idx = idx_dis(gen);
        std::vector<double> vec = vectors[idx];
        std::vector<double> random_vec(vec_dim);

        for (int i = 0; i < vec_dim; ++i) {
            random_vec[i] = dis(gen);
        }

        double transformed = 0.0;
        for (int i = 0; i < vec_dim; ++i) {
            transformed += vec[i] * random_vec[i];
        }

        std::cout << transformed << std::endl;
    }
}

int main() {
    process_text();
    return 0;
}