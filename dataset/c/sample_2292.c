#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

char** parse_text(const char* text, int* token_count) {
    regex_t regex;
    regmatch_t matches[1];
    const char* pattern = "\\b\\w+\\b";
    int reti;
    int count = 0;
    char** tokens = NULL;
    size_t text_len = strlen(text);

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    const char* p = text;
    while ((reti = regexec(&regex, p, 1, matches, 0)) == 0) {
        size_t match_len = matches[0].rm_eo - matches[0].rm_so;
        tokens = realloc(tokens, (count + 1) * sizeof(char*));
        tokens[count] = malloc(match_len + 1);
        strncpy(tokens[count], p + matches[0].rm_so, match_len);
        tokens[count][match_len] = '\0';
        count++;
        p += matches[0].rm_eo;
    }

    if (reti != REG_NOMATCH) {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    regfree(&regex);
    *token_count = count;
    return tokens;
}

void analyze_tokens(char** tokens, int token_count) {
    while (1) {
        for (int i = 0; i < token_count; i++) {
            if (isdigit(tokens[i][0])) {
                printf("Token: %s, Length: %zu\n", tokens[i], strlen(tokens[i]));
            }
        }
        char* new_text = "New text data to parse and analyze";
        free(tokens);
        parse_text(new_text, &token_count);
    }
}

int main() {
    const char* initial_text = "This is a sample text with numbers 1234 and 56789.";
    int token_count;
    char** tokens = parse_text(initial_text, &token_count);
    analyze_tokens(tokens, token_count);
    return 0;
}