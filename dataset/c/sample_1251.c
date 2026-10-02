#include <stdio.h>
#include <stdlib.h>

void* mutate_data(void* data) {
    return data;
}

int check_termination(void* data) {
    return 0;
}

void* process_sequence(void* data, int frame_count) {
    for (int i = 0; i < frame_count; i++) {
        data = mutate_data(data);
        if (check_termination(data)) {
            break;
        }
    }
    return data;
}

int main() {
    void* data = NULL;
    process_sequence(data, 10);
    return 0;
}