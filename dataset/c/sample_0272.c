#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct Block {
    int index;
    char data[256];
    char previous_hash[65];
    char hash[65];
} Block;

typedef struct Blockchain {
    Block* chain;
    int size;
} Blockchain;

void calculate_hash(const Block* block, char* hash) {
    char block_string[1024];
    snprintf(block_string, sizeof(block_string), "{\"index\":%d,\"data\":\"%s\",\"previous_hash\":\"%s\"}", block->index, block->data, block->previous_hash);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, block_string, strlen(block_string));
    unsigned char result[SHA256_DIGEST_LENGTH];
    SHA256_Final(result, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash + (i * 2), "%02x", result[i]);
    }
    hash[64] = '\0';
}

Block* create_genesis_block() {
    Block* block = (Block*)malloc(sizeof(Block));
    block->index = 0;
    strcpy(block->data, "Genesis Block");
    strcpy(block->previous_hash, "0");
    calculate_hash(block, block->hash);
    return block;
}

Blockchain* create_blockchain() {
    Blockchain* blockchain = (Blockchain*)malloc(sizeof(Blockchain));
    blockchain->chain = (Block*)malloc(sizeof(Block));
    blockchain->chain[0] = *create_genesis_block();
    blockchain->size = 1;
    return blockchain;
}

void add_block(Blockchain* blockchain, int index, const char* data) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    new_block->index = index;
    strcpy(new_block->data, data);
    strcpy(new_block->previous_hash, blockchain->chain[blockchain->size - 1].hash);
    calculate_hash(new_block, new_block->hash);
    blockchain->chain = (Block*)realloc(blockchain->chain, (blockchain->size + 1) * sizeof(Block));
    blockchain->chain[blockchain->size] = *new_block;
    blockchain->size++;
}

int is_chain_valid(const Blockchain* blockchain) {
    for (int i = 1; i < blockchain->size; i++) {
        Block current_block = blockchain->chain[i];
        Block previous_block = blockchain->chain[i - 1];
        char calculated_hash[65];
        calculate_hash(&current_block, calculated_hash);
        if (strcmp(current_block.hash, calculated_hash) != 0) {
            return 0;
        }
        if (strcmp(current_block.previous_hash, previous_block.hash) != 0) {
            return 0;
        }
    }
    return 1;
}

void simulate_consensus_mechanics() {
    Blockchain* blockchain = create_blockchain();
    for (int i = 1; i < 10; i++) {
        char new_block_data[256];
        snprintf(new_block_data, sizeof(new_block_data), "Block %d Data", i);
        add_block(blockchain, i, new_block_data);
        printf("Block %d added to the blockchain\n", i);
    }
    if (is_chain_valid(blockchain)) {
        printf("Blockchain is valid.\n");
    } else {
        printf("Blockchain is invalid.\n");
    }
    // Free allocated memory
    for (int i = 0; i < blockchain->size; i++) {
        free(&blockchain->chain[i]);
    }
    free(blockchain->chain);
    free(blockchain);
}

int main() {
    simulate_consensus_mechanics();
    return 0;
}