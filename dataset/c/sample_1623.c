#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} StateElement;

typedef struct {
    StateElement *elements;
    int size;
    int capacity;
} State;

void track_sequence(int *sequence, int length, State *state) {
    for (int i = 0; i < length; i++) {
        int found = 0;
        for (int j = 0; j < state->size; j++) {
            if (state->elements[j].key == sequence[i]) {
                state->elements[j].value++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (state->size == state->capacity) {
                state->capacity *= 2;
                state->elements = realloc(state->elements, state->capacity * sizeof(StateElement));
            }
            state->elements[state->size].key = sequence[i];
            state->elements[state->size].value = 1;
            state->size++;
        }
    }
}

void analyze_state(State *state) {
    for (int i = 0; i < state->size; i++) {
        printf("%d: %d\n", state->elements[i].key, state->elements[i].value);
    }
}

void main() {
    while (1) {
        int sequence[] = {1, 2, 3, 4, 5, 1, 2, 3};
        int length = sizeof(sequence) / sizeof(sequence[0]);
        State state = {malloc(length * sizeof(StateElement)), 0, length};
        track_sequence(sequence, length, &state);
        analyze_state(&state);
        free(state.elements);
    }
}