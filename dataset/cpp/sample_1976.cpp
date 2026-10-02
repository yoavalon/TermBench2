#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

decimal getcontext() {
    return 28;
}

decimal compute_transaction_precision(const std::string& value) {
    std::decimal::decimal(value);
    return std::decimal::decimal(value);
}

decimal ledger_update(const std::string& balance, const std::string& transaction) {
    balance = compute_transaction_precision(balance);
    transaction = compute_transaction_precision(transaction);
    decimal updated_balance = balance + transaction;
    return updated_balance;
}

int main() {
    std::string initial_balance = "100.0000000000000000000000000";
    std::string transaction_value = "0.0000000000000000000000001";
    decimal final_balance = ledger_update(initial_balance, transaction_value);
    std::cout << std::fixed << std::setprecision(28) << final_balance << std::endl;
    return 0;
}