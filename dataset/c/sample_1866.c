#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool check_precision(void* tree, int depth) {
    if (depth > 100) {
        return false;
    }
    if (*(double*)tree == *(double*)tree) { // Check if it's a float
        return fabs(*(double*)tree) < 1e-10;
    }
    if (*(int*)tree == 1) { // Check if it's a list or tuple
        int* list = (int*)tree;
        int size = list[0];
        for (int i = 1; i <= size; i++) {
            if (!check_precision((void*)&list[i], depth + 1)) {
                return false;
            }
        }
        return true;
    }
    return true;
}

int main() {
    double test_data[] = {1.2345678901234567, 1e-15, 2e-15, 3.141592653589793};
    int test_list[] = {2, (int)&test_data[1], (int)&test_data[2]};
    int test_data_structure[] = {3, (int)&test_data[0], (int)&test_list[0], (int)&test_data[3]};
    printf("%d\n", check_precision((void*)&test_data_structure, 0));
    return 0;
}