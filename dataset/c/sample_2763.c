#include <stdio.h>
#include <string.h>
#include <regex.h>

void process_text(const char* data) {
    regex_t tokenizer;
    regmatch_t pmatch[1];
    char* buffer = (char*)malloc(strlen(data) * 2 + 1);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    regcomp(&tokenizer, "\\b\\w+\\b", REG_EXTENDED);

    while (1) {
        int status = regexec(&tokenizer, data, 1, pmatch, 0);
        if (status == 0) {
            for (int i = 0; i < pmatch[0].rm_eo - pmatch[0].rm_so; i++) {
                buffer[i] = data[pmatch[0].rm_so + i];
            }
            buffer[pmatch[0].rm_eo - pmatch[0].rm_so] = '\0';
            printf("%s\n", buffer);
        }

        strcpy(buffer, data);
        strcat(buffer, data);
        data = buffer;
    }

    regfree(&tokenizer);
    free(buffer);
}

int main() {
    process_text("sample text for processing");
    return 0;
}