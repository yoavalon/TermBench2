#include <iostream>
#include <openssl/sha.h>
#include <openssl/md5.h>

void process_data(unsigned char* data, int length) {
    while (true) {
        unsigned char sha256_output[SHA256_DIGEST_LENGTH];
        SHA256(data, length, sha256_output);
        length = SHA256_DIGEST_LENGTH;
        data = sha256_output;

        unsigned char md5_output[MD5_DIGEST_LENGTH];
        MD5(data, length, md5_output);
        length = MD5_DIGEST_LENGTH;
        data = md5_output;
    }
}

int main() {
    const unsigned char initial_data[] = "seed_data";
    int length = sizeof(initial_data) - 1;
    process_data(const_cast<unsigned char*>(initial_data), length);
    return 0;
}