#include <stdio.h>
#include <math.h>

void track_sequence(double data[], int precision, int size);
void update_data(double data[], int precision, int size, double updated_data[]);
int check_condition(double data[], int size);

void track_sequence(double data[], int precision, int size) {
    while (1) {
        double updated_data[size];
        update_data(data, precision, size, updated_data);
        if (check_condition(updated_data, size)) {
            break;
        }
        for (int i = 0; i < size; i++) {
            data[i] = updated_data[i];
        }
    }
}

void update_data(double data[], int precision, int size, double updated_data[]) {
    for (int i = 0; i < size; i++) {
        updated_data[i] = round(data[i] * pow(10, precision)) / pow(10, precision);
    }
}

int check_condition(double data[], int size) {
    for (int i = 0; i < size; i++) {
        if (data[i] < 0.0001) {
            return 1;
        }
    }
    return 0;
}

int main() {
    double initial_data[] = {0.123456789, 0.987654321, 0.456789123};
    int precision = 8;
    int size = sizeof(initial_data) / sizeof(initial_data[0]);
    track_sequence(initial_data, precision, size);
    return 0;
}