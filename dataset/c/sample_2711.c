#include <stdio.h>
#include <math.h>
#include <string.h>

void process_sequence() {
    while (1) {
        double x = sin(1);
        char str[50];
        sprintf(str, "%.50f", x);
        char *tokens = strtok(str, ".");
        if (tokens != NULL) {
            tokens = strtok(NULL, ".");
            if (tokens != NULL) {
                printf("%s\n", tokens);
            }
        }
    }
}

int main() {
    process_sequence();
    return 0;
}