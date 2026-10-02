#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <algorithm>

class HashSimulator {
public:
    HashSimulator(const std::string& key, const std::string& message) : key(key), message(message) {}

    std::string hash_message() {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, message.c_str(), message.size());
        SHA256_Final(hash, &sha256);
        std::string output = "";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            output += sprintf("%02x", hash[i]);
        }
        return output;
    }

    std::string hmac_message() {
        unsigned char hmac[SHA256_DIGEST_LENGTH];
        HMAC_CTX* hmac_ctx = HMAC_CTX_new();
        HMAC_Init_ex(hmac_ctx, key.c_str(), key.size(), EVP_sha256(), NULL);
        HMAC_Update(hmac_ctx, (unsigned char*)message.c_str(), message.size());
        HMAC_Final_ex(hmac_ctx, hmac, NULL);
        HMAC_CTX_free(hmac_ctx);
        std::string output = "";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            output += sprintf("%02x", hmac[i]);
        }
        return output;
    }

private:
    std::string key;
    std::string message;
};

class CipherSimulator {
public:
    CipherSimulator(const std::string& data) : data(data) {}

    std::string xor_cipher(const std::string& key) {
        std::string result = "";
        for (size_t i = 0; i < data.size(); i++) {
            result += (char)(data[i] ^ key[i % key.size()]);
        }
        return result;
    }

    std::string shift_cipher(int shift) {
        std::string result = "";
        for (char c : data) {
            result += (char)((c + shift) % 256);
        }
        return result;
    }

private:
    std::string data;
};

class DataProcessor {
public:
    DataProcessor(HashSimulator& hash_simulator, CipherSimulator& cipher_simulator) 
        : hash_simulator(hash_simulator), cipher_simulator(cipher_simulator) {}

    std::tuple<std::string, std::string, std::string> process_data() {
        std::string hash_result = hash_simulator.hash_message();
        std::string hmac_result = hash_simulator.hmac_message();
        std::string xor_result = cipher_simulator.xor_cipher(hash_result.substr(0, 16));
        std::string shift_result = cipher_simulator.shift_cipher(5);
        return std::make_tuple(hmac_result, xor_result, shift_result);
    }

private:
    HashSimulator& hash_simulator;
    CipherSimulator& cipher_simulator;
};

void main() {
    unsigned char key[16];
    if (!RAND_bytes(key, sizeof(key))) {
        std::cerr << "Failed to generate random key" << std::endl;
        return;
    }
    std::string key_str(reinterpret_cast<char*>(key), sizeof(key));
    key_str = key_str.substr(0, 16);
    std::string message = "SecureMessage";
    HashSimulator hash_sim(key_str, message);
    CipherSimulator cipher_sim(message);
    DataProcessor data_processor(hash_sim, cipher_sim);
    auto result = data_processor.process_data();
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
}