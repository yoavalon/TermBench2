#include <stdio.h>
#include <string.h>

char* process_state(int state, char* data) {
    static char result[100];
    if (state == 0) {
        sprintf(result, "%sa", data);
        return process_state(1, result);
    } else if (state == 1) {
        sprintf(result, "%sb", data);
        return process_state(2, result);
    } else if (state == 2) {
        sprintf(result, "%sc", data);
        return process_state(3, result);
    } else if (state == 3) {
        return data;
    }
    return NULL;
}

int main() {
    char data[100] = "";
    char* result = process_state(0, data);
    printf("%s\n", result);
    return 0;
}