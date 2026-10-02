#include <stdio.h>

void process_signal(int data[], int index) {
    if (index >= 5) {
        process_signal(data, 0);
    } else {
        data[index] = data[index] * 2;
        process_signal(data, index + 1);
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    process_signal(data, 0);
    return 0;
}