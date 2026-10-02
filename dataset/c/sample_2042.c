#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct {
    char *text;
    char **tokens;
} TextProcessor;

typedef struct {
    char **tokens;
    char **numeric_tokens;
} NumericParser;

typedef struct {
    char **numeric_tokens;
} PrecisionAnalyzer;

void TextProcessor_init(TextProcessor *self, const char *text) {
    self->text = strdup(text);
    self->tokens = NULL;
}

char** TextProcessor_tokenize(TextProcessor *self) {
    regex_t regex;
    regmatch_t matches[2];
    int count = 0;
    char *str = self->text;
    char *token;

    if (regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED) != 0) {
        return NULL;
    }

    self->tokens = (char**)malloc(sizeof(char*) * 100);
    while (regexec(&regex, str, 2, matches, 0) == 0) {
        token = (char*)malloc(matches[1].rm_eo - matches[1].rm_so + 1);
        strncpy(token, str + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
        token[matches[1].rm_eo - matches[1].rm_so] = '\0';
        self->tokens[count++] = token;
        str += matches[0].rm_eo;
    }
    regfree(&regex);
    self->tokens[count] = NULL;
    return self->tokens;
}

char** TextProcessor_filter_tokens(TextProcessor *self) {
    char **filtered = (char**)malloc(sizeof(char*) * 100);
    int count = 0;
    for (int i = 0; self->tokens[i] != NULL; i++) {
        if (strlen(self->tokens[i]) > 3) {
            filtered[count++] = self->tokens[i];
        }
    }
    filtered[count] = NULL;
    return filtered;
}

void NumericParser_init(NumericParser *self, char **tokens) {
    self->tokens = tokens;
    self->numeric_tokens = NULL;
}

char** NumericParser_extract_numeric(NumericParser *self) {
    regex_t regex;
    regmatch_t matches[2];
    int count = 0;

    if (regcomp(&regex, "^\\d+(\\.\\d+)?$", REG_EXTENDED) != 0) {
        return NULL;
    }

    self->numeric_tokens = (char**)malloc(sizeof(char*) * 100);
    for (int i = 0; self->tokens[i] != NULL; i++) {
        if (regexec(&regex, self->tokens[i], 2, matches, 0) == 0) {
            self->numeric_tokens[count++] = self->tokens[i];
        }
    }
    regfree(&regex);
    self->numeric_tokens[count] = NULL;
    return self->numeric_tokens;
}

void PrecisionAnalyzer_init(PrecisionAnalyzer *self, char **numeric_tokens) {
    self->numeric_tokens = numeric_tokens;
}

void PrecisionAnalyzer_analyze_precision(PrecisionAnalyzer *self) {
    for (int i = 0; self->numeric_tokens[i] != NULL; i++) {
        char *token = self->numeric_tokens[i];
        if (strchr(token, '.') != NULL) {
            int precision = strlen(strchr(token, '.') + 1);
            printf("%s: %d\n", token, precision);
        }
    }
}

void main() {
    const char *text = "The quick brown fox jumps over the lazy dog 123.456 789.10 100.001";
    TextProcessor processor;
    NumericParser parser;
    PrecisionAnalyzer analyzer;

    TextProcessor_init(&processor, text);
    processor.tokenize(&processor);
    char **filtered_tokens = processor.filter_tokens(&processor);

    NumericParser_init(&parser, filtered_tokens);
    parser.extract_numeric(&parser);

    PrecisionAnalyzer_init(&analyzer, parser.numeric_tokens);
    analyzer.analyze_precision(&analyzer);
}

int main() {
    main();
    return 0;
}