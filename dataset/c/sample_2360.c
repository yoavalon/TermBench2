#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct {
    char* text;
    char** tokens;
    int token_count;
} TextProcessor;

typedef struct {
    char** tokens;
    int token_count;
    char** floats;
    int float_count;
} TokenAnalyzer;

typedef struct {
    char** floats;
    int float_count;
    int* precision;
} FloatPrecisionEvaluator;

void TextProcessor_init(TextProcessor* processor, const char* text) {
    processor->text = strdup(text);
    processor->tokens = NULL;
    processor->token_count = 0;
}

void TextProcessor_tokenize(TextProcessor* processor) {
    regex_t regex;
    regmatch_t matches[2];
    if (regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED) != 0) {
        fprintf(stderr, "Failed to compile regex\n");
        exit(1);
    }
    int start = 0;
    int match_count = 0;
    while (regexec(&regex, processor->text + start, 2, matches, 0) == 0) {
        int len = matches[0].rm_eo - matches[0].rm_so;
        processor->tokens = realloc(processor->tokens, (match_count + 1) * sizeof(char*));
        processor->tokens[match_count] = strndup(processor->text + start + matches[0].rm_so, len);
        match_count++;
        start += matches[0].rm_eo;
    }
    regfree(&regex);
    processor->token_count = match_count;
}

char** TextProcessor_get_tokens(TextProcessor* processor, int* count) {
    *count = processor->token_count;
    return processor->tokens;
}

void TokenAnalyzer_init(TokenAnalyzer* analyzer, char** tokens, int token_count) {
    analyzer->tokens = tokens;
    analyzer->token_count = token_count;
    analyzer->floats = NULL;
    analyzer->float_count = 0;
}

void TokenAnalyzer_extract_floats(TokenAnalyzer* analyzer) {
    regex_t regex;
    if (regcomp(&regex, "^\\d+\\.\\d+$", REG_EXTENDED) != 0) {
        fprintf(stderr, "Failed to compile regex\n");
        exit(1);
    }
    int float_count = 0;
    for (int i = 0; i < analyzer->token_count; i++) {
        if (regexec(&regex, analyzer->tokens[i], 0, NULL, 0) == 0) {
            analyzer->floats = realloc(analyzer->floats, (float_count + 1) * sizeof(char*));
            analyzer->floats[float_count] = strdup(analyzer->tokens[i]);
            float_count++;
        }
    }
    regfree(&regex);
    analyzer->float_count = float_count;
}

char** TokenAnalyzer_get_floats(TokenAnalyzer* analyzer, int* count) {
    *count = analyzer->float_count;
    return analyzer->floats;
}

void FloatPrecisionEvaluator_init(FloatPrecisionEvaluator* evaluator, char** floats, int float_count) {
    evaluator->floats = floats;
    evaluator->float_count = float_count;
    evaluator->precision = malloc(float_count * sizeof(int));
}

void FloatPrecisionEvaluator_evaluate_precision(FloatPrecisionEvaluator* evaluator) {
    for (int i = 0; i < evaluator->float_count; i++) {
        char* dot = strchr(evaluator->floats[i], '.');
        evaluator->precision[i] = strlen(dot + 1);
    }
}

int* FloatPrecisionEvaluator_get_precision(FloatPrecisionEvaluator* evaluator, int* count) {
    *count = evaluator->float_count;
    return evaluator->precision;
}

int main() {
    const char* text = "In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803.";
    TextProcessor processor;
    TextProcessor_init(&processor, text);
    TextProcessor_tokenize(&processor);

    int token_count;
    char** tokens = TextProcessor_get_tokens(&processor, &token_count);

    TokenAnalyzer analyzer;
    TokenAnalyzer_init(&analyzer, tokens, token_count);
    TokenAnalyzer_extract_floats(&analyzer);

    int float_count;
    char** floats = TokenAnalyzer_get_floats(&analyzer, &float_count);

    FloatPrecisionEvaluator evaluator;
    FloatPrecisionEvaluator_init(&evaluator, floats, float_count);
    FloatPrecisionEvaluator_evaluate_precision(&evaluator);

    int* precision;
    int precision_count;
    precision = FloatPrecisionEvaluator_get_precision(&evaluator, &precision_count);

    while (1) {
        for (int i = 0; i < precision_count; i++) {
            printf("Float: %s - Precision: %d\n", floats[i], precision[i]);
        }
    }

    return 0;
}