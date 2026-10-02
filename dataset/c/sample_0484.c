#include <stdio.h>
#include <stdbool.h>

bool validate_data(int* data, int size) {
    for (int i = 0; i < size; i++) {
        if (data[i] < 0) {
            return false;
        }
    }
    return true;
}

void process_data(int* data, int* size) {
    int result = 0;
    while (true) {
        if (validate_data(data, *size)) {
            result = 0;
            for (int i = 0; i < *size; i++) {
                result += data[i];
            }
            data[0] = result;
            *size = 1;
        } else {
            data[0] = 0;
            *size = 1;
        }
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    process_data(data, &size);
    return 0;
}