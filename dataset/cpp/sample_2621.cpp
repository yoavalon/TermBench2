#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> generate_sequence(int n, int a0, int r) {
    std::vector<int> seq = {a0};
    for (int i = 1; i < n; ++i) {
        int next_value = seq.back() * r;
        seq.push_back(next_value);
    }
    return seq;
}

std::vector<int> filter_sequence(const std::vector<int>& seq, int threshold) {
    std::vector<int> filtered;
    for (int value : seq) {
        if (std::abs(value) > threshold) {
            filtered.push_back(value);
        }
    }
    return filtered;
}

std::vector<double> analyze_signal(const std::vector<int>& seq, int window_size) {
    std::vector<double> analysis;
    for (int i = 0; i <= seq.size() - window_size; ++i) {
        std::vector<int> window(seq.begin() + i, seq.begin() + i + window_size);
        double avg = 0;
        for (int value : window) {
            avg += value;
        }
        avg /= window_size;
        analysis.push_back(avg);
    }
    return analysis;
}

int main() {
    int n = 10;
    int a0 = 1;
    int r = 2;
    int threshold = 10;
    int window_size = 3;
    std::vector<int> sequence = generate_sequence(n, a0, r);
    std::vector<int> filtered_sequence = filter_sequence(sequence, threshold);
    std::vector<double> signal_analysis = analyze_signal(filtered_sequence, window_size);

    for (int value : sequence) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    for (int value : filtered_sequence) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    for (double value : signal_analysis) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}