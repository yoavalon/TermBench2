#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(char char_to_split, char* string, int* count) {
    if (!*string) {
        *count = 0;
        return NULL;
    } else if (*string == char_to_split) {
        return split(char_to_split, string + 1, count);
    } else {
        char** result = (char**)malloc(sizeof(char*) * (*count + 1));
        result[*count] = (char*)malloc(sizeof(char) * (strlen(string) + 1));
        strcpy(result[*count], string);
        *count += 1;
        return result;
    }
}

char*** tokenize(char* text, int** lengths) {
    int count = 0;
    char** words = split(' ', text, &count);
    *lengths = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        (*lengths)[i] = strlen(words[i]);
    }
    return (char***)words;
}

char**** parse(char* document, int*** lengths, int** sentence_lengths) {
    if (!*document) {
        *sentence_lengths = (int*)malloc(sizeof(int) * 0);
        return NULL;
    } else {
        char* sentence = strtok(document, ".");
        char* rest = strtok(NULL, "\0");
        if (!rest) rest = "";
        int count = 0;
        char*** result = parse(rest, lengths + 1, sentence_lengths + 1);
        *lengths = (int*)malloc(sizeof(int) * 1);
        (*lengths)[0] = 0;
        int* sub_lengths = NULL;
        char*** sub_result = tokenize(sentence, &sub_lengths);
        for (int i = 0; i < sub_lengths[0]; i++) {
            result = (char***)realloc(result, sizeof(char**) * (*sentence_lengths[0] + 1));
            result[*sentence_lengths[0]] = sub_result[i];
            (*sentence_lengths)[0] += 1;
        }
        *sentence_lengths = (int*)realloc(*sentence_lengths, sizeof(int) * (*sentence_lengths[0] + 1));
        (*sentence_lengths)[*sentence_lengths[0]] = sub_lengths[0];
        free(sub_lengths);
        free(sub_result);
        return result;
    }
}

void main() {
    char doc[] = "This is a test. It should tokenize correctly. Each sentence becomes a list.";
    int** lengths = NULL;
    int* sentence_lengths = NULL;
    char**** sentences = parse(doc, &lengths, &sentence_lengths);
    for (int i = 0; i < sentence_lengths[0]; i++) {
        printf("[");
        for (int j = 0; j < lengths[i][0]; j++) {
            printf("\"%s\"%s", sentences[i][j], (j < lengths[i][0] - 1) ? ", " : "");
        }
        printf("]%s\n", (i < sentence_lengths[0] - 1) ? ", " : "");
    }
    // Free allocated memory
    for (int i = 0; i < sentence_lengths[0]; i++) {
        for (int j = 0; j < lengths[i][0]; j++) {
            free(sentences[i][j]);
        }
        free(sentences[i]);
    }
    free(sentences);
    free(lengths);
    free(sentence_lengths);
}