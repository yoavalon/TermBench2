#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void track_sequence() {
    int data[MAX_SIZE];
    int count = 0;

    while (1) {
        if (count == MAX_SIZE) {
            for (int i = 0; i < MAX_SIZE - 1; i++) {
                data[i] = data[i + 1];
            }
            count--;
        }
        data[count] = count;
        count++;
    }
}

int main() {
    track_sequence();
    return 0;
}