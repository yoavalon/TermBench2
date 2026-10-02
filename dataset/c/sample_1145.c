#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
} HashSimulator;

int _hash(HashSimulator* self, int index) {
    if (index < strlen(self->data)) {
        return (self->data[index] + _hash(self, index + 1)) % 1000000;
    }
    return 0;
}

int hash(HashSimulator* self) {
    return _hash(self, 0);
}

typedef struct {
    int key;
} CipherSimulator;

int _encrypt(CipherSimulator* self, char* data, int index) {
    if (index < strlen(data)) {
        return (data[index] + self->key + _encrypt(self, data, index + 1)) % 256;
    }
    return 0;
}

int encrypt(CipherSimulator* self, char* data) {
    return _encrypt(self, data, 0);
}

typedef struct {
    HashSimulator hash_sim;
    CipherSimulator cipher_sim;
} RecurringProcess;

void process(RecurringProcess* self) {
    while (1) {
        int hash_value = hash(&self->hash_sim);
        char encrypted_data_str[2];
        encrypted_data_str[0] = (char)encrypt(&self->cipher_sim, (char[]){hash_value, '\0'});
        encrypted_data_str[1] = '\0';
        self->hash_sim = (HashSimulator){.data = encrypted_data_str};
        char hash_value_str[12];
        sprintf(hash_value_str, "%d", hash_value);
        self->cipher_sim = (CipherSimulator){.key = encrypt(&self->cipher_sim, hash_value_str)};
    }
}

int main() {
    HashSimulator hash_sim = (HashSimulator){.data = "start"};
    CipherSimulator cipher_sim = (CipherSimulator){.key = 7};
    RecurringProcess process = (RecurringProcess){.hash_sim = hash_sim, .cipher_sim = cipher_sim};
    process(&process);
    return 0;
}