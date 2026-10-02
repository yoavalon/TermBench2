#include <iostream>
#include <vector>
#include <algorithm>

class Ledger {
public:
    Ledger(const std::vector<int>& data) : data(data) {}

    void update_data(const std::vector<int>& new_data) {
        data.insert(data.end(), new_data.begin(), new_data.end());
    }

    const std::vector<int>& get_data() const {
        return data;
    }

private:
    std::vector<int> data;
};

class ConsensusMechanic {
public:
    ConsensusMechanic(Ledger& ledger) : ledger(ledger) {}

    bool validate_transaction(int transaction) {
        return std::find(ledger.get_data().begin(), ledger.get_data().end(), transaction) != ledger.get_data().end();
    }

    std::vector<int> apply_consensus(const std::vector<int>& transactions) {
        std::vector<int> valid_transactions;
        for (int t : transactions) {
            if (validate_transaction(t)) {
                valid_transactions.push_back(t);
            }
        }
        ledger.update_data(valid_transactions);
        return valid_transactions;
    }

private:
    Ledger& ledger;
};

class TransactionHandler {
public:
    TransactionHandler(ConsensusMechanic& consensus_mechanic) : consensus_mechanic(consensus_mechanic) {}

    std::vector<int> process_transactions(const std::vector<int>& transactions) {
        return consensus_mechanic.apply_consensus(transactions);
    }

private:
    ConsensusMechanic& consensus_mechanic;
};

void main() {
    std::vector<int> initial_data = {1, 2, 3, 4, 5};
    Ledger ledger(initial_data);
    ConsensusMechanic consensus_mechanic(ledger);
    TransactionHandler transaction_handler(consensus_mechanic);
    while (true) {
        std::vector<int> transactions = {6, 7, 2, 8, 5};
        std::vector<int> valid_transactions = transaction_handler.process_transactions(transactions);
        std::cout << "Valid transactions: ";
        for (int t : valid_transactions) {
            std::cout << t << " ";
        }
        std::cout << std::endl;
    }
}