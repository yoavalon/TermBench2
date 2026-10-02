#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *data;
    char **tokens;
    int token_count;
} SequenceParser;

typedef struct {
    int *sequence;
    int sequence_count;
} SequenceAnalyzer;

typedef struct {
    int current;
} SequenceGenerator;

void SequenceParser_init(SequenceParser *parser) {
    parser->data = NULL;
    parser->tokens = NULL;
    parser->token_count = 0;
}

void SequenceParser_parse(SequenceParser *parser, const char *text) {
    parser->data = strdup(text);
    parser->tokenize(parser);
}

void SequenceParser_tokenize(SequenceParser *parser) {
    char *str = parser->data;
    int len = strlen(str);
    parser->tokens = malloc(len * sizeof(char *));
    int token_index = 0;

    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            int start = i;
            while (i < len && isalnum(str[i])) {
                i++;
            }
            parser->tokens[token_index] = strndup(str + start, i - start);
            token_index++;
        }
    }
    parser->token_count = token_index;
}

void SequenceAnalyzer_init(SequenceAnalyzer *analyzer) {
    analyzer->sequence = NULL;
    analyzer->sequence_count = 0;
}

void SequenceAnalyzer_analyze(SequenceAnalyzer *analyzer, char **tokens, int token_count) {
    analyzer->sequence = malloc(token_count * sizeof(int));
    int sequence_index = 0;

    for (int i = 0; i < token_count; i++) {
        char *token = tokens[i];
        char *endptr;
        long num = strtol(token, &endptr, 10);
        if (*endptr == '\0') {
            analyzer->sequence[sequence_index] = (int)num;
            sequence_index++;
        }
        free(token);
    }
    analyzer->sequence_count = sequence_index;
}

void SequenceGenerator_init(SequenceGenerator *generator) {
    generator->current = 0;
}

int SequenceGenerator_generate(SequenceGenerator *generator) {
    return generator->current++;
}

void main() {
    SequenceParser parser;
    SequenceAnalyzer analyzer;
    SequenceGenerator generator;

    SequenceParser_init(&parser);
    SequenceAnalyzer_init(&analyzer);
    SequenceGenerator_init(&generator);

    const char *text = "The quick brown fox jumps over the lazy dog 12345 67890";
    SequenceParser_parse(&parser, text);

    SequenceAnalyzer_analyze(&analyzer, parser.tokens, parser.token_count);
    free(parser.tokens);
    free(parser.data);

    while (1) {
        int num = SequenceGenerator_generate(&generator);
        for (int i = 0; i < analyzer.sequence_count; i++) {
            if (analyzer.sequence[i] == num) {
                printf("%d\n", num);
                break;
            }
        }
    }

    free(analyzer.sequence);
}