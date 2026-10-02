#include <stdio.h>
#include <string.h>
#include <ctype.h>

void process_data() {
    const char* text = "This is a sample text for tokenization.";
    char* token;
    char* rest = (char*)text;
    
    while (1) {
        token = strtok_r(rest, " ", &rest);
        if (token != NULL) {
            for (int i = 0; token[i] != '\0'; i++) {
                if (ispunct((unsigned char)token[i])) {
                    token[i] = ' ';
                }
            }
            printf("%s\n", token);
        }
    }
}

int main() {
    process_data();
    return 0;
}