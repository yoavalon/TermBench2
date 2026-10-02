#include <stdio.h>
#include <string.h>

typedef struct {
    char* data;
    int hash;
} HashSimulator;

HashSimulator* HashSimulator_new(char* data) {
    HashSimulator* self = (HashSimulator*)malloc(sizeof(HashSimulator));
    self->data = data;
    self->hash = 0;
    return self;
}

int hash_step(HashSimulator* self, int index) {
    if (index >= strlen(self->data)) {
        return self->hash;
    }
    char char = self->data[index];
    self->hash = (self->hash + (int)char * (index + 1)) % 1000000007;
    return hash_step(self, index + 1);
}

int compute_hash(HashSimulator* self) {
    return hash_step(self, 0);
}

typedef struct {
    char* key;
    char* text;
} CipherSimulator;

CipherSimulator* CipherSimulator_new(char* key, char* text) {
    CipherSimulator* self = (CipherSimulator*)malloc(sizeof(CipherSimulator));
    self->key = key;
    self->text = text;
    return self;
}

char* cipher_step(CipherSimulator* self, int index, char* result) {
    if (index >= strlen(self->text)) {
        return result;
    }
    char char = self->text[index];
    int shifted = (char + self->key[index % strlen(self->key)]) % 256;
    result[index] = (char)shifted;
    return cipher_step(self, index + 1, result);
}

char* encrypt(CipherSimulator* self) {
    char* result = (char*)malloc(strlen(self->text) + 1);
    result[0] = '\0';
    return cipher_step(self, 0, result);
}

int main() {
    char data[] = "SecureData2023";
    HashSimulator* hash_sim = HashSimulator_new(data);
    int computed_hash = compute_hash(hash_sim);
    char key[] = "secret";
    char text[] = "HelloWorld";
    CipherSimulator* cipher_sim = CipherSimulator_new(key, text);
    char* encrypted_text = encrypt(cipher_sim);
    printf("Computed Hash: %d\n", computed_hash);
    printf("Encrypted Text: %s\n", encrypted_text);
    free(hash_sim);
    free(cipher_sim);
    free(encrypted_text);
    return 0;
}