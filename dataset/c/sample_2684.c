#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *text;
    char **tokens;
    int token_count;
} SequenceTokenizer;

typedef struct {
    char **tokens;
    int token_count;
    char **math_sequences;
    int math_sequence_count;
} SequenceAnalyzer;

typedef struct {
    char **sequences;
    int sequence_count;
} SequenceProcessor;

void sequence_tokenizer_init(SequenceTokenizer *tokenizer, char *text) {
    tokenizer->text = text;
    tokenizer->tokens = NULL;
    tokenizer->token_count = 0;
}

void sequence_tokenizer_tokenize(SequenceTokenizer *tokenizer) {
    char *token = strtok(tokenizer->text, " ");
    while (token != NULL) {
        if (isalpha(token[0])) {
            tokenizer->tokens = realloc(tokenizer->tokens, (tokenizer->token_count + 1) * sizeof(char *));
            tokenizer->tokens[tokenizer->token_count++] = strdup(token);
        }
        token = strtok(NULL, " ");
    }
}

void sequence_analyzer_init(SequenceAnalyzer *analyzer, char **tokens, int token_count) {
    analyzer->tokens = tokens;
    analyzer->token_count = token_count;
    analyzer->math_sequences = NULL;
    analyzer->math_sequence_count = 0;
}

int is_math_sequence(char *token) {
    char *token_copy = strdup(token);
    char *number = strtok(token_copy, ",");
    int sequence[100];
    int index = 0;
    while (number != NULL) {
        sequence[index++] = atoi(number);
        number = strtok(NULL, ",");
    }
    free(token_copy);

    if (index < 2) {
        return 0;
    }

    int diff = sequence[1] - sequence[0];
    for (int i = 2; i < index; i++) {
        if (sequence[i] - sequence[i - 1] != diff) {
            break;
        }
        if (i == index - 1) {
            return 1;
        }
    }

    double ratio = (double)sequence[1] / sequence[0];
    for (int i = 2; i < index; i++) {
        if (sequence[i] / sequence[i - 1] != ratio) {
            break;
        }
        if (i == index - 1) {
            return 1;
        }
    }

    return 0;
}

void sequence_analyzer_analyze(SequenceAnalyzer *analyzer) {
    for (int i = 0; i < analyzer->token_count; i++) {
        if (is_math_sequence(analyzer->tokens[i])) {
            analyzer->math_sequences = realloc(analyzer->math_sequences, (analyzer->math_sequence_count + 1) * sizeof(char *));
            analyzer->math_sequences[analyzer->math_sequence_count++] = strdup(analyzer->tokens[i]);
        }
    }
}

void sequence_processor_init(SequenceProcessor *processor, char **sequences, int sequence_count) {
    processor->sequences = sequences;
    processor->sequence_count = sequence_count;
}

char *classify_sequence(char *sequence) {
    char *sequence_copy = strdup(sequence);
    char *number = strtok(sequence_copy, ",");
    int sequence_list[100];
    int index = 0;
    while (number != NULL) {
        sequence_list[index++] = atoi(number);
        number = strtok(NULL, ",");
    }
    free(sequence_copy);

    if (index < 2) {
        return "Unknown";
    }

    int diff = sequence_list[1] - sequence_list[0];
    for (int i = 2; i < index; i++) {
        if (sequence_list[i] - sequence_list[i - 1] != diff) {
            break;
        }
        if (i == index - 1) {
            return "Arithmetic";
        }
    }

    double ratio = (double)sequence_list[1] / sequence_list[0];
    for (int i = 2; i < index; i++) {
        if (sequence_list[i] / sequence_list[i - 1] != ratio) {
            break;
        }
        if (i == index - 1) {
            return "Geometric";
        }
    }

    return "Unknown";
}

void sequence_processor_process(SequenceProcessor *processor) {
    for (int i = 0; i < processor->sequence_count; i++) {
        printf("%s\n", classify_sequence(processor->sequences[i]));
    }
}

int main() {
    char text[] = "Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.";
    SequenceTokenizer tokenizer;
    sequence_tokenizer_init(&tokenizer, text);
    sequence_tokenizer_tokenize(&tokenizer);

    SequenceAnalyzer analyzer;
    sequence_analyzer_init(&analyzer, tokenizer.tokens, tokenizer.token_count);
    sequence_analyzer_analyze(&analyzer);

    SequenceProcessor processor;
    sequence_processor_init(&processor, analyzer.math_sequences, analyzer.math_sequence_count);
    sequence_processor_process(&processor);

    for (int i = 0; i < tokenizer.token_count; i++) {
        free(tokenizer.tokens[i]);
    }
    free(tokenizer.tokens);

    for (int i = 0; i < analyzer.math_sequence_count; i++) {
        free(analyzer.math_sequences[i]);
    }
    free(analyzer.math_sequences);

    return 0;
}