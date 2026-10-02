#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>
#include <algorithm>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        std::string data = std::to_string(i);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        std::string hash_value;
        for (int j = 0; j < SHA256_DIGEST_LENGTH; ++j) {
            char buf[3];
            sprintf(buf, "%02x", hash[j]);
            hash_value.append(buf);
        }
        int value = std::stoll(hash_value, nullptr, 16) % 1000;
        sequence.push_back(value);
    }
    return sequence;
}

std::map<std::string, double> analyze_sequence(const std::vector<int>& seq) {
    std::map<std::string, double> stats;
    stats["min"] = *std::min_element(seq.begin(), seq.end());
    stats["max"] = *std::max_element(seq.begin(), seq.end());
    double sum = 0;
    for (int num : seq) {
        sum += num;
    }
    stats["avg"] = sum / seq.size();
    return stats;
}

int main() {
    std::vector<int> seq = generate_sequence(100);
    std::map<std::string, double> stats = analyze_sequence(seq);
    std::cout << "min: " << stats["min"] << ", max: " << stats["max"] << ", avg: " << stats["avg"] << std::endl;
    return 0;
}