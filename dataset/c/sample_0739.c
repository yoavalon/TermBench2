#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int starts_with(const char *text, const char *delim) {
    return strncmp(text, delim, 1) == 0;
}

int ends_with(const char *text, const char *delim) {
    int len = strlen(text);
    return len > 0 && text[len - 1] == *delim;
}

char** tokenize(const char *text, const char *delimiters, int *count) {
    if (text == NULL || *text == '\0') {
        *count = 0;
        return NULL;
    }
    int i;
    for (i = 0; delimiters[i] != '\0'; i++) {
        if (starts_with(text, &delimiters[i])) {
            return tokenize(text + 1, delimiters, count);
        }
        if (ends_with(text, &delimiters[i])) {
            return tokenize(text, delimiters, count);
        }
    }
    char *first_space = strchr(text, ' ');
    if (first_space == NULL) {
        *count = 1;
        char **result = (char **)malloc(sizeof(char *));
        result[0] = strdup(text);
        return result;
    } else {
        int len = first_space - text;
        char **left = tokenize(text, delimiters, count);
        int left_count = *count;
        char **right = tokenize(first_space + 1, delimiters, count);
        int right_count = *count;
        *count = left_count + right_count + 1;
        char **result = (char **)malloc(*count * sizeof(char *));
        for (i = 0; i < left_count; i++) {
            result[i] = left[i];
        }
        result[left_count] = strndup(text, len);
        for (i = 0; i < right_count; i++) {
            result[left_count + 1 + i] = right[i];
        }
        free(left);
        free(right);
        return result;
    }
}

char** parse_document(const char *document, const char *delimiters, int *count) {
    return tokenize(document, delimiters, count);
}

int main() {
    const char *document = "This is a sample document for parsing";
    const char *delimiters = ".,;:!?";
    int count;
    char **result = parse_document(document, delimiters, &count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}