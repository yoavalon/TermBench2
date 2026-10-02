#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <openssl/sha.h>

std::vector<unsigned long long> generate_sequence(unsigned long long seed, int length) {
    std::vector<unsigned long long> sequence;
    unsigned long long current = seed;
    for (int i = 0; i < length; ++i) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        std::string str = std::to_string(current);
        SHA256_Update(&sha256, str.c_str(), str.size());
        SHA256_Final(hash, &sha256);
        unsigned long long num = 0;
        for (int j = 0; j < SHA256_DIGEST_LENGTH; ++j) {
            num = (num << 8) | hash[j];
        }
        current = num;
        sequence.push_back(current);
    }
    return sequence;
}

std::unordered_map<unsigned long long, int> analyze_sequence(const std::vector<unsigned long long>& sequence) {
    std::unordered_map<unsigned long long, int> stats;
    for (unsigned long long num : sequence) {
        stats[num]++;
    }
    return stats;
}

int main() {
    unsigned long long seed = 42;
    int length = 10;
    std::vector<unsigned long long> seq = generate_sequence(seed, length);
    std::unordered_map<unsigned long long, int> stats = analyze_sequence(seq);
    for (const auto& pair : stats) {
        std::cout << "{" << pair.first << ": " << pair.second << "}" << std::endl;
    }
    return 0;
}