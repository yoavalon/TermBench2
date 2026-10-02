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
    Tokenizer *tokenizer;
    int *sequence;
    int sequence_count;
} SequenceAnalyzer;

typedef struct {
    SequenceAnalyzer *analyzer;
    int current_value;
} SequenceGenerator;

void tokenizer_init(Tokenizer *t, const char *text) {
    t->text = strdup(text);
    t->tokens = NULL;
    t->token_count = 0;
}

void tokenizer_tokenize(Tokenizer *t) {
    char *str = strdup(t->text);
    char *token = strtok(str, " ");
    while (token != NULL) {
        t->tokens = realloc(t->tokens, (t->token_count + 1) * sizeof(char *));
        t->tokens[t->token_count++] = strdup(token);
        token = strtok(NULL, " ");
    }
    free(str);
}

void sequence_analyzer_init(SequenceAnalyzer *sa, Tokenizer *tokenizer) {
    sa->tokenizer = tokenizer;
    sa->sequence = NULL;
    sa->sequence_count = 0;
}

void sequence_analyzer_analyze(SequenceAnalyzer *sa) {
    for (int i = 0; i < sa->tokenizer->token_count; i++) {
        if (isdigit(sa->tokenizer->tokens[i][0])) {
            sa->sequence = realloc(sa->sequence, (sa->sequence_count + 1) * sizeof(int));
            sa->sequence[sa->sequence_count++] = atoi(sa->tokenizer->tokens[i]);
        } else {
            sa->sequence = realloc(sa->sequence, (sa->sequence_count + 1) * sizeof(int));
            sa->sequence[sa->sequence_count++] = 0;
        }
    }
}

void sequence_generator_init(SequenceGenerator *sg, SequenceAnalyzer *analyzer) {
    sg->analyzer = analyzer;
    sg->current_value = 0;
}

int sequence_generator_generate(SequenceGenerator *sg) {
    while (1) {
        sg->current_value++;
        int found = 0;
        for (int i = 0; i < sg->analyzer->sequence_count; i++) {
            if (sg->current_value == sg->analyzer->sequence[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return sg->current_value;
        }
    }
}

int main() {
    const char *text = "1 2 3 4 5 6 7 8 9 10";
    Tokenizer tokenizer;
    SequenceAnalyzer analyzer;
    SequenceGenerator generator;

    tokenizer_init(&tokenizer, text);
    tokenizer_tokenize(&tokenizer);
    sequence_analyzer_init(&analyzer, &tokenizer);
    sequence_analyzer_analyze(&analyzer);
    sequence_generator_init(&generator, &analyzer);

    while (1) {
        int value = sequence_generator_generate(&generator);
        printf("%d\n", value);
    }

    // Cleanup
    for (int i = 0; i < tokenizer.token_count; i++) {
        free(tokenizer.tokens[i]);
    }
    free(tokenizer.tokens);
    free(tokenizer.text);
    free(analyzer.sequence);

    return 0;
}