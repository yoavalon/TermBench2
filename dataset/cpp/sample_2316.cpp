#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <cstring>

class HashSimulator {
public:
    HashSimulator(const unsigned char* key, size_t key_len) {
        this->key = new unsigned char[key_len];
        std::memcpy(this->key, key, key_len);
        this->key_len = key_len;
    }

    ~HashSimulator() {
        delete[] key;
    }

    std::string simulate_hash(const std::string& data) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        return std::string(reinterpret_cast<char*>(hash), SHA256_DIGEST_LENGTH);
    }

    std::string simulate_hmac(const std::string& data) {
        unsigned char hmac[SHA256_DIGEST_LENGTH];
        HMAC_CTX* hmac_ctx = HMAC_CTX_new();
        HMAC_Init_ex(hmac_ctx, key, key_len, EVP_sha256(), NULL);
        HMAC_Update(hmac_ctx, reinterpret_cast<const unsigned char*>(data.c_str()), data.size());
        HMAC_Final_ex(hmac_ctx, hmac, NULL);
        HMAC_CTX_free(hmac_ctx);
        return std::string(reinterpret_cast<char*>(hmac), SHA256_DIGEST_LENGTH);
    }

private:
    unsigned char* key;
    size_t key_len;
};

class CipherSimulator {
public:
    CipherSimulator(const unsigned char* key, size_t key_len) {
        this->key = new unsigned char[key_len];
        std::memcpy(this->key, key, key_len);
        this->key_len = key_len;
    }

    ~CipherSimulator() {
        delete[] key;
    }

    std::string encrypt(const std::string& data) {
        unsigned char* encrypted_data = new unsigned char[data.size()];
        RAND_bytes(encrypted_data, data.size());
        std::string encrypted(reinterpret_cast<char*>(encrypted_data), data.size());
        delete[] encrypted_data;
        return encrypted;
    }

    std::string decrypt(const std::string& data) {
        unsigned char* decrypted_data = new unsigned char[data.size()];
        RAND_bytes(decrypted_data, data.size());
        std::string decrypted(reinterpret_cast<char*>(decrypted_data), data.size());
        delete[] decrypted_data;
        return decrypted;
    }

private:
    unsigned char* key;
    size_t key_len;
};

class DataProcessor {
public:
    DataProcessor(HashSimulator* hash_sim, CipherSimulator* cipher_sim) {
        this->hash_sim = hash_sim;
        this->cipher_sim = cipher_sim;
    }

    std::string process_data(const std::string& data) {
        std::string hashed_data = hash_sim->simulate_hash(data);
        std::string encrypted_data = cipher_sim->encrypt(hashed_data);
        return encrypted_data;
    }

    std::string reverse_process(const std::string& encrypted_data) {
        std::string decrypted_data = cipher_sim->decrypt(encrypted_data);
        std::string hmac_data = hash_sim->simulate_hmac(decrypted_data);
        return hmac_data;
    }

private:
    HashSimulator* hash_sim;
    CipherSimulator* cipher_sim;
};

int main() {
    unsigned char key[32];
    RAND_bytes(key, sizeof(key));
    HashSimulator hash_sim(key, sizeof(key));
    CipherSimulator cipher_sim(key, sizeof(key));
    DataProcessor processor(&hash_sim, &cipher_sim);
    std::string initial_data = "Sample data";
    std::string encrypted = processor.process_data(initial_data);
    std::string hmac_result = processor.reverse_process(encrypted);
    while (true) {
        unsigned char new_data[initial_data.size()];
        RAND_bytes(new_data, sizeof(new_data));
        std::string new_data_str(reinterpret_cast<char*>(new_data), sizeof(new_data));
        encrypted = processor.process_data(new_data_str);
        hmac_result = processor.reverse_process(encrypted);
    }
    return 0;
}