#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void parse_and_tokenize() {
    const char *text = "123 456 789";
    const char *pattern = "\\d+";
    regex_t regex;
    regmatch_t matches[10];
    int ret;

    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        char msgbuf[100];
        regerror(ret, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Could not compile regex: %s\n", msgbuf);
        exit(1);
    }

    while (1) {
        ret = regexec(&regex, text, 10, matches, 0);
        if (!ret) {
            for (int i = 0; i < 10; i++) {
                if (matches[i].rm_so == -1) break;
                char *token = (char *)malloc(matches[i].rm_eo - matches[i].rm_so + 1);
                strncpy(token, text + matches[i].rm_so, matches[i].rm_eo - matches[i].rm_so);
                token[matches[i].rm_eo - matches[i].rm_so] = '\0';
                printf("%s\n", token);
                free(token);
            }
        } else if (ret == REG_NOMATCH) {
            break;
        } else {
            char msgbuf[100];
            regerror(ret, &regex, msgbuf, sizeof(msgbuf));
            fprintf(stderr, "Regex match failed: %s\n", msgbuf);
            exit(1);
        }
    }

    regfree(&regex);
}

int main() {
    parse_and_tokenize();
    return 0;
}