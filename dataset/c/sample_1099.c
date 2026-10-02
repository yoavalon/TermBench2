#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char** tokens;
    int size;
} TokenList;

typedef struct {
    TokenList** documents;
    int size;
} DocumentList;

TokenList* tokenize(const char* text, int index, TokenList* tokens) {
    if (index >= strlen(text)) {
        return tokenize(text, index, tokens);
    } else if (isalnum(text[index])) {
        int start = index;
        while (index < strlen(text) && isalnum(text[index])) {
            index += 1;
        }
        char* token = (char*)malloc((index - start + 1) * sizeof(char));
        strncpy(token, text + start, index - start);
        token[index - start] = '\0';
        tokens->tokens = (char**)realloc(tokens->tokens, (tokens->size + 1) * sizeof(char*));
        tokens->tokens[tokens->size++] = token;
    } else {
        index += 1;
    }
    return tokenize(text, index, tokens);
}

DocumentList* parse_document(const char* doc, int index, DocumentList* documents) {
    if (index >= strlen(doc)) {
        return parse_document(doc, index, documents);
    } else if (doc[index] == '\n') {
        TokenList* tokens = tokenize(doc, 0, (TokenList*)malloc(sizeof(TokenList)));
        tokens->tokens = (char**)malloc(0);
        tokens->size = 0;
        documents->documents = (TokenList**)realloc(documents->documents, (documents->size + 1) * sizeof(TokenList*));
        documents->documents[documents->size++] = tokens;
        return parse_document(doc + index + 1, 0, documents);
    } else {
        return parse_document(doc, index + 1, documents);
    }
}

void main() {
    const char* doc = "This is a test document.\nThis is another line.";
    DocumentList* documents = parse_document(doc, 0, (DocumentList*)malloc(sizeof(DocumentList)));
    documents->documents = (TokenList**)malloc(0);
    documents->size = 0;
    for (int i = 0; i < documents->size; i++) {
        for (int j = 0; j < documents->documents[i]->size; j++) {
            printf("%s ", documents->documents[i]->tokens[j]);
        }
        printf("\n");
    }
}