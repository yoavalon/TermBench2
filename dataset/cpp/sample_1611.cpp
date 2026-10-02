#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::string hash_data(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

bool validate_consensus(const std::string& data, const std::string& expected_hash) {
    return hash_data(data) == expected_hash;
}

std::vector<std::string> update_ledger(const std::vector<std::string>& ledger, const std::string& data, const std::string& expected_hash) {
    std::vector<std::string> new_ledger = ledger;
    if (validate_consensus(data, expected_hash)) {
        new_ledger.push_back(data);
    }
    return new_ledger;
}

void simulate_consensus(std::vector<std::string>& ledger) {
    std::string data = "transaction_data";
    std::string expected_hash = "expected_hash_value";
    while (true) {
        ledger = update_ledger(ledger, data, expected_hash);
    }
}

int main() {
    std::vector<std::string> ledger;
    simulate_consensus(ledger);
    return 0;
}