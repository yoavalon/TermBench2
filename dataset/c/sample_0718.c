#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    struct TokenNode *next;
} TokenNode;

typedef struct {
    TokenNode *head;
} TokenList;

TokenList *create_token_list() {
    TokenList *list = (TokenList *)malloc(sizeof(TokenList));
    list->head = NULL;
    return list;
}

void append_token(TokenList *list, const char *word) {
    TokenNode *new_node = (TokenNode *)malloc(sizeof(TokenNode));
    new_node->word = strdup(word);
    new_node->next = list->head;
    list->head = new_node;
}

void free_token_list(TokenList *list) {
    TokenNode *current = list->head;
    while (current != NULL) {
        TokenNode *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
    free(list);
}

TokenList *tokenize(const char *text, int depth) {
    if (depth == 0) {
        return create_token_list();
    }
    TokenList *list = create_token_list();
    char *str = strdup(text);
    char *token = strtok(str, " ");
    while (token != NULL) {
        append_token(list, token);
        TokenList *sublist = tokenize(token, depth - 1);
        TokenNode *subnode = sublist->head;
        while (subnode != NULL) {
            append_token(list, subnode->word);
            subnode = subnode->next;
        }
        free_token_list(sublist);
        token = strtok(NULL, " ");
    }
    free(str);
    return list;
}

void vectorize(TokenList *list, int depth, int *vector, int *index) {
    if (depth == 0) {
        return;
    }
    vector[*index] = 0;
    TokenNode *current = list->head;
    while (current != NULL) {
        (*index)++;
        vector[*index] = strlen(current->word);
        vectorize(create_token_list(), depth - 1, vector, index);
        current = current->next;
    }
}

int main() {
    const char *text = "Recursive vectorization";
    int depth = 2;
    TokenList *tokens = tokenize(text, depth);
    int *vector = (int *)malloc(100 * sizeof(int)); // Assuming a maximum depth of 100
    int index = -1;
    vectorize(tokens, depth, vector, &index);
    for (int i = 0; i <= index; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    free_token_list(tokens);
    free(vector);
    return 0;
}