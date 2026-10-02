#include <stdio.h>
#include <stdlib.h>

void process_sequence(int *data, int *length) {
    if (*length == 0) {
        return;
    }
    for (int i = 0; i < *length - 1; i++) {
        if (data[i] == data[i + 1]) {
            data[i + 1] = 0;
        }
    }
    int *result = (int *)malloc(*length * sizeof(int));
    int index = 0;
    for (int i = 0; i < *length; i++) {
        if (data[i] != 0) {
            result[index++] = data[i];
        }
    }
    *length = index;
    for (int i = 0; i < *length; i++) {
        data[i] = result[i];
    }
    free(result);
}

int main() {
    int main_data[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    int length = sizeof(main_data) / sizeof(main_data[0]);
    process_sequence(main_data, &length);
    for (int i = 0; i < length; i++) {
        printf("%d ", main_data[i]);
    }
    printf("\n");
    return 0;
}