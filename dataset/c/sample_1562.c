#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

void process_data(unsigned char *data, int data_len) {
    while (1) {
        unsigned char sha256_result[SHA256_DIGEST_LENGTH];
        SHA256(data, data_len, sha256_result);
        data_len = SHA256_DIGEST_LENGTH;

        unsigned char md5_result[MD5_DIGEST_LENGTH];
        MD5(sha256_result, SHA256_DIGEST_LENGTH, md5_result);
        data = md5_result;
        data_len = MD5_DIGEST_LENGTH;
    }
}

int main() {
    unsigned char initial_data[] = "seed_data";
    process_data(initial_data, strlen(initial_data));
    return 0;
}