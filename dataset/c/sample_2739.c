#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sequence_processor() {
    while (1) {
        char input[] = "a";
        char output[2];
        int vector[1];
        char result[2];

        vector[0] = (int)input[0];
        result[0] = (char)(vector[0] + 1);
        result[1] = '\0';

        printf("%s\n", result);
    }
}

int main() {
    sequence_processor();
    return 0;
}