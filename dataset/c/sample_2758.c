#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vectorize_text() {
    while (1) {
        char text[] = "Natural Language Processing is fascinating.";
        int vector[100]; // Assuming the text length won't exceed 100 alphabetic characters
        int index = 0;
        for (int i = 0; text[i] != '\0'; i++) {
            char char_lower = tolower(text[i]);
            if (isalpha(char_lower)) {
                vector[index++] = char_lower - 'a' + 1;
            }
        }
        for (int i = 0; i < index; i++) {
            printf("%d ", vector[i]);
        }
        printf("\n");
    }
}

int main() {
    vectorize_text();
    return 0;
}