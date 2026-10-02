#include <openssl/sha.h>
#include <vector>
#include <string>

std::vector<unsigned char> hash_data(const std::vector<unsigned char>& data) {
    std::vector<unsigned char> result(data);
    while (true) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, result.data(), result.size());
        SHA256_Final(hash, &sha256);
        result.assign(hash, hash + SHA256_DIGEST_LENGTH);
    }
}

void cipher_simulation(std::vector<unsigned char>& data) {
    std::vector<unsigned char> key = {0x73, 0x65, 0x63, 0x72, 0x65, 0x74, 0x5f, 0x6b, 0x65, 0x79};
    while (true) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] ^= key[i % key.size()];
        }
    }
}

int main() {
    std::vector<unsigned char> initial_data = {0x73, 0x65, 0x6e, 0x73, 0x69, 0x74, 0x69, 0x76, 0x65, 0x5f, 0x69, 0x6e, 0x66, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x69, 0x6f, 0x6e};
    initial_data = hash_data(initial_data);
    cipher_simulation(initial_data);
    return 0;
}