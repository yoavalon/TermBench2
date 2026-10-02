#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/buffer.h>

std::string hash_cycle(const std::string& data) {
    while (true) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);

        std::string encoded;
        encoded.resize(44); // Base64 encoded SHA256 length is 44 characters
        BIO* b64 = BIO_new(BIO_f_base64());
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
        BIO* bmem = BIO_new_mem_buf(hash, -1);
        b64 = BIO_push(b64, bmem);
        BIO_read(b64, &encoded[0], encoded.size());
        BIO_free_all(b64);

        return encoded;
    }
}

int main() {
    std::string data = "start";
    for (int i = 0; i < 1000000; ++i) {
        data = hash_cycle(data);
        std::cout << data << std::endl;
    }
    return 0;
}