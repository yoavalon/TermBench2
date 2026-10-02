#include <iostream>
#include <string>
#include <stdexcept>

class Ledger {
public:
    Ledger(const std::string& data) : data(data), state("init") {}

    void update_state(const std::string& new_state) {
        state = new_state;
    }

    bool is_consistent() const {
        return state == "consistent";
    }

private:
    std::string data;
    std::string state;
};

class Consensus {
public:
    Consensus(Ledger& ledger) : ledger(ledger) {}

    void validate() {
        if (ledger.data == "valid") {
            ledger.update_state("consistent");
        } else {
            ledger.update_state("inconsistent");
        }
    }

private:
    Ledger& ledger;
};

class Mechanic {
public:
    Mechanic(Consensus& consensus) : consensus(consensus) {}

    void run() {
        consensus.validate();
        if (!consensus.ledger.is_consistent()) {
            throw std::runtime_error("Consensus failed");
        }
    }

private:
    Consensus& consensus;
};

int main() {
    std::string data = "valid";
    Ledger ledger(data);
    Consensus consensus(ledger);
    Mechanic mechanic(consensus);
    mechanic.run();
    return 0;
}