#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct {
    char* text;
    char** tokens;
    int token_count;
} DocumentTokenizer;

void DocumentTokenizer_init(DocumentTokenizer* self, char* text) {
    self->text = text;
    self->tokens = NULL;
    self->token_count = 0;
}

void DocumentTokenizer_tokenize(DocumentTokenizer* self) {
    regex_t regex;
    regmatch_t pmatch[1];
    int reti;
    char* ptr = self->text;
    int len = strlen(self->text);

    reti = regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    self->tokens = (char**)malloc(len * sizeof(char*));
    self->token_count = 0;

    while ((reti = regexec(&regex, ptr, 1, pmatch, 0)) == 0) {
        int start = pmatch[0].rm_so;
        int end = pmatch[0].rm_eo;
        int token_len = end - start;
        self->tokens[self->token_count] = (char*)malloc((token_len + 1) * sizeof(char));
        strncpy(self->tokens[self->token_count], ptr + start, token_len);
        self->tokens[self->token_count][token_len] = '\0';
        self->token_count++;
        ptr += end;
    }

    if (reti != REG_NOMATCH) {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    regfree(&regex);
}

char** DocumentTokenizer_get_tokens(DocumentTokenizer* self, int* count) {
    *count = self->token_count;
    return self->tokens;
}

typedef struct {
    char** tokens;
    int token_count;
    int max_length;
    char** long_tokens;
    int long_token_count;
} BoundaryConditionChecker;

void BoundaryConditionChecker_init(BoundaryConditionChecker* self, char** tokens, int token_count, int max_length) {
    self->tokens = tokens;
    self->token_count = token_count;
    self->max_length = max_length;
    self->long_tokens = NULL;
    self->long_token_count = 0;
}

void BoundaryConditionChecker_check_conditions(BoundaryConditionChecker* self) {
    for (int i = 0; i < self->token_count; i++) {
        if (strlen(self->tokens[i]) > self->max_length) {
            self->long_token_count++;
            self->long_tokens = (char**)realloc(self->long_tokens, self->long_token_count * sizeof(char*));
            self->long_tokens[self->long_token_count - 1] = self->tokens[i];
        }
    }
}

char** BoundaryConditionChecker_get_long_tokens(BoundaryConditionChecker* self, int* count) {
    *count = self->long_token_count;
    return self->long_tokens;
}

typedef struct {
    char** long_tokens;
    int long_token_count;
    char* report;
} ReportGenerator;

void ReportGenerator_init(ReportGenerator* self, char** long_tokens, int long_token_count) {
    self->long_tokens = long_tokens;
    self->long_token_count = long_token_count;
    self->report = NULL;
}

void ReportGenerator_generate_report(ReportGenerator* self) {
    if (self->long_token_count > 0) {
        self->report = (char*)malloc(1024 * sizeof(char));
        snprintf(self->report, 1024, "Tokens exceeding %d characters: ", strlen(self->long_tokens[0]));
        for (int i = 0; i < self->long_token_count; i++) {
            strcat(self->report, self->long_tokens[i]);
            if (i < self->long_token_count - 1) {
                strcat(self->report, ", ");
            }
        }
    } else {
        self->report = "No tokens exceed the boundary condition.";
    }
}

char* ReportGenerator_get_report(ReportGenerator* self) {
    return self->report;
}

void main() {
    char text[] = "This is a simple text to demonstrate the boundary conditions of tokenization in Python.";
    DocumentTokenizer tokenizer;
    DocumentTokenizer_init(&tokenizer, text);
    DocumentTokenizer_tokenize(&tokenizer);
    int token_count;
    char** tokens = DocumentTokenizer_get_tokens(&tokenizer, &token_count);
    BoundaryConditionChecker boundary_checker;
    BoundaryConditionChecker_init(&boundary_checker, tokens, token_count, 10);
    BoundaryConditionChecker_check_conditions(&boundary_checker);
    int long_token_count;
    char** long_tokens = BoundaryConditionChecker_get_long_tokens(&boundary_checker, &long_token_count);
    ReportGenerator report_generator;
    ReportGenerator_init(&report_generator, long_tokens, long_token_count);
    ReportGenerator_generate_report(&report_generator);
    printf("%s\n", ReportGenerator_get_report(&report_generator));
}

int main() {
    main();
    return 0;
}