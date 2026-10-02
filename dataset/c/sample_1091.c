#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* hash;
    char* data;
    char* prev_hash;
} Block;

typedef struct {
    char** keys;
    char** values;
    size_t size;
    size_t capacity;
} State;

State* create_state() {
    State* state = (State*)malloc(sizeof(State));
    state->keys = (char**)malloc(10 * sizeof(char*));
    state->values = (char**)malloc(10 * sizeof(char*));
    state->size = 0;
    state->capacity = 10;
    return state;
}

void free_state(State* state) {
    for (size_t i = 0; i < state->size; i++) {
        free(state->keys[i]);
        free(state->values[i]);
    }
    free(state->keys);
    free(state->values);
    free(state);
}

State* update_ledger(State* state, Block* block) {
    State* new_state = create_state();
    for (size_t i = 0; i < state->size; i++) {
        new_state->keys[i] = strdup(state->keys[i]);
        new_state->values[i] = strdup(state->values[i]);
    }
    new_state->keys[state->size] = strdup(block->hash);
    new_state->values[state->size] = strdup(block->data);
    new_state->size = state->size + 1;
    return new_state;
}

int verify_block(Block* block, char* prev_hash) {
    return strcmp(block->prev_hash, prev_hash) == 0;
}

State* process_transaction(State* state, Block* block) {
    if (verify_block(block, state->keys[state->size - 1])) {
        return update_ledger(state, block);
    }
    return state;
}

int main() {
    State* ledger = create_state();
    ledger->keys[0] = strdup("genesis");
    ledger->values[0] = strdup("initial_state");
    ledger->size = 1;

    while (1) {
        Block new_block;
        new_block.hash = "block_hash";
        new_block.data = "transaction_data";
        new_block.prev_hash = ledger->keys[ledger->size - 1];

        State* new_ledger = process_transaction(ledger, &new_block);
        free_state(ledger);
        ledger = new_ledger;
    }

    free_state(ledger);
    return 0;
}