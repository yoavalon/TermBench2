#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_PAIRS 1000

typedef struct {
    char *text;
    char *tokens[MAX_TOKENS];
    int token_count;
} TextProcessor;

typedef struct {
    char *tokens[MAX_TOKENS];
    int token_count;
    int sequences[MAX_PAIRS][2];
    int sequence_counts[MAX_PAIRS];
    int sequence_count;
} SequenceAnalyzer;

typedef struct {
    int sequences[MAX_PAIRS][2];
    int sequence_counts[MAX_PAIRS];
    int sequence_count;
} ReportGenerator;

void text_processor_init(TextProcessor *processor, const char *text) {
    processor->text = strdup(text);
    processor->token_count = 0;
}

void text_processor_tokenize(TextProcessor *processor) {
    char *text = processor->text;
    char *token = strtok(text, " ,.!?;:");
    while (token) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        processor->tokens[processor->token_count++] = strdup(token);
        token = strtok(NULL, " ,.!?;:");
    }
}

void sequence_analyzer_init(SequenceAnalyzer *analyzer, TextProcessor *processor) {
    for (int i = 0; i < processor->token_count; i++) {
        analyzer->tokens[i] = processor->tokens[i];
    }
    analyzer->token_count = processor->token_count;
    analyzer->sequence_count = 0;
}

void sequence_analyzer_identify_sequences(SequenceAnalyzer *analyzer) {
    for (int i = 0; i < analyzer->token_count - 1; i++) {
        int found = 0;
        for (int j = 0; j < analyzer->sequence_count; j++) {
            if (strcmp(analyzer->sequences[j][0], analyzer->tokens[i]) == 0 &&
                strcmp(analyzer->sequences[j][1], analyzer->tokens[i + 1]) == 0) {
                analyzer->sequence_counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            analyzer->sequences[analyzer->sequence_count][0] = analyzer->tokens[i];
            analyzer->sequences[analyzer->sequence_count][1] = analyzer->tokens[i + 1];
            analyzer->sequence_counts[analyzer->sequence_count] = 1;
            analyzer->sequence_count++;
        }
    }
}

void report_generator_init(ReportGenerator *generator, SequenceAnalyzer *analyzer) {
    for (int i = 0; i < analyzer->sequence_count; i++) {
        generator->sequences[i][0] = analyzer->sequences[i][0];
        generator->sequences[i][1] = analyzer->sequences[i][1];
        generator->sequence_counts[i] = analyzer->sequence_counts[i];
    }
    generator->sequence_count = analyzer->sequence_count;
}

void report_generator_generate_report(ReportGenerator *generator) {
    for (int i = 0; i < generator->sequence_count - 1; i++) {
        for (int j = i + 1; j < generator->sequence_count; j++) {
            if (generator->sequence_counts[i] < generator->sequence_counts[j]) {
                int temp = generator->sequence_counts[i];
                generator->sequence_counts[i] = generator->sequence_counts[j];
                generator->sequence_counts[j] = temp;
                char *temp1 = generator->sequences[i][0];
                generator->sequences[i][0] = generator->sequences[j][0];
                generator->sequences[j][0] = temp1;
                char *temp2 = generator->sequences[i][1];
                generator->sequences[i][1] = generator->sequences[j][1];
                generator->sequences[j][1] = temp2;
            }
        }
    }
}

void main() {
    TextProcessor processor;
    SequenceAnalyzer analyzer;
    ReportGenerator generator;
    const char *text = "This is a test text for parsing and tokenization. We will test the text processing and sequence analysis.";

    text_processor_init(&processor, text);
    text_processor_tokenize(&processor);

    sequence_analyzer_init(&analyzer, &processor);
    sequence_analyzer_identify_sequences(&analyzer);

    report_generator_init(&generator, &analyzer);
    report_generator_generate_report(&generator);

    for (int i = 0; i < 10 && i < generator.sequence_count; i++) {
        printf("Sequence: %s %s, Count: %d\n", generator.sequences[i][0], generator.sequences[i][1], generator.sequence_counts[i]);
    }
}