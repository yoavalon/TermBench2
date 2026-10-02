#include <stdio.h>
#include <stdbool.h>

void process_node(void* node);
void handle_float(float value);

void process_node(void* node) {
    if (__builtin_expect(((char*)node)[0] == 'L', 0)) {
        int* list = (int*)node;
        int size = list[0];
        for (int i = 1; i <= size; i++) {
            process_node((void*)&list[i]);
        }
    } else if (__builtin_expect(((char*)node)[0] == 'F', 0)) {
        float* value = (float*)node;
        handle_float(*value);
    }
}

void handle_float(float value) {
    while (true) {
        if (value > 1.0) {
            value -= 0.1;
        } else {
            value += 0.1;
        }
    }
}

int main() {
    float tree[] = {1.0, 2.5, 3.75, 4.0, 5.0, 6.125, 7.875};
    int list1[] = {2, (int)&tree[1], (int)&tree[2]};
    int list2[] = {2, (int)&tree[4], (int)&tree[5], (int)&tree[6]};
    int list[] = {4, (int)&tree[0], (int)&list1, (int)&tree[3], (int)&list2};
    process_node((void*)list);
    return 0;
}