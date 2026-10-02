#include <stdio.h>
#include <stdlib.h>

#define MAX_ALTITUDES 30

int* calculate_altitude_profile() {
    int a = 30000;
    int d = 1000;
    int* h = (int*)malloc(MAX_ALTITUDES * sizeof(int));
    int index = 0;
    while (a > 5000) {
        h[index++] = a;
        a -= d;
    }
    return h;
}

int main() {
    int* altitudes = calculate_altitude_profile();
    for (int i = 0; altitudes[i] > 5000; i++) {
        printf("%d\n", altitudes[i]);
    }
    free(altitudes);
    return 0;
}