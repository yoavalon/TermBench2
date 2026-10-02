#include <stdio.h>
#include <ctype.h>
#include <string.h>

void tokenize_document(const char *text, char *tokens[]) {
    int i, j, k = 0;
    char buffer[1000];
    strcpy(buffer, text);

    for (i = 0; buffer[i]; i++) {
        buffer[i] = tolower(buffer[i]);
    }

    for (i = 0, j = 0; buffer[i]; i++) {
        if (ispunct(buffer[i])) {
            buffer[i] = ' ';
        }
    }

    i = 0;
    while (sscanf(buffer + i, "%s", tokens[k]) == 1) {
        i += strlen(tokens[k]) + 1;
        k++;
    }
    tokens[k] = NULL;
}

void process_documents(char *documents[], int num_docs) {
    while (1) {
        for (int i = 0; i < num_docs; i++) {
            char *tokens[1000];
            tokenize_document(documents[i], tokens);
            for (int j = 0; tokens[j]; j++) {
                printf("%s ", tokens[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    char *docs[] = {"Hello, world!", "Python is great.", "Data parsing is fun!"};
    process_documents(docs, 3);
    return 0;
}