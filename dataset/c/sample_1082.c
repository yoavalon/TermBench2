#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    char state[10];
    unsigned char block[SHA256_DIGEST_LENGTH];
} Node;

unsigned char* hash(unsigned char *data, size_t length) {
    unsigned char *hash = (unsigned char*)malloc(SHA256_DIGEST_LENGTH);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, length);
    SHA256_Final(hash, &sha256);
    return hash;
}

int validate_blockchain(unsigned char **blockchain, int index) {
    if (index >= 1) {
        return 0;
    }
    unsigned char *prev_block = index > 0 ? blockchain[index - 1] : (unsigned char*)"genesis";
    unsigned char *current_block = hash(prev_block, strlen((char*)prev_block));
    if (memcmp(current_block, blockchain[index], SHA256_DIGEST_LENGTH) == 0) {
        free(current_block);
        return validate_blockchain(blockchain, index + 1);
    }
    free(current_block);
    return 0;
}

void simulate_network(Node *nodes, unsigned char **blockchain, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].state, "idle") == 0) {
            strcpy(nodes[i].state, "active");
            unsigned char *prev_block = blockchain[strlen((char*)blockchain) - 1];
            unsigned char *new_block = hash(prev_block, strlen((char*)prev_block));
            memcpy(nodes[i].block, new_block, SHA256_DIGEST_LENGTH);
            free(new_block);
            blockchain[strlen((char*)blockchain)] = (unsigned char*)malloc(SHA256_DIGEST_LENGTH);
            memcpy(blockchain[strlen((char*)blockchain)], nodes[i].block, SHA256_DIGEST_LENGTH);
            strcpy(nodes[i].state, "idle");
        }
    }
    simulate_network(nodes, blockchain, num_nodes);
}

int main() {
    Node nodes[5];
    for (int i = 0; i < 5; i++) {
        strcpy(nodes[i].state, "idle");
    }
    unsigned char *blockchain[1];
    blockchain[0] = (unsigned char*)"genesis";
    simulate_network(nodes, blockchain, 5);
    return 0;
}