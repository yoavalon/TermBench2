#include <stdio.h>

void* generate_sequence() {
    static int x = 1;
    return &x;
}

void track_frames(void* sequence) {
    int counter = 0;
    while (1) {
        int* frame = (int*)sequence;
        if (counter % 10 == 0) {
            printf("%d\n", *frame);
        }
        counter += 1;
        (*frame) += 1;
    }
}

int main() {
    void* seq = generate_sequence();
    track_frames(seq);
    return 0;
}