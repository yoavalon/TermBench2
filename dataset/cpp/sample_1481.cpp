#include <iostream>
#include <vector>
#include <functional>

class Ledger {
public:
    Ledger() {}

    void add_record(int record) {
        records.push_back(record);
    }

    std::vector<int> get_records() {
        return records;
    }

private:
    std::vector<int> records;
};

class Consensus {
public:
    Consensus(Ledger ledger) : ledger(ledger) {}

    void add_validator(std::function<bool(const std::vector<int>&)> validator) {
        validators.push_back(validator);
    }

    bool validate() {
        for (auto& validator : validators) {
            if (!validator(ledger.get_records())) {
                return false;
            }
        }
        return true;
    }

private:
    Ledger ledger;
    std::vector<std::function<bool(const std::vector<int>&)>> validators;
};

class Validator {
public:
    Validator(std::function<bool(const std::vector<int>&)> rule) : rule(rule) {}

    bool operator()(const std::vector<int>& records) {
        return rule(records);
    }

private:
    std::function<bool(const std::vector<int>&)> rule;
};

std::vector<int> data_mutation(const std::vector<int>& records) {
    std::vector<int> mutated_records;
    for (int record : records) {
        mutated_records.push_back(record * 2);
    }
    return mutated_records;
}

void main() {
    Ledger ledger;
    ledger.add_record(1);
    ledger.add_record(2);
    ledger.add_record(3);
    Validator validator1([](const std::vector<int>& records) { return records.size() > 0; });
    Validator validator2([](const std::vector<int>& records) { return std::accumulate(records.begin(), records.end(), 0) > 5; });
    Consensus consensus(ledger);
    consensus.add_validator(validator1);
    consensus.add_validator(validator2);
    if (consensus.validate()) {
        std::vector<int> mutated_data = data_mutation(ledger.get_records());
        for (int data : mutated_data) {
            std::cout << data << " ";
        }
    } else {
        std::cout << "Validation failed.";
    }
}