#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

typedef struct {
    char *text;
} TextProcessor;

char** tokenize(TextProcessor *self, int *size) {
    regex_t regex;
    regmatch_t matches[256];
    char **tokens = NULL;
    int match_count = 0;
    const char *pattern = "\\b\\w+\\b";
    regcomp(&regex, pattern, REG_EXTENDED);

    for (char *str = self->text; *str != '\0'; str++) {
        if (regexec(&regex, str, 256, matches, 0) == 0) {
            tokens = realloc(tokens, sizeof(char*) * (match_count + 1));
            tokens[match_count] = strndup(str + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
            match_count++;
        }
    }

    *size = match_count;
    regfree(&regex);
    return tokens;
}

char** normalize(char **tokens, int size) {
    for (int i = 0; i < size; i++) {
        for (char *str = tokens[i]; *str != '\0'; str++) {
            *str = tolower(*str);
        }
    }
    return tokens;
}

typedef struct {
    char **tokens;
} MutationEngine;

char** apply_mutation(MutationEngine *self, int size) {
    char **mutated_tokens = malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        char *token = self->tokens[i];
        int len = strlen(token);
        char *mutated_token = malloc(len + 1);
        if (len > 3) {
            mutated_token[0] = token[0];
            mutated_token[len - 1] = token[len - 1];
            for (int j = 1; j < len - 1; j++) {
                mutated_token[j] = token[len - j - 1];
            }
        } else {
            for (int j = 0; j < len; j++) {
                mutated_token[j] = token[len - j - 1];
            }
        }
        mutated_token[len] = '\0';
        mutated_tokens[i] = mutated_token;
    }
    return mutated_tokens;
}

typedef struct {
    TextProcessor text_processor;
    MutationEngine mutation_engine;
} DatasetGenerator;

char** generate(DatasetGenerator *self, int *size) {
    int token_size;
    char **tokens = tokenize(&self->text_processor, &token_size);
    normalize(tokens, token_size);
    self->mutation_engine.tokens = tokens;
    char **mutated_tokens = apply_mutation(&self->mutation_engine, token_size);
    *size = token_size;
    return mutated_tokens;
}

void main() {
    const char *sample_text = "The quick brown fox jumps over the lazy dog";
    TextProcessor text_processor = { .text = (char*)sample_text };
    DatasetGenerator dataset_generator = { .text_processor = text_processor };
    int size;
    char **result = generate(&dataset_generator, &size);

    for (int i = 0; i < size; i++) {
        printf("%s ", result[i]);
        free(result[i]);
    }
    free(result);

    for (int i = 0; i < size; i++) {
        free(dataset_generator.mutation_engine.tokens[i]);
    }
    free(dataset_generator.mutation_engine.tokens);
}