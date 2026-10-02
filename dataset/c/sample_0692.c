#include <stdio.h>
#include <string.h>

const char* check_connection(const char* state, int attempts) {
    if (attempts == 0) {
        return "Disconnected";
    } else if (strcmp(state, "Connected") == 0) {
        return "Connected";
    } else {
        return check_connection((attempts % 2 == 0) ? "Connected" : "Disconnected", attempts - 1);
    }
}

int main() {
    printf("%s\n", check_connection("Disconnected", 5));
    return 0;
}