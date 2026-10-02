#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>

class HashSimulator {
public:
    HashSimulator(const std::vector<unsigned char>& data) : data(data) {}

    std::string generate_hash() {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.data(), data.size());
        SHA256_Final(hash, &sha256);
        std::string output = "";
        for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            output += std::hex << (int)hash[i];
        }
        return output;
    }

    std::string generate_hmac(const std::vector<unsigned char>& key) {
        unsigned char hmac[SHA256_DIGEST_LENGTH];
        HMAC_CTX* hmac_ctx = HMAC_CTX_new();
        HMAC_Init_ex(hmac_ctx, key.data(), key.size(), EVP_sha256(), NULL);
        HMAC_Update(hmac_ctx, data.data(), data.size());
        unsigned int hmac_len;
        HMAC_Final_ex(hmac_ctx, hmac, &hmac_len);
        HMAC_CTX_free(hmac_ctx);
        std::string output = "";
        for(int i = 0; i < hmac_len; i++) {
            output += std::hex << (int)hmac[i];
        }
        return output;
    }

private:
    std::vector<unsigned char> data;
};

class CipherSimulator {
public:
    CipherSimulator(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key) : data(data), key(key) {}

    std::vector<unsigned char> encrypt() {
        std::vector<unsigned char> encrypted(data.size());
        for(size_t i = 0; i < data.size(); i++) {
            encrypted[i] = data[i] ^ key[i % key.size()];
        }
        return encrypted;
    }

    std::vector<unsigned char> decrypt() {
        return encrypt();
    }

private:
    std::vector<unsigned char> data;
    std::vector<unsigned char> key;
};

void main() {
    std::vector<unsigned char> data(32);
    std::vector<unsigned char> key(16);
    if (!RAND_bytes(data.data(), data.size()) || !RAND_bytes(key.data(), key.size())) {
        std::cerr << "Failed to generate random bytes" << std::endl;
        return;
    }
    HashSimulator hash_sim(data);
    CipherSimulator hmac_sim(std::vector<unsigned char>(hash_sim.generate_hash().begin(), hash_sim.generate_hash().end()), key);
    std::vector<unsigned char> encrypted_hmac = hmac_sim.encrypt();
    std::vector<unsigned char> decrypted_hmac = hmac_sim.decrypt();
    std::cout << "Original HMAC: " << hash_sim.generate_hmac(key) << std::endl;
    std::cout << "Encrypted HMAC: ";
    for(auto byte : encrypted_hmac) {
        std::cout << std::hex << (int)byte;
    }
    std::cout << std::endl;
    std::cout << "Decrypted HMAC: ";
    for(auto byte : decrypted_hmac) {
        std::cout << std::hex << (int)byte;
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}