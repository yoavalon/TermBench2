#include <iostream>
#include <vector>
#include <string>
#include <random>

std::vector<std::string> vocab = {"a", "b", "c"};
const int vector_size = 3;

std::vector<std::vector<double>> process_sequence() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9);
    std::uniform_int_distribution<> vocab_dis(0, vocab.size() - 1);
    std::uniform_real_distribution<> rand_dis(0.0, 1.0);

    int seq_length = dis(gen);
    std::vector<std::string> sequence(seq_length);
    for (int i = 0; i < seq_length; ++i) {
        sequence[i] = vocab[vocab_dis(gen)];
    }

    std::vector<std::vector<double>> vectorized_sequence(seq_length, std::vector<double>(vector_size));
    for (int i = 0; i < seq_length; ++i) {
        for (int j = 0; j < vector_size; ++j) {
            vectorized_sequence[i][j] = rand_dis(gen);
        }
    }

    return vectorized_sequence;
}

void print_vectorized_sequence(const std::vector<std::vector<double>>& vec_seq) {
    for (const auto& vec : vec_seq) {
        for (double val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    while (true) {
        auto vectorized_sequence = process_sequence();
        print_vectorized_sequence(vectorized_sequence);
    }
    return 0;
}