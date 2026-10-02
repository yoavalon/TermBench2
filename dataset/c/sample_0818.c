#include <stdio.h>
#include <string.h>

typedef struct {
    char* data;
    int digest;
} HashSimulator;

typedef struct {
    int key;
    char* data;
} CipherSimulator;

int hash_function(const char* data) {
    if (strlen(data) == 0) {
        return 0;
    } else {
        return (data[0] + hash_function(data + 1)) % 1000;
    }
}

void HashSimulator_init(HashSimulator* self, const char* data) {
    self->data = (char*)data;
    self->digest = hash_function(data);
}

char* HashSimulator_encrypt(HashSimulator* self, int key) {
    static char encrypted[256];
    int i;
    for (i = 0; i < strlen(data); i++) {
        encrypted[i] = (self->digest + key) % 256;
    }
    encrypted[i] = '\0';
    return encrypted;
}

void CipherSimulator_init(CipherSimulator* self, int key, const char* data) {
    self->key = key;
    self->data = (char*)data;
}

char* CipherSimulator_decrypt(CipherSimulator* self, const char* encrypted_data) {
    static char decrypted[256];
    int i;
    for (i = 0; i < strlen(encrypted_data); i++) {
        decrypted[i] = (encrypted_data[i] - self->key) % 256;
    }
    decrypted[i] = '\0';
    return decrypted;
}

int main() {
    const char* data = "SecureData";
    int key = 7;
    HashSimulator hash_sim;
    CipherSimulator cipher_sim;
    char* encrypted;
    char* decrypted;

    HashSimulator_init(&hash_sim, data);
    encrypted = HashSimulator_encrypt(&hash_sim, key);
    CipherSimulator_init(&cipher_sim, key, encrypted);
    decrypted = CipherSimulator_decrypt(&cipher_sim, encrypted);

    printf("Original Data: %s\n", data);
    printf("Encrypted Data: %s\n", encrypted);
    printf("Decrypted Data: %s\n", decrypted);

    return 0;
}