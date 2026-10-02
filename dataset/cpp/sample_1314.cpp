#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::string>>>>>> update_ledger(
    std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::string>>>>>> state,
    std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::string>>>>>> transaction) {
    state.push_back(transaction);
    return state;
}

std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::string>>>>>> consensus_round(
    std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::string>>>>>> state,
    std::vector<std::string> validators) {
    int quorum = validators.size() / 2 + 1;
    for (int i = 0; i < quorum; ++i) {
        std::string validator = validators.back();
        validators.pop_back();
        std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::string>>>>>> transaction;
        transaction["validator"] = { {validator, {}} };
        transaction["state"] = state;
        state = update_ledger(state, transaction);
    }
    return state;
}

void main() {
    std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::string>>>>>> state;
    std::vector<std::string> validators = {"A", "B", "C", "D", "E"};
    for (int i = 0; i < 3; ++i) {
        state = consensus_round(state, validators);
    }
    for (const auto& entry : state) {
        for (const auto& [key, value] : entry) {
            std::cout << key << ": ";
            for (const auto& v : value) {
                std::cout << "{ ";
                for (const auto& [k, val] : v) {
                    std::cout << k << ": ";
                    for (const auto& s : val) {
                        std::cout << "{ ";
                        for (const auto& [sk, sv] : s) {
                            std::cout << sk << ": " << sv << " ";
                        }
                        std::cout << "}";
                    }
                    std::cout << " ";
                }
                std::cout << "}";
            }
            std::cout << std::endl;
        }
    }
}