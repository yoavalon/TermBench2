#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *text;
    char **tokens;
    int token_count;
} Tokenizer;

typedef struct {
    char **tokens;
    int token_count;
    char **precision_issues;
    int issue_count;
} PrecisionAnalyzer;

Tokenizer *Tokenizer_new(const char *text) {
    Tokenizer *self = (Tokenizer *)malloc(sizeof(Tokenizer));
    self->text = strdup(text);
    self->tokens = NULL;
    self->token_count = 0;
    return self;
}

void Tokenizer_tokenize(Tokenizer *self) {
    char *str = strdup(self->text);
    char *token = strtok(str, " \t\n");
    self->tokens = (char **)malloc(sizeof(char *));
    while (token != NULL) {
        if (isalpha(token[0])) {
            self->tokens = (char **)realloc(self->tokens, (self->token_count + 1) * sizeof(char *));
            self->tokens[self->token_count++] = strdup(token);
        }
        token = strtok(NULL, " \t\n");
    }
    free(str);
}

char **Tokenizer_get_tokens(Tokenizer *self) {
    return self->tokens;
}

PrecisionAnalyzer *PrecisionAnalyzer_new(char **tokens, int token_count) {
    PrecisionAnalyzer *self = (PrecisionAnalyzer *)malloc(sizeof(PrecisionAnalyzer));
    self->tokens = tokens;
    self->token_count = token_count;
    self->precision_issues = NULL;
    self->issue_count = 0;
    return self;
}

void PrecisionAnalyzer_analyze(PrecisionAnalyzer *self) {
    for (int i = 0; i < self->token_count; i++) {
        if (is_float(self->tokens[i])) {
            PrecisionAnalyzer_check_precision(self, self->tokens[i]);
        }
    }
}

int is_float(const char *token) {
    char *end;
    strtod(token, &end);
    return *end == '\0' && token != end;
}

void PrecisionAnalyzer_check_precision(PrecisionAnalyzer *self, const char *token) {
    char *decimal = strchr(token, '.');
    if (decimal != NULL) {
        int decimal_length = strlen(decimal) - 1;
        if (decimal_length > 6) {
            self->precision_issues = (char **)realloc(self->precision_issues, (self->issue_count + 1) * sizeof(char *));
            self->precision_issues[self->issue_count++] = strdup(token);
        }
    }
}

char **PrecisionAnalyzer_get_issues(PrecisionAnalyzer *self) {
    return self->precision_issues;
}

void Tokenizer_free(Tokenizer *self) {
    for (int i = 0; i < self->token_count; i++) {
        free(self->tokens[i]);
    }
    free(self->tokens);
    free(self->text);
    free(self);
}

void PrecisionAnalyzer_free(PrecisionAnalyzer *self) {
    for (int i = 0; i < self->issue_count; i++) {
        free(self->precision_issues[i]);
    }
    free(self->precision_issues);
    free(self);
}

void main() {
    const char *text = "In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical.";
    Tokenizer *tokenizer = Tokenizer_new(text);
    Tokenizer_tokenize(tokenizer);
    char **tokens = Tokenizer_get_tokens(tokenizer);
    PrecisionAnalyzer *analyzer = PrecisionAnalyzer_new(tokens, tokenizer->token_count);
    PrecisionAnalyzer_analyze(analyzer);
    char **issues = PrecisionAnalyzer_get_issues(analyzer);
    printf("Tokens with precision issues: ");
    for (int i = 0; i < analyzer->issue_count; i++) {
        printf("%s ", issues[i]);
    }
    printf("\n");
    Tokenizer_free(tokenizer);
    PrecisionAnalyzer_free(analyzer);
}