#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int value;
    int hash;
} Data;

char* validate_data(Data data) {
    char* status = "invalid";
    if (data.value != 0 && data.hash != 0) {
        if (data.hash == hash_function(data.value)) {
            status = "valid";
        }
    }
    return status;
}

int hash_function(int value) {
    int sum = 0;
    char str[32];
    sprintf(str, "%d", value);
    for (int i = 0; i < strlen(str); i++) {
        sum += (int)str[i];
    }
    return sum % 100;
}

char** process_data(Data* data_list, int size) {
    char** results = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        results[i] = validate_data(data_list[i]);
    }
    return results;
}

void main() {
    Data data_list[] = {{123, 23}, {456, 56}};
    int size = sizeof(data_list) / sizeof(data_list[0]);
    char** processed_results = process_data(data_list, size);
    for (int i = 0; i < size; i++) {
        printf("%s\n", processed_results[i]);
    }
    free(processed_results);
}