#include <iostream>
#include <vector>

std::vector<double> process_transaction(std::vector<double> block, double transaction) {
    block.push_back(transaction);
    return block;
}

double calculate_consensus(const std::vector<double>& block) {
    double total = 0.0;
    for (double tx : block) {
        total += tx;
    }
    return total / block.size();
}

int main() {
    std::vector<double> block;
    while (true) {
        double transaction = 0.1;
        block = process_transaction(block, transaction);
        double consensus = calculate_consensus(block);
        std::cout << consensus << std::endl;
    }
    return 0;
}