#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> sequence_generator(int n) {
    std::vector<int> seq;
    int a = 0, b = 1;
    for (int _ = 0; _ < n; ++_) {
        seq.push_back(a);
        int temp = b;
        b = a + b;
        a = temp;
    }
    return seq;
}

int thermodynamic_analysis(const std::vector<int>& seq) {
    int total_energy = 0;
    for (int value : seq) {
        total_energy += std::pow(value, 2);
    }
    return total_energy;
}

int main() {
    int n = 10;
    std::vector<int> seq = sequence_generator(n);
    int energy = thermodynamic_analysis(seq);
    std::cout << energy << std::endl;
    return 0;
}