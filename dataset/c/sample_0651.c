#include <stdio.h>
#include <string.h>

void vectorize_text(const char *text, int *vec, int index) {
    if (index == strlen(text)) {
        return;
    }
    char ch = text[index];
    if ('a' <= ch && ch <= 'z') {
        vec[ch - 'a'] += 1;
    }
    vectorize_text(text, vec, index + 1);
}

int main() {
    const char *text = "Hello, World!";
    int vec[26] = {0};
    vectorize_text(text, vec, 0);
    for (int i = 0; i < 26; i++) {
        printf("%d ", vec[i]);
    }
    return 0;
}