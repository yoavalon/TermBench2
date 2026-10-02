#include <stdio.h>
#include <string.h>

char* state_handler(char* state, int* data) {
    if (strcmp(state, "init") == 0) {
        strcpy(state, "connecting");
        (*data)++;
    } else if (strcmp(state, "connecting") == 0) {
        if (*data % 2 == 0) {
            strcpy(state, "connected");
            (*data)++;
        } else {
            strcpy(state, "failed");
            (*data)++;
        }
    } else if (strcmp(state, "connected") == 0) {
        strcpy(state, "data_exchange");
        (*data)++;
    } else if (strcmp(state, "data_exchange") == 0) {
        strcpy(state, "disconnecting");
        (*data)++;
    } else if (strcmp(state, "disconnecting") == 0) {
        strcpy(state, "init");
        (*data)++;
    } else if (strcmp(state, "failed") == 0) {
        strcpy(state, "retry");
        (*data)++;
    } else if (strcmp(state, "retry") == 0) {
        if (*data % 3 == 0) {
            strcpy(state, "connecting");
            (*data)++;
        } else {
            strcpy(state, "failed");
            (*data)++;
        }
    }
    return state;
}

int main() {
    char state[] = "init";
    int data = 0;
    while (1) {
        state_handler(state, &data);
    }
    return 0;
}