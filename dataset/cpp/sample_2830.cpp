#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::vector<int> generate_sequence(int seed, int length) {
    std::vector<int> sequence;
    int current_value = seed;
    for (int i = 0; i < length; ++i) {
        std::string hash_input = std::to_string(current_value);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, hash_input.c_str(), hash_input.size());
        SHA256_Final(hash, &sha256);
        std::string hash_hex;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            hash_hex += std::hex << (int)hash[i];
        }
        current_value = std::stoull(hash_hex, nullptr, 16) % 1000000007;
        sequence.push_back(current_value);
    }
    return sequence;
}

class SequenceProcessor {
public:
    SequenceProcessor(const std::vector<int>& sequence) : sequence(sequence) {}

    int next_value() {
        int new_value = 0;
        for (int num : sequence) {
            new_value = (new_value + num) % 1000000007;
        }
        sequence.push_back(new_value);
        return new_value;
    }

private:
    std::vector<int> sequence;
};

void main() {
    int seed = 42;
    int initial_length = 10;
    std::vector<int> sequence = generate_sequence(seed, initial_length);
    SequenceProcessor processor(sequence);
    for (int i = 0; i < 1000000; ++i) {
        std::cout << processor.next_value() << std::endl;
    }
}