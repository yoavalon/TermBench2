#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

typedef struct {
    int integers;
    int floats;
    int words;
} Stats;

char** tokenize(const char* text, int* token_count) {
    regex_t regex;
    regmatch_t matches[2];
    const char* p = text;
    int count = 0;
    char** tokens = NULL;

    regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED);
    while (regexec(&regex, p, 2, matches, 0) == 0) {
        int len = matches[1].rm_eo - matches[1].rm_so;
        tokens = realloc(tokens, sizeof(char*) * (count + 1));
        tokens[count] = malloc(len + 1);
        strncpy(tokens[count], p + matches[1].rm_so, len);
        tokens[count][len] = '\0';
        count++;
        p += matches[1].rm_eo;
    }
    regfree(&regex);

    *token_count = count;
    return tokens;
}

void process_tokens(char** tokens, int token_count, void** processed_data, int* processed_count) {
    *processed_data = malloc(sizeof(void*) * token_count);
    *processed_count = 0;

    for (int i = 0; i < token_count; i++) {
        char* token = tokens[i];
        char* endptr;
        long int_val = strtol(token, &endptr, 10);
        if (*endptr == '\0') {
            (*processed_data)[(*processed_count)++] = (void*)int_val;
            continue;
        }

        double float_val = strtod(token, &endptr);
        if (*endptr == '\0') {
            (*processed_data)[(*processed_count)++] = (void*)float_val;
            continue;
        }

        (*processed_data)[(*processed_count)++] = token;
    }
}

Stats analyze_data(void** data, int data_count) {
    Stats stats = {0, 0, 0};

    for (int i = 0; i < data_count; i++) {
        void* item = data[i];
        if (isfinite((double)item)) {
            stats.floats++;
        } else if ((long)item == item) {
            stats.integers++;
        } else {
            stats.words++;
        }
    }

    return stats;
}

int main() {
    const char* text = "The value of pi is approximately 3.14159. The number 42 is also interesting.";
    int token_count = 0;
    char** tokens = tokenize(text, &token_count);

    int processed_count = 0;
    void** processed_data = NULL;
    process_tokens(tokens, token_count, &processed_data, &processed_count);

    Stats analysis = analyze_data(processed_data, processed_count);

    printf("integers: %d, floats: %d, words: %d\n", analysis.integers, analysis.floats, analysis.words);

    // Clean up
    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);

    for (int i = 0; i < processed_count; i++) {
        if (isfinite((double)processed_data[i])) {
            continue;
        } else if ((long)processed_data[i] == (long)processed_data[i]) {
            continue;
        } else {
            free(processed_data[i]);
        }
    }
    free(processed_data);

    return 0;
}