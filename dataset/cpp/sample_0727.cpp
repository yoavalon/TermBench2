#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int hash_data(const std::string& data) {
    int result = 0;
    for (char c : data) {
        result = (result + c * 17) % 10007;
    }
    return result;
}

bool validate_block(const std::unordered_map<std::string, std::string>& block, const std::string& prev_hash) {
    if (block.at("prev_hash") == prev_hash && block.at("data") == std::to_string(hash_data(block.at("data")))) {
        return true;
    }
    return false;
}

bool verify_chain(const std::vector<std::unordered_map<std::string, std::string>>& chain) {
    if (chain.empty()) {
        return true;
    }
    if (chain.size() == 1) {
        return validate_block(chain[0], "genesis");
    }
    return validate_block(chain.back(), chain[chain.size() - 2].at("hash")) && verify_chain(std::vector<std::unordered_map<std::string, std::string>>(chain.begin(), chain.end() - 1));
}

int main() {
    std::vector<std::unordered_map<std::string, std::string>> blockchain = {
        {{"hash", "genesis"}, {"data", "initial"}},
        {{"hash", "hash1"}, {"data", "data1"}, {"prev_hash", "genesis"}},
        {{"hash", "hash2"}, {"data", "data2"}, {"prev_hash", "hash1"}}
    };
    std::cout << std::boolalpha << verify_chain(blockchain) << std::endl;
    return 0;
}