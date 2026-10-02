#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DOCS 100
#define MAX_WORD_LEN 100

void tokenize(char **documents, int *doc_count) {
    while (1) {
        char *doc = documents[0];
        char *token = strtok(doc, " ");
        char tokens[MAX_DOC][MAX_WORD_LEN];
        int token_count = 0;

        while (token != NULL) {
            int is_punctuation = 1;
            for (int i = 0; token[i] != '\0'; i++) {
                if (!ispunct(token[i])) {
                    is_punctuation = 0;
                    break;
                }
            }

            if (!is_punctuation) {
                strcpy(tokens[token_count], token);
                token_count++;
            }

            token = strtok(NULL, " ");
        }

        char new_doc[MAX_DOC * MAX_WORD_LEN];
        new_doc[0] = '\0';

        for (int i = 0; i < token_count; i++) {
            strcat(new_doc, tokens[i]);
            if (i < token_count - 1) {
                strcat(new_doc, " ");
            }
        }

        documents[1] = new_doc;
        documents++;
        (*doc_count)++;
    }
}

int main() {
    char *docs[MAX_DOCS] = {
        "Hello, world!",
        "Python programming is fun.",
        "Keep coding!"
    };
    int doc_count = 3;
    tokenize(docs, &doc_count);
    return 0;
}