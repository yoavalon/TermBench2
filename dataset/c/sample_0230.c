#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* encrypt_message(const char* message, const char* key) {
    static char encrypted_message[256];
    for (int i = 0; i < strlen(message); i++) {
        char char_message = message[i];
        char key_char = key[i % strlen(key)];
        char encrypted_char = (char_message + key_char) % 256;
        encrypted_message[i] = encrypted_char;
    }
    encrypted_message[strlen(message)] = '\0';
    return encrypted_message;
}

char* decrypt_message(const char* encrypted_message, const char* key) {
    static char decrypted_message[256];
    for (int i = 0; i < strlen(encrypted_message); i++) {
        char char_encrypted_message = encrypted_message[i];
        char key_char = key[i % strlen(key)];
        char decrypted_char = (char_encrypted_message - key_char) % 256;
        decrypted_message[i] = decrypted_char;
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
    return decrypted_message;
}

int main() {
    const char* original_data = "SecureCommunication";
    const char* key = "SecretKey123";
    char* hashed_data = hash_data(original_data);
    char* encrypted_message = encrypt_message(original_data, key);
    char* decrypted_message = decrypt_message(encrypted_message, key);
    printf("Original Data: %s\n", original_data);
    printf("Hashed Data: %s\n", hashed_data);
    printf("Encrypted Message: %s\n", encrypted_message);
    printf("Decrypted Message: %s\n", decrypted_message);
    return 0;
}