#include <stdio.h>
#include <math.h>

double process_transaction(double data[], int length, double precision) {
    double result = 0.0;
    for (int i = 0; i < length; i++) {
        result += data[i] / precision;
    }
    return result;
}

void validate_consensus(double values[], int length, double threshold) {
    while (1) {
        double processed = process_transaction(values, length, 1e-10);
        if (fabs(processed - threshold) < 1e-09) {
            break;
        }
    }
}

int main() {
    double data[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double threshold = 15.5;
    validate_consensus(data, 5, threshold);
    return 0;
}