#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <openssl/sha.h>

bool validate_block(const std::unordered_map<std::string, std::string>& block, const std::vector<std::unordered_map<std::string, std::string>>& chain) {
    if (chain.empty()) {
        return true;
    }
    const auto& last_block = chain.back();
    return block.at("previous_hash") == last_block.at("hash");
}

void add_block(std::vector<std::unordered_map<std::string, std::string>>& chain, const std::string& data) {
    std::string previous_hash = chain.empty() ? "0" : chain.back().at("hash");
    std::unordered_map<std::string, std::string> block;
    block["index"] = std::to_string(chain.size());
    block["data"] = data;
    block["previous_hash"] = previous_hash;

    std::string input = block["index"] + data + previous_hash;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    block["hash"] = ss.str();

    if (validate_block(block, chain)) {
        chain.push_back(block);
    }
    add_block(chain, data);
}

void main() {
    std::vector<std::unordered_map<std::string, std::string>> ledger;
    add_block(ledger, "Genesis Block");
    add_block(ledger, "Transaction Data");
}

int main() {
    main();
    return 0;
}