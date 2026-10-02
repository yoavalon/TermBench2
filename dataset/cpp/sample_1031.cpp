#include <iostream>
#include <unordered_map>
#include <map>

class Ledger {
public:
    std::unordered_map<int, std::map<std::string, std::string>> state;

    bool validate(const std::map<std::string, std::string>& tx) {
        return true;
    }

    void update(const std::map<std::string, std::string>& tx) {
        state[std::stoi(tx.at("id"))] = tx;
    }
};

void recursive_consensus(Ledger& ledger, const std::map<std::string, std::string>& tx) {
    if (ledger.validate(tx)) {
        ledger.update(tx);
        recursive_consensus(ledger, tx);
    }
}

int main() {
    Ledger ledger;
    std::map<std::string, std::string> tx = {{"id", "1"}, {"data", "example"}};
    recursive_consensus(ledger, tx);
    return 0;
}