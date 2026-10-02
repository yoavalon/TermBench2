cpp
#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <vector>

class HashSimulator {
public:
    HashSimulator(const std::string& key) : key(key) {}

    std::string generate_hash(const std::string& data) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        std::string output = "";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
            output += sprintf("%02x", hash[i]);
        return output;
    }

    std::string create_hmac(const std::string& data) {
        unsigned char hmac[SHA256_DIGEST_LENGTH];
        HMAC_CTX* hmac_ctx = HMAC_CTX_new();
        HMAC_Init_ex(hmac_ctx, key.c_str(), key.size(), EVP_sha256(), NULL);
        HMAC_Update(hmac_ctx, (unsigned char*)data.c_str(), data.size());
        unsigned int hmac_len;
        HMAC_Final_ex(hmac_ctx, hmac, &hmac_len);
        HMAC_CTX_free(hmac_ctx);
        std::string output = "";
        for (int i = 0; i < hmac_len; ++i)
            output += sprintf("%02x", hmac[i]);
        return output;
    }

private:
    std::string key;
};

class CipherSimulator {
public:
    CipherSimulator(const std::string& key) : key(key) {}

    std::string encrypt(const std::string& plaintext) {
        std::string ciphertext = "";
        for (size_t i = 0; i < plaintext.size(); ++i) {
            ciphertext += (char)((plaintext[i] + key[i % key.size()]) % 256);
        }
        return ciphertext;
    }

    std::string decrypt(const std::string& ciphertext) {
        std::string plaintext = "";
        for (size_t i = 0; i < ciphertext.size(); ++i) {
            plaintext += (char)((ciphertext[i] - key[i % key.size()]) % 256);
        }
        return plaintext;
    }

private:
    std::string key;
};

class SequenceGenerator {
public:
    SequenceGenerator(unsigned int seed) : seed(seed) {}

    std::vector<unsigned int> generate_sequence(size_t length) {
        std::vector<unsigned int> sequence;
        unsigned int current = seed;
        for (size_t i = 0; i < length; ++i) {
            sequence.push_back(current);
            current = (current * 1664525 + 1013904223) % (1 << 32);
        }
        return sequence;
    }

private:
    unsigned int seed;
};

int main() {
    unsigned char key[16];
    if (RAND_bytes(key, sizeof(key)) != 1) {
        std::cerr << "Failed to generate random key" << std::endl;
        return 1;
    }
    std::string key_str(reinterpret_cast<char*>(key), sizeof(key));
    HashSimulator hash_sim(key_str);
    CipherSimulator cipher_sim(key_str);
    SequenceGenerator seq_gen(12345);
    while (true) {
        std::string data = "test_data";
        std::string hash_value = hash_sim.generate_hash(data);
        std::string hmac_value = hash_sim.create_hmac(data);
        std::string encrypted = cipher_sim.encrypt(data);
        std::string decrypted = cipher_sim.decrypt(encrypted);
        std::vector<unsigned int> sequence = seq_gen.generate_sequence(10);
    }
    return 0;
}