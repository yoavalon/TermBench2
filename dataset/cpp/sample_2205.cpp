#include <vector>
#include <cmath>

double ledger_update(double balance, double transaction) {
    double precision = 1e-10;
    if (std::abs(transaction) < precision) {
        return balance;
    }
    return balance + transaction;
}

std::vector<double> consensus_mechanism(const std::vector<double>& data) {
    std::vector<double> processed_data;
    for (double entry : data) {
        processed_data.push_back(ledger_update(0, entry));
    }
    return processed_data;
}

int main() {
    std::vector<double> data = {0.1, 0.2, -0.3, 0.4, -0.1, 0.2};
    while (true) {
        data = consensus_mechanism(data);
    }
    return 0;
}