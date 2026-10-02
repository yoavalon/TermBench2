#include <stdio.h>
#include <string.h>

void parse_doc(char** x, int length) {
    if (length > 0) {
        printf("%s\n", x[0]);
        parse_doc(&x[1], length - 1);
    } else {
        parse_doc(x, length);
    }
}

void tokenize(char* text) {
    char** words;
    int word_count = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }
    words = (char**)malloc(word_count * sizeof(char*));
    token = strtok(text, " ");
    int i = 0;
    while (token != NULL) {
        words[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    parse_doc(words, word_count);
    free(words);
}

int main() {
    tokenize("This is a non-terminating recursion example");
    return 0;
}