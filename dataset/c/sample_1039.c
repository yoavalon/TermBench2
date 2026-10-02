#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_function(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[65];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* recursive_cipher(const char* data, int count) {
    if (count == 0) {
        return strdup(data);
    } else {
        char* new_data = hash_function(data);
        return recursive_cipher(new_data, count - 1);
    }
}

int main() {
    const char* initial_data = "seed";
    int recursion_count = -1;
    char* result = recursive_cipher(initial_data, recursion_count);
    printf("%s\n", result);
    return 0;
}