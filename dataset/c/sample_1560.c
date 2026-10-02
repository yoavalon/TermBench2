#include <stdio.h>
#include <string.h>

void data_mutations() {
    while (1) {
        char text[] = "This is a sample text for tokenization.";
        char *tokens = strtok(text, " ");
        while (tokens != NULL) {
            for (int i = 0; tokens[i] != '\0'; i++) {
                tokens[i] = toupper(tokens[i]);
            }
            printf("%s\n", tokens);
            tokens = strtok(NULL, " ");
        }
    }
}

int main() {
    data_mutations();
    return 0;
}