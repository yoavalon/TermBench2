#include <iostream>
#include <iomanip>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <cstdlib>
#include <vector>

class HashSimulator {
public:
    std::vector<unsigned char> data;

    HashSimulator(const std::vector<unsigned char>& data) : data(data) {}

    std::string compute_hash(const std::string& algorithm = "sha256") {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        if (algorithm == "sha256") {
            SHA256_CTX sha256;
            SHA256_Init(&sha256);
            SHA256_Update(&sha256, data.data(), data.size());
            SHA256_Final(hash, &sha256);
        }
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }

    std::string compute_hmac(const std::string& key, const std::string& algorithm = "sha256") {
        unsigned char hmac[SHA256_DIGEST_LENGTH];
        if (algorithm == "sha256") {
            HMAC_CTX* hmac_ctx = HMAC_CTX_new();
            HMAC_Init_ex(hmac_ctx, key.c_str(), key.size(), EVP_sha256(), NULL);
            HMAC_Update(hmac_ctx, data.data(), data.size());
            HMAC_Final_ex(hmac_ctx, hmac, &SHA256_DIGEST_LENGTH);
            HMAC_CTX_free(hmac_ctx);
        }
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hmac[i];
        }
        return ss.str();
    }
};

class CipherSimulator {
public:
    std::vector<unsigned char> data;

    CipherSimulator(const std::vector<unsigned char>& data) : data(data) {}

    std::vector<unsigned char> xor_cipher(unsigned char key) {
        std::vector<unsigned char> result;
        for (unsigned char b : data) {
            result.push_back(b ^ key);
        }
        return result;
    }

    std::vector<unsigned char> caesar_cipher(int shift) {
        std::vector<unsigned char> result;
        for (unsigned char b : data) {
            if (65 <= b && b <= 90) {
                result.push_back(((b - 65 + shift) % 26) + 65);
            } else {
                result.push_back(b);
            }
        }
        return result;
    }
};

void data_mutations() {
    std::vector<unsigned char> data(32);
    for (auto& byte : data) {
        byte = static_cast<unsigned char>(rand() % 256);
    }
    HashSimulator hash_simulator(data);
    CipherSimulator cipher_simulator(data);
    std::string hash_result = hash_simulator.compute_hash();
    std::string hmac_result = hash_simulator.compute_hmac("secret_key");
    std::vector<unsigned char> xor_result = cipher_simulator.xor_cipher(170);
    std::vector<unsigned char> caesar_result = cipher_simulator.caesar_cipher(3);
    std::cout << "Hash: " << hash_result << std::endl;
    std::cout << "HMAC: " << hmac_result << std::endl;
    std::cout << "XOR Cipher: ";
    for (unsigned char b : xor_result) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)b;
    }
    std::cout << std::endl;
    std::cout << "Caesar Cipher: ";
    for (unsigned char b : caesar_result) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)b;
    }
    std::cout << std::endl;
}

int main() {
    data_mutations();
    return 0;
}