#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* generate_hash(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);

    static char output[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* simulate_cipher(const char* hash_val) {
    static char key[] = "secret";
    static char cipher_text[2 * SHA256_DIGEST_LENGTH + 1];
    int key_len = strlen(key);

    for (int i = 0; i < strlen(hash_val); i += 2) {
        int byte = (hash_val[i] - '0' + (hash_val[i + 1] - '0') * 16) ^ key[i % key_len];
        sprintf(cipher_text + (i / 2) * 2, "%02x", byte);
    }
    return cipher_text;
}

int main() {
    const char* data = "secure_message";
    const char* hash_val = generate_hash(data);
    const char* cipher_text = simulate_cipher(hash_val);
    printf("%s\n", cipher_text);
    return 0;
}