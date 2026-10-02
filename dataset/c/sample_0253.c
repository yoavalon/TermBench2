#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct Node {
    char* data;
    char* hash;
    char* previous_hash;
} Node;

typedef struct Blockchain {
    Node* chain;
    int length;
} Blockchain;

void calculate_hash(Node* node) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, node->data, strlen(node->data));
    SHA256_Final(hash, &sha256);
    node->hash = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&node->hash[i * 2], "%02x", hash[i]);
    }
}

Node* create_node(char* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = strdup(data);
    node->hash = NULL;
    node->previous_hash = NULL;
    calculate_hash(node);
    return node;
}

Blockchain* create_blockchain() {
    Blockchain* blockchain = (Blockchain*)malloc(sizeof(Blockchain));
    blockchain->chain = (Node*)malloc(sizeof(Node));
    blockchain->length = 1;
    blockchain->chain[0] = *create_node("Genesis Block");
    return blockchain;
}

void add_block(Blockchain* blockchain, Node* new_block) {
    new_block->previous_hash = blockchain->chain[blockchain->length - 1].hash;
    blockchain->chain = (Node*)realloc(blockchain->chain, (blockchain->length + 1) * sizeof(Node));
    blockchain->chain[blockchain->length] = *new_block;
    blockchain->length++;
    calculate_hash(new_block);
}

int is_chain_valid(Blockchain* blockchain) {
    for (int i = 1; i < blockchain->length; i++) {
        Node* current_block = &blockchain->chain[i];
        Node* previous_block = &blockchain->chain[i - 1];
        unsigned char current_hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, current_block->data, strlen(current_block->data));
        SHA256_Final(current_hash, &sha256);
        char calculated_hash[SHA256_DIGEST_LENGTH * 2 + 1];
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&calculated_hash[j * 2], "%02x", current_hash[j]);
        }
        if (strcmp(current_block->hash, calculated_hash) != 0) {
            return 0;
        }
        if (strcmp(current_block->previous_hash, previous_block->hash) != 0) {
            return 0;
        }
    }
    return 1;
}

void main() {
    Blockchain* blockchain = create_blockchain();
    for (int i = 0; i < 10; i++) {
        char new_data[20];
        sprintf(new_data, "Block %d", i);
        Node* new_block = create_node(new_data);
        add_block(blockchain, new_block);
    }
    printf("Blockchain valid: %d\n", is_chain_valid(blockchain));
}