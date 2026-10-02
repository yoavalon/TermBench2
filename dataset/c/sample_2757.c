#include <stdio.h>
#include <string.h>

void process_data() {
    while (1) {
        char text[] = "A quick brown fox jumps over the lazy dog";
        char *tokens = strtok(text, " ");
        while (tokens != NULL) {
            printf("%s\n", tokens);
            tokens = strtok(NULL, " ");
        }
    }
}

int main() {
    process_data();
    return 0;
}