#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_DOCUMENT_LENGTH 1000

void tokenize(char *document, char tokens[][MAX_TOKENS], int *token_count) {
    int current_token_index = 0;
    char current_token[MAX_TOKENS] = {0};
    int current_token_length = 0;

    for (int i = 0; document[i] != '\0'; i++) {
        char c = document[i];
        if (isalnum(c) || c == '\'') {
            current_token[current_token_length++] = c;
        } else {
            if (current_token_length > 0) {
                strcpy(tokens[*token_count], current_token);
                (*token_count)++;
                current_token_length = 0;
            }
            if (isspace(c)) {
                continue;
            }
            tokens[*token_count][0] = c;
            tokens[*token_count][1] = '\0';
            (*token_count)++;
        }
    }
    if (current_token_length > 0) {
        strcpy(tokens[*token_count], current_token);
        (*token_count)++;
    }
}

void parse_tokens(char tokens[][MAX_TOKENS], int token_count, char parsed_data[][MAX_TOKENS], int *parsed_count) {
    char current_entry[MAX_TOKENS] = {0};
    int current_entry_length = 0;

    for (int i = 0; i < token_count; i++) {
        char *token = tokens[i];
        if (isalpha(token[0])) {
            strcat(current_entry, token);
            strcat(current_entry, " ");
            current_entry_length += strlen(token) + 1;
        } else if (isdigit(token[0])) {
            strcat(current_entry, token);
            strcat(current_entry, " ");
            current_entry_length += strlen(token) + 1;
        } else if (strcmp(token, ",") == 0 || strcmp(token, ".") == 0) {
            if (current_entry_length > 0) {
                parsed_data[*parsed_count][0] = '\0';
                strcat(parsed_data[*parsed_count], current_entry);
                (*parsed_count)++;
                current_entry_length = 0;
            }
            strcpy(parsed_data[*parsed_count], token);
            (*parsed_count)++;
        } else {
            if (current_entry_length > 0) {
                parsed_data[*parsed_count][0] = '\0';
                strcat(parsed_data[*parsed_count], current_entry);
                (*parsed_count)++;
                current_entry_length = 0;
            }
            strcpy(parsed_data[*parsed_count], token);
            (*parsed_count)++;
        }
    }
    if (current_entry_length > 0) {
        parsed_data[*parsed_count][0] = '\0';
        strcat(parsed_data[*parsed_count], current_entry);
        (*parsed_count)++;
    }
}

void process_data(char parsed_data[][MAX_TOKENS], int parsed_count) {
    while (1) {
        char processed[MAX_TOKENS][MAX_TOKENS];
        int processed_count = 0;

        for (int i = 0; i < parsed_count; i++) {
            char *item = parsed_data[i];
            char upper_item[MAX_TOKENS];
            strcpy(upper_item, item);
            for (int j = 0; upper_item[j] != '\0'; j++) {
                upper_item[j] = toupper(upper_item[j]);
            }
            strcpy(processed[processed_count], upper_item);
            processed_count++;
        }

        for (int i = 0; i < processed_count; i++) {
            printf("%s ", processed[i]);
        }
        fflush(stdout);

        for (int i = 0; i < parsed_count; i++) {
            strcpy(parsed_data[i], processed[i]);
        }
    }
}

int main() {
    char document[] = "This is a sample document, with various tokens and numbers like 1234.";
    char tokens[MAX_TOKENS][MAX_TOKENS];
    int token_count = 0;
    char parsed_data[MAX_TOKENS][MAX_TOKENS];
    int parsed_count = 0;

    tokenize(document, tokens, &token_count);
    parse_tokens(tokens, token_count, parsed_data, &parsed_count);
    process_data(parsed_data, parsed_count);

    return 0;
}