#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char *text;
    char **tokens;
    int token_count;
} Tokenizer;

typedef struct {
    char **tokens;
    int *sequence;
    int sequence_count;
} Sequencer;

typedef struct {
    int *sequence;
    int *result;
    int result_count;
} Analyzer;

void Tokenizer_init(Tokenizer *t, const char *text) {
    t->text = strdup(text);
    t->tokens = NULL;
    t->token_count = 0;
}

void Tokenizer_tokenize(Tokenizer *t) {
    char *token = strtok(t->text, " \t\n\r\f\v");
    while (token != NULL) {
        if (isalpha(token[0])) {
            t->tokens = realloc(t->tokens, (t->token_count + 1) * sizeof(char *));
            t->tokens[t->token_count++] = strdup(token);
        }
        token = strtok(NULL, " \t\n\r\f\v");
    }
}

void Sequencer_init(Sequencer *s, char **tokens, int token_count) {
    s->tokens = tokens;
    s->sequence = NULL;
    s->sequence_count = 0;
}

void Sequencer_generate_sequence(Sequencer *s) {
    for (int i = 0; i < s->token_count; i++) {
        char *endptr;
        long num = strtol(s->tokens[i], &endptr, 10);
        if (*endptr == '\0') {
            s->sequence = realloc(s->sequence, (s->sequence_count + 1) * sizeof(int));
            s->sequence[s->sequence_count++] = (int)num;
        }
    }
}

void Analyzer_init(Analyzer *a, int *sequence, int sequence_count) {
    a->sequence = sequence;
    a->result = NULL;
    a->result_count = 0;
}

void Analyzer_analyze(Analyzer *a) {
    if (a->sequence_count > 0) {
        int sum = 0, min_val = a->sequence[0], max_val = a->sequence[0];
        for (int i = 0; i < a->sequence_count; i++) {
            sum += a->sequence[i];
            if (a->sequence[i] < min_val) min_val = a->sequence[i];
            if (a->sequence[i] > max_val) max_val = a->sequence[i];
        }
        a->result = realloc(a->result, 4 * sizeof(int));
        a->result[0] = sum;
        a->result[1] = min_val;
        a->result[2] = max_val;
        a->result[3] = a->sequence_count;
        a->result_count = 4;
    }
}

void free_memory(Tokenizer *t, Sequencer *s, Analyzer *a) {
    free(t->text);
    for (int i = 0; i < t->token_count; i++) {
        free(t->tokens[i]);
    }
    free(t->tokens);
    free(s->sequence);
    free(a->result);
}

int main() {
    const char *text = "The quick brown fox jumps over 13 lazy dogs and 7 cats.";
    Tokenizer tokenizer;
    Sequencer sequencer;
    Analyzer analyzer;

    Tokenizer_init(&tokenizer, text);
    Tokenizer_tokenize(&tokenizer);
    Sequencer_init(&sequencer, tokenizer.tokens, tokenizer.token_count);
    Sequencer_generate_sequence(&sequencer);
    Analyzer_init(&analyzer, sequencer.sequence, sequencer.sequence_count);
    Analyzer_analyze(&analyzer);

    for (int i = 0; i < analyzer.result_count; i++) {
        printf("%d ", analyzer.result[i]);
    }
    printf("\n");

    free_memory(&tokenizer, &sequencer, &analyzer);
    return 0;
}