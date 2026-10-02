#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_DOCUMENTS 3
#define MAX_SENTENCES 10

typedef struct {
    char tokens[MAX_TOKEN_LENGTH][MAX_TOKEN_LENGTH];
    int token_count;
} Sequence;

void tokenize(char *text, Sequence *seq) {
    seq->token_count = 0;
    char word[MAX_TOKEN_LENGTH] = "";
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalnum(c)) {
            strncat(word, &c, 1);
        } else if (word[0] != '\0') {
            for (int j = 0; word[j] != '\0'; j++) {
                word[j] = tolower(word[j]);
            }
            strcpy(seq->tokens[seq->token_count], word);
            seq->token_count++;
            word[0] = '\0';
        }
    }
    if (word[0] != '\0') {
        for (int j = 0; word[j] != '\0'; j++) {
            word[j] = tolower(word[j]);
        }
        strcpy(seq->tokens[seq->token_count], word);
        seq->token_count++;
    }
}

void parse_document(char *text, char sentences[MAX_SENTENCES][MAX_TOKEN_LENGTH], int *sentence_count) {
    *sentence_count = 0;
    char sentence[MAX_TOKEN_LENGTH] = "";
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        strncat(sentence, &c, 1);
        if (c == '.' || c == '!' || c == '?') {
            strcpy(sentences[*sentence_count], sentence);
            (*sentence_count)++;
            sentence[0] = '\0';
        }
    }
    if (sentence[0] != '\0') {
        strcpy(sentences[*sentence_count], sentence);
        (*sentence_count)++;
    }
}

void analyze_sequences(char *documents[MAX_DOCUMENTS], Sequence sequences[MAX_DOCUMENTS * MAX_SENTENCES], int *sequence_count) {
    *sequence_count = 0;
    for (int i = 0; i < MAX_DOCUMENTS; i++) {
        if (documents[i] == NULL) break;
        char sentences[MAX_SENTENCES][MAX_TOKEN_LENGTH];
        int sentence_count;
        parse_document(documents[i], sentences, &sentence_count);
        for (int j = 0; j < sentence_count; j++) {
            tokenize(sentences[j], &sequences[*sequence_count]);
            (*sequence_count)++;
        }
    }
}

int main() {
    char *docs[MAX_DOCUMENTS] = {
        "The quick brown fox jumps over the lazy dog.",
        "This is a simple test document for parsing.",
        "Another sentence to test the lexical tokenizer."
    };
    Sequence sequences[MAX_DOCUMENTS * MAX_SENTENCES];
    int sequence_count;
    analyze_sequences(docs, sequences, &sequence_count);
    for (int i = 0; i < sequence_count; i++) {
        for (int j = 0; j < sequences[i].token_count; j++) {
            printf("%s ", sequences[i].tokens[j]);
        }
        printf("\n");
    }
    return 0;
}