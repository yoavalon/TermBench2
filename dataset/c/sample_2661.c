#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *sequence;
} SequenceParser;

typedef struct {
    int parsed_sequence;
} SequenceEvaluator;

void SequenceParser_init(SequenceParser *parser, const char *sequence) {
    parser->sequence = strdup(sequence);
}

char** tokenize(SequenceParser *parser, int *token_count) {
    char **tokens = NULL;
    *token_count = 0;
    for (int i = 0; parser->sequence[i] != '\0'; i++) {
        char c = parser->sequence[i];
        if (isdigit(c)) {
            tokens = realloc(tokens, (*token_count + 1) * sizeof(char*));
            tokens[*token_count] = strdup("NUMBER");
            (*token_count)++;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
            tokens = realloc(tokens, (*token_count + 1) * sizeof(char*));
            tokens[*token_count] = malloc(2 * sizeof(char));
            tokens[*token_count][0] = c;
            tokens[*token_count][1] = '\0';
            (*token_count)++;
        } else {
            fprintf(stderr, "Invalid character: %c\n", c);
            exit(EXIT_FAILURE);
        }
    }
    return tokens;
}

int parse_expression(char **tokens, int *index) {
    if (strcmp(tokens[*index], "(") == 0) {
        (*index)++;
        int result = parse_expression(tokens, index);
        if (strcmp(tokens[*index], ")") != 0) {
            fprintf(stderr, "Missing closing parenthesis\n");
            exit(EXIT_FAILURE);
        }
        (*index)++;
        return result;
    } else if (strcmp(tokens[*index], "NUMBER") == 0) {
        int result = atoi(tokens[*index]);
        (*index)++;
        return result;
    } else {
        fprintf(stderr, "Unexpected token: %s\n", tokens[*index]);
        exit(EXIT_FAILURE);
    }
}

int parse_term(char **tokens, int *index) {
    int result = parse_expression(tokens, index);
    while (*index < *token_count && (tokens[*index][0] == '*' || tokens[*index][0] == '/')) {
        char operator = tokens[*index][0];
        (*index)++;
        int next_value = parse_expression(tokens, index);
        if (operator == '*') {
            result *= next_value;
        } else if (operator == '/') {
            result /= next_value;
        }
    }
    return result;
}

int parse_sequence(char **tokens, int *index) {
    int result = parse_term(tokens, index);
    while (*index < *token_count && (tokens[*index][0] == '+' || tokens[*index][0] == '-')) {
        char operator = tokens[*index][0];
        (*index)++;
        int next_value = parse_term(tokens, index);
        if (operator == '+') {
            result += next_value;
        } else if (operator == '-') {
            result -= next_value;
        }
    }
    return result;
}

int parse(SequenceParser *parser, char **tokens, int token_count) {
    int index = 0;
    int result = parse_sequence(tokens, &index);
    if (index != token_count) {
        fprintf(stderr, "Extra tokens at the end\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void SequenceEvaluator_init(SequenceEvaluator *evaluator, int parsed_sequence) {
    evaluator->parsed_sequence = parsed_sequence;
}

int evaluate_expression(int expr) {
    return expr;
}

int evaluate(SequenceEvaluator *evaluator) {
    return evaluate_expression(evaluator->parsed_sequence);
}

void main() {
    const char *sequence = "3+5*2-8/4";
    SequenceParser parser;
    SequenceParser_init(&parser, sequence);
    int token_count;
    char **tokens = tokenize(&parser, &token_count);
    int parsed_sequence = parse(&parser, tokens, token_count);
    SequenceEvaluator evaluator;
    SequenceEvaluator_init(&evaluator, parsed_sequence);
    int result = evaluate(&evaluator);
    printf("%d\n", result);
    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(parser.sequence);
}