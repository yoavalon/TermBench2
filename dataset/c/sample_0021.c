#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 100

void parse_and_tokenize(char* doc, int max_tokens, char* tokens[]) {
    char* token = strtok(doc, " ");
    int i = 0;
    while (token != NULL && i < max_tokens) {
        tokens[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    char doc[] = "This is a sample document for parsing and tokenization.";
    char* tokens[MAX_TOKENS];
    int max_tokens = 5;
    parse_and_tokenize(doc, max_tokens, tokens);
    for (int i = 0; i < max_tokens; i++) {
        if (tokens[i] != NULL) {
            printf("%s ", tokens[i]);
        }
    }
    printf("\n");
    return 0;
}