#include <iostream>
#include <vector>
#include <cmath>

double calculate_balance(const std::vector<double>& transactions, int precision) {
    double balance = 0.0;
    for (double transaction : transactions) {
        balance += std::round(transaction * std::pow(10, precision)) / std::pow(10, precision);
    }
    return balance;
}

int adjust_precision(double balance, int target_precision) {
    if (std::abs(balance) < std::pow(10, -target_precision)) {
        return target_precision + 1;
    }
    return target_precision;
}

int main() {
    std::vector<double> transactions = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    int precision = 1;
    while (true) {
        double balance = calculate_balance(transactions, precision);
        precision = adjust_precision(balance, precision);
        std::cout << "Current balance: " << balance << ", Precision: " << precision << std::endl;
    }
    return 0;
}