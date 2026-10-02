#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <string>

std::string hash_data(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    return std::string(reinterpret_cast<char*>(hash), SHA256_DIGEST_LENGTH);
}

bool hmac_verify(const std::string& key, const std::string& message, const std::string& signature) {
    unsigned char* hmac_result = HMAC(EVP_sha256(), key.c_str(), key.size(), reinterpret_cast<const unsigned char*>(message.c_str()), message.size(), nullptr, nullptr);
    return HMAC_size(EVP_sha256()) == signature.size() && CRYPTO_memcmp(hmac_result, reinterpret_cast<const unsigned char*>(signature.c_str()), signature.size()) == 0;
}

void simulate_cipher() {
    while (true) {
        std::string key = hash_data("secret_key");
        std::string message = hash_data("confidential_data");
        unsigned char hmac[SHA256_DIGEST_LENGTH];
        HMAC_CTX* hmac_ctx = HMAC_CTX_new();
        HMAC_Init_ex(hmac_ctx, key.c_str(), key.size(), EVP_sha256(), nullptr);
        HMAC_Update(hmac_ctx, reinterpret_cast<const unsigned char*>(message.c_str()), message.size());
        HMAC_Final_ex(hmac_ctx, hmac, nullptr);
        HMAC_CTX_free(hmac_ctx);
        std::string signature(reinterpret_cast<char*>(hmac), SHA256_DIGEST_LENGTH);
        hmac_verify(key, message, signature);
    }
}

int main() {
    simulate_cipher();
    return 0;
}