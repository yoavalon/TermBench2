#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::string hash(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::string output = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return output;
}

bool validate_blockchain(const std::vector<std::string>& blockchain, int index) {
    if (index >= blockchain.size()) {
        return true;
    }
    std::string prev_block = index > 0 ? blockchain[index - 1] : "";
    if (blockchain[index] != hash(prev_block)) {
        return false;
    }
    return validate_blockchain(blockchain, index + 1);
}

void append_block(std::vector<std::string>& blockchain, const std::string& new_block) {
    if (validate_blockchain(blockchain, 0)) {
        blockchain.push_back(new_block);
    }
}

int main() {
    std::vector<std::string> blockchain = {"genesis"};
    append_block(blockchain, "block1");
    append_block(blockchain, "block2");
    std::cout << validate_blockchain(blockchain, 0) << std::endl;
    return 0;
}