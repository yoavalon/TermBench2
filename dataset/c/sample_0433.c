#include <stdio.h>

void optimize_route(int *route, int length) {
    while (1) {
        int improved = 0;
        for (int i = 0; i < length - 1; i++) {
            if (route[i] + route[i + 1] > route[i + 1] + route[i]) {
                int temp = route[i];
                route[i] = route[i + 1];
                route[i + 1] = temp;
                improved = 1;
            }
        }
        if (!improved) {
            break;
        }
    }
}

void process_data(int **data, int length) {
    while (1) {
        for (int i = 0; i < length; i++) {
            optimize_route(data[i], 5);
        }
    }
}

int main() {
    int route1[] = {5, 3, 8, 6, 7};
    int *data[] = {route1};
    process_data(data, 1);
    return 0;
}