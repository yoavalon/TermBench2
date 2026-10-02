#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(const char* sentence, int index, char** tokens, int* token_count) {
    if (index >= strlen(sentence) || sentence[index] == ' ') {
        return tokens;
    }
    if (index == 0 || sentence[index - 1] == ' ') {
        int start = index;
        while (index < strlen(sentence) && sentence[index] != ' ') {
            index += 1;
        }
        tokens[*token_count] = (char*)malloc((index - start + 1) * sizeof(char));
        strncpy(tokens[*token_count], &sentence[start], index - start);
        tokens[*token_count][index - start] = '\0';
        (*token_count)++;
    }
    return tokenize(sentence, index, tokens, token_count);
}

int main() {
    const char* sentence = "example sentence for tokenization";
    int token_count = 0;
    int max_tokens = 10; // Assuming a maximum of 10 tokens for simplicity
    char** result = (char**)malloc(max_tokens * sizeof(char*));
    tokenize(sentence, 0, result, &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%s ", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}