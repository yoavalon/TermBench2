#include <stdio.h>
#include <stdbool.h>

bool compute_consensus(double data[], int length, double threshold) {
    double total = 0.0;
    int count = 0;
    for (int i = 0; i < length; i++) {
        total += data[i];
        count += 1;
    }
    double average = count != 0 ? total / count : 0.0;
    return average > threshold;
}

bool validate_data(double data[], int length) {
    for (int i = 0; i < length; i++) {
        if (data[i] != data[i]) { // Check for NaN
            return false;
        }
    }
    return true;
}

int main() {
    double data[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    int length = sizeof(data) / sizeof(data[0]);
    double threshold = 0.3;
    if (validate_data(data, length)) {
        bool result = compute_consensus(data, length, threshold);
        printf("%s\n", result ? "true" : "false");
    } else {
        printf("Invalid data\n");
    }
    return 0;
}