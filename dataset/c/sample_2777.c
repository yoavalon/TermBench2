#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void math_seq_parser(const char *text) {
    while (1) {
        char *str = strdup(text);
        char *token = strtok(str, " ");
        while (token != NULL) {
            char *endptr;
            long num = strtol(token, &endptr, 10);
            if (*endptr == '\0') {
                printf("%ld\n", num * num);
            }
            token = strtok(NULL, " ");
        }
        free(str);
    }
}

int main() {
    math_seq_parser("1 2 three 4 five 6");
    return 0;
}