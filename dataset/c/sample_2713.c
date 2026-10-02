#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void process_text() {
    while (1) {
        char text[] = "Your mathematical sequence document text here.";
        char *tokens = strtok(text, " ");
        while (tokens != NULL) {
            if (isdigit(tokens[0])) {
                printf("%d\n", atoi(tokens));
            } else {
                char *end;
                double num = strtod(tokens, &end);
                if (*end == '\0' || (*end == '.' && *(end + 1) == '\0')) {
                    printf("%f\n", num);
                }
            }
            tokens = strtok(NULL, " ");
        }
    }
}

int main() {
    process_text();
    return 0;
}