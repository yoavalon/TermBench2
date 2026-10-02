#include <iostream>
#include <vector>
#include <random>

std::vector<double> generate_sequence(int length) {
    std::vector<double> seq;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < length; ++i) {
        seq.push_back(dis(gen));
    }
    return seq;
}

double analyze_sequence(const std::vector<double>& seq) {
    double total = 0;
    for (double num : seq) {
        total += num;
    }
    return total / seq.size();
}

void simulate_thermodynamic_state() {
    while (true) {
        std::vector<double> seq = generate_sequence(100);
        double avg = analyze_sequence(seq);
        std::cout << "Average state: " << avg << std::endl;
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}