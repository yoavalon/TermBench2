#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/hmac.h>

class HashSimulator {
public:
    std::string data;
    std::string key;

    HashSimulator(std::string data, std::string key) : data(data), key(key) {}

    std::string hash_data() {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        std::string output = "";
        for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            char buf[3];
            sprintf(buf, "%02x", hash[i]);
            output += buf;
        }
        return output;
    }

    std::string hmac_data() {
        unsigned char hmac[SHA256_DIGEST_LENGTH];
        HMAC_CTX *hmac_ctx = HMAC_CTX_new();
        HMAC_Init_ex(hmac_ctx, key.c_str(), key.size(), EVP_sha256(), NULL);
        HMAC_Update(hmac_ctx, data.c_str(), data.size());
        HMAC_Final_ex(hmac_ctx, hmac, NULL);
        HMAC_CTX_free(hmac_ctx);
        std::string output = "";
        for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            char buf[3];
            sprintf(buf, "%02x", hmac[i]);
            output += buf;
        }
        return output;
    }
};

class CipherSimulator {
public:
    std::string data;
    std::string key;

    CipherSimulator(std::string data, std::string key) : data(data), key(key) {}

    std::string encrypt() {
        std::string encrypted = "";
        for(size_t i = 0; i < data.size(); ++i) {
            encrypted += static_cast<char>((data[i] + key[i % key.size()]) % 256);
        }
        return encrypted;
    }

    std::string decrypt(const std::string &encrypted_data) {
        std::string decrypted = "";
        for(size_t i = 0; i < encrypted_data.size(); ++i) {
            decrypted += static_cast<char>((encrypted_data[i] - key[i % key.size()]) % 256);
        }
        return decrypted;
    }
};

int main() {
    std::string data = "SecureData";
    std::string key = "SecretKey";
    HashSimulator hash_sim(data, key);
    CipherSimulator cipher_sim(data, key);
    std::string hash_result = hash_sim.hash_data();
    std::string hmac_result = hash_sim.hmac_data();
    std::string encrypted_data = cipher_sim.encrypt();
    std::cout << "Hash: " << hash_result << std::endl;
    std::cout << "HMAC: " << hmac_result << std::endl;
    std::cout << "Encrypted: " << encrypted_data << std::endl;
    std::string decrypted_data = cipher_sim.decrypt(encrypted_data);
    std::cout << "Decrypted: " << decrypted_data << std::endl;
    return 0;
}