#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include <openssl/hmac.h>

std::string process_data(const std::string& x) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x.c_str(), x.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    std::string h = ss.str();
    unsigned char c[HMAC_MAX_MD_SIZE];
    unsigned int c_len;
    const unsigned char* k = (const unsigned char*)"secret_key";
    HMAC_CTX* hmac_ctx = HMAC_CTX_new();
    HMAC_Init_ex(hmac_ctx, k, 10, EVP_sha256(), NULL);
    HMAC_Update(hmac_ctx, (const unsigned char*)h.c_str(), h.size());
    HMAC_Final_ex(hmac_ctx, c, &c_len);
    HMAC_CTX_free(hmac_ctx);
    std::stringstream ss2;
    for (int i = 0; i < c_len; i++) {
        ss2 << std::hex << std::setw(2) << std::setfill('0') << (int)c[i];
    }
    return ss2.str();
}

int main() {
    std::string data = "input_data";
    std::string result = process_data(data);
    std::cout << result << std::endl;
    return 0;
}