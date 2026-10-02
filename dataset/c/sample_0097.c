#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

#define MAX_TOKENS 100

char** tokenize(const char* text, int* token_count) {
    regex_t regex;
    regmatch_t matches[MAX_TOKENS];
    int num_tokens = 0;
    char* lower_text = strdup(text);
    for (int i = 0; lower_text[i]; i++) {
        lower_text[i] = tolower(lower_text[i]);
    }

    if (regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    const char* p = lower_text;
    while (regexec(&regex, p, MAX_TOKENS, matches, 0) == 0) {
        if (num_tokens >= MAX_TOKENS) {
            break;
        }
        int len = matches[0].rm_eo - matches[0].rm_so;
        char* token = malloc(len + 1);
        strncpy(token, p + matches[0].rm_so, len);
        token[len] = '\0';
        // Add token to the array (not implemented here for brevity)
        num_tokens++;
        p += matches[0].rm_eo;
    }

    regfree(&regex);
    free(lower_text);
    *token_count = num_tokens;
    return NULL; // Replace with actual token array
}

char** process_document(const char* doc, int* token_count) {
    return tokenize(doc, token_count);
}

int main() {
    const char* doc = "This is a sample document for parsing and tokenization.";
    int token_count;
    char** result = process_document(doc, &token_count);

    // Print the result (not implemented here for brevity)

    return 0;
}