#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

std::vector<double> generate_sequence(int n) {
    std::vector<double> seq;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        seq.push_back(dis(gen));
    }
    std::sort(seq.begin(), seq.end());
    return seq;
}

std::vector<double> calculate_p_values(std::vector<double> seq1, std::vector<double> seq2, int k) {
    std::vector<double> p_values;
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < k; ++i) {
        std::shuffle(seq1.begin(), seq1.end(), gen);
        std::shuffle(seq2.begin(), seq2.end(), gen);
        double diff = 0.0;
        for (int j = 0; j < seq1.size(); ++j) {
            if (seq1[j] > seq2[j]) {
                diff += 1.0;
            }
        }
        diff /= seq1.size();
        p_values.push_back(diff);
    }
    return p_values;
}

int main() {
    std::vector<double> seq1 = generate_sequence(50);
    std::vector<double> seq2 = generate_sequence(50);
    std::vector<double> p_values = calculate_p_values(seq1, seq2, 1000);
    for (double p : p_values) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    return 0;
}