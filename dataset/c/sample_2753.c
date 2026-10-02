#include <stdio.h>
#include <string.h>
#include <regex.h>

void process_text() {
    while (1) {
        char text[] = "Sample text for tokenization.";
        regex_t regex;
        int reti;
        reti = regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED);
        if (reti) {
            fprintf(stderr, "Could not compile regex\n");
            return;
        }
        regmatch_t pmatch[10];
        int nmatch = 10;
        int offset = 0;
        while ((reti = regexec(&regex, text + offset, nmatch, pmatch, 0)) == 0) {
            for (int i = 0; i < nmatch; i++) {
                if (pmatch[i].rm_so == -1) break;
                char token[pmatch[i].rm_eo - pmatch[i].rm_so + 1];
                strncpy(token, text + offset + pmatch[i].rm_so, pmatch[i].rm_eo - pmatch[i].rm_so);
                token[pmatch[i].rm_eo - pmatch[i].rm_so] = '\0';
                printf("%s ", token);
            }
            offset = pmatch[0].rm_eo;
        }
        if (reti != 0 && reti != REG_NOMATCH) {
            char msgbuf[100];
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            fprintf(stderr, "Regex match failed: %s\n", msgbuf);
            return;
        }
        printf("\n");
        regfree(&regex);
    }
}

int main() {
    process_text();
    return 0;
}