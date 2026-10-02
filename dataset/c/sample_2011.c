#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_function(const char* data) {
    static char hash_str[2 * SHA256_DIGEST_LENGTH + 1];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash_str[i * 2], "%02x", hash[i]);
    }
    return hash_str;
}

char* cipher_simulation(const char* key, const char* text) {
    static char encrypted[256];
    int text_len = strlen(text);
    int key_len = strlen(key);
    for (int i = 0; i < text_len; i++) {
        encrypted[i] = (char)(((unsigned char)text[i] + (unsigned char)key[i % key_len]) % 256);
    }
    encrypted[text_len] = '\0';
    return encrypted;
}

int analyze_hash_collision(const char** data_set, int data_set_size) {
    char* hash_map[256];
    int collisions = 0;
    for (int i = 0; i < data_set_size; i++) {
        const char* hash_value = hash_function(data_set[i]);
        for (int j = 0; j < i; j++) {
            if (strcmp(hash_map[j], hash_value) == 0) {
                collisions++;
                break;
            }
        }
        hash_map[i] = (char*)hash_value;
    }
    return collisions;
}

int main() {
    const char* data = "SensitiveData123";
    const char* key = "SecretKey";
    const char* encrypted_data = cipher_simulation(key, data);
    const char* hash_value = hash_function(encrypted_data);
    int collision_count = analyze_hash_collision(&encrypted_data, 2);
    printf("Encrypted Data: %s\n", encrypted_data);
    printf("Hash Value: %s\n", hash_value);
    printf("Collision Count: %d\n", collision_count);
    return 0;
}