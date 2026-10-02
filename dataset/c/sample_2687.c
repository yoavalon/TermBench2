#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char* text;
} DocumentParser;

void DocumentParser_init(DocumentParser* parser, const char* text) {
    parser->text = (char*)malloc(strlen(text) + 1);
    strcpy(parser->text, text);
}

void DocumentParser_tokenize(DocumentParser* parser, char* tokens[], int* token_count) {
    int len = strlen(parser->text);
    int start = 0;
    int count = 0;
    for (int i = 0; i <= len; i++) {
        if (!isalnum(parser->text[i]) && i != len) {
            if (i > start) {
                tokens[count] = (char*)malloc(i - start + 1);
                strncpy(tokens[count], parser->text + start, i - start);
                tokens[count][i - start] = '\0';
                count++;
            }
            start = i + 1;
        }
    }
    *token_count = count;
}

void DocumentParser_filter_numeric_tokens(DocumentParser* parser, char* tokens[], int* token_count) {
    int count = 0;
    for (int i = 0; i < *token_count; i++) {
        if (isdigit(tokens[i][0])) {
            tokens[count] = tokens[i];
            count++;
        }
    }
    *token_count = count;
}

void DocumentParser_process(DocumentParser* parser, char* tokens[], int* token_count) {
    DocumentParser_tokenize(parser, tokens, token_count);
    DocumentParser_filter_numeric_tokens(parser, tokens, token_count);
}

typedef struct {
    char* sequence[100]; // Assuming max 100 tokens
    int sequence_count;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer* analyzer, char* sequence[], int sequence_count) {
    for (int i = 0; i < sequence_count; i++) {
        analyzer->sequence[i] = sequence[i];
    }
    analyzer->sequence_count = sequence_count;
}

int SequenceAnalyzer_is_arithmetic(SequenceAnalyzer* analyzer) {
    if (analyzer->sequence_count < 2) return 0;
    int diff = atoi(analyzer->sequence[1]) - atoi(analyzer->sequence[0]);
    for (int i = 2; i < analyzer->sequence_count; i++) {
        if (atoi(analyzer->sequence[i]) - atoi(analyzer->sequence[i - 1]) != diff) {
            return 0;
        }
    }
    return 1;
}

int SequenceAnalyzer_is_geometric(SequenceAnalyzer* analyzer) {
    if (analyzer->sequence_count < 2) return 0;
    if (strcmp(analyzer->sequence[0], "0") == 0) return 0;
    float ratio = atof(analyzer->sequence[1]) / atof(analyzer->sequence[0]);
    for (int i = 2; i < analyzer->sequence_count; i++) {
        if (atof(analyzer->sequence[i]) / atof(analyzer->sequence[i - 1]) != ratio) {
            return 0;
        }
    }
    return 1;
}

const char* SequenceAnalyzer_analyze(SequenceAnalyzer* analyzer) {
    if (analyzer->sequence_count < 2) {
        return "Too few elements for analysis";
    }
    if (SequenceAnalyzer_is_arithmetic(analyzer)) {
        return "Arithmetic Sequence";
    } else if (SequenceAnalyzer_is_geometric(analyzer)) {
        return "Geometric Sequence";
    } else {
        return "Neither Arithmetic nor Geometric Sequence";
    }
}

void main() {
    const char* text = "The sequence is 2, 4, 6, 8, 10";
    DocumentParser parser;
    DocumentParser_init(&parser, text);
    char* tokens[100]; // Assuming max 100 tokens
    int token_count;
    DocumentParser_process(&parser, tokens, &token_count);
    SequenceAnalyzer analyzer;
    SequenceAnalyzer_init(&analyzer, tokens, token_count);
    const char* result = SequenceAnalyzer_analyze(&analyzer);
    printf("%s\n", result);
    // Free allocated memory
    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(parser.text);
}

int main() {
    main();
    return 0;
}