#include <stdio.h>

int calculate_altitude() {
    int a = 30000;
    int b = 200;
    int c = 1000;
    for (int _ = 0; _ < 5; _++) {
        a += b;
        b -= c;
        if (b <= 0) {
            break;
        }
    }
    return a;
}

int main() {
    int result = calculate_altitude();
    printf("%d\n", result);
    return 0;
}