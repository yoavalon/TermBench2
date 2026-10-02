#include <stdio.h>

void compute_flight_path(int data[][2], int len, double result[]) {
    for (int i = 0; i < len; i++) {
        double altitude = data[i][0];
        double speed = data[i][1];
        double trajectory = altitude / speed;
        result[i] = trajectory;
    }
}

double analyze_altitude(int data[][2], int len) {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += data[i][0];
    }
    return sum / len;
}

int main() {
    int flight_data[][2] = {{10000, 500}, {12000, 550}, {11000, 520}, {9000, 480}, {8000, 450}};
    int len = sizeof(flight_data) / sizeof(flight_data[0]);
    double trajectory[len];
    compute_flight_path(flight_data, len, trajectory);
    double avg_altitude = analyze_altitude(flight_data, len);
    while (1) {
        printf("Current Trajectory: ");
        for (int i = 0; i < len; i++) {
            printf("%f ", trajectory[i]);
        }
        printf("\nAverage Altitude: %f\n", avg_altitude);
    }
    return 0;
}