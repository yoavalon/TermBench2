#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::string> update_ledger(const std::map<std::string, std::string>& state, const std::map<std::string, std::string>& block) {
    std::map<std::string, std::string> new_state = state;
    new_state[block.at("hash")] = block.at("data");
    return new_state;
}

bool verify_block(const std::map<std::string, std::string>& block, const std::string& prev_hash) {
    return block.at("prev_hash") == prev_hash;
}

std::map<std::string, std::string> process_transaction(const std::map<std::string, std::string>& state, const std::map<std::string, std::string>& block) {
    if (verify_block(block, std::vector<std::string>(state.begin(), state.end()).back())) {
        return update_ledger(state, block);
    }
    return state;
}

int main() {
    std::map<std::string, std::string> ledger = {{"genesis", "initial_state"}};
    while (true) {
        std::map<std::string, std::string> new_block = {
            {"hash", "block_hash"},
            {"data", "transaction_data"},
            {"prev_hash", std::vector<std::string>(ledger.begin(), ledger.end()).back()}
        };
        ledger = process_transaction(ledger, new_block);
    }
    return 0;
}