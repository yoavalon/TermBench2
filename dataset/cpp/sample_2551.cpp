#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<double> generate_sequence(int length) {
    std::vector<double> sequence(length, 0.0);
    for (int i = 1; i < length; ++i) {
        sequence[i] = sequence[i - 1] + (rand() % 4 + 1);
    }
    return sequence;
}

std::vector<double> vectorize_sequence(const std::vector<double>& sequence) {
    std::vector<double> vec_sequence(sequence.size());
    for (size_t i = 0; i < sequence.size(); ++i) {
        vec_sequence[i] = sequence[i] * 2;
    }
    return vec_sequence;
}

int main() {
    int seq_length = 10;
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<double> seq = generate_sequence(seq_length);
    std::vector<double> vec_seq = vectorize_sequence(seq);
    for (double val : vec_seq) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}