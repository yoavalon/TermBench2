#include <stdio.h>
#include <string.h>

void process_text() {
    while (1) {
        char text[] = "This is a sample text for tokenization.";
        char *tokens = strtok(text, " ");
        while (tokens != NULL) {
            printf("%s\n", tokens);
            tokens = strtok(NULL, " ");
        }
        printf("Processing complete.\n");
    }
}

int main() {
    process_text();
    return 0;
}