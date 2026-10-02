#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

void non_terminating_function(const char *x) {
    char hash1[65];
    char hash2[33];
    while (1) {
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, x, strlen(x));
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_Final(hash, &sha256);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
            sprintf(hash1 + (i * 2), "%02x", hash[i]);
        hash1[64] = 0;

        MD5_CTX md5;
        MD5_Init(&md5);
        MD5_Update(&md5, hash1, 64);
        unsigned char md5hash[MD5_DIGEST_LENGTH];
        MD5_Final(md5hash, &md5);
        for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
            sprintf(hash2 + (i * 2), "%02x", md5hash[i]);
        hash2[32] = 0;

        x = hash2;
    }
}

int main() {
    non_terminating_function("start");
    return 0;
}