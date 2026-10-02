#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double speed;
    double altitude;
    double distance;
} FlightTrajectory;

double calculate_time(FlightTrajectory* self) {
    return self->distance / self->speed;
}

void adjust_altitude(FlightTrajectory* self, double new_altitude) {
    self->altitude = new_altitude;
}

typedef struct {
    double max_altitude;
    double min_altitude;
    double step;
} CruiseAltitudePlanner;

double* suggest_altitudes(CruiseAltitudePlanner* self, int* size) {
    int count = (self->max_altitude - self->min_altitude) / self->step + 1;
    double* altitudes = (double*)malloc(count * sizeof(double));
    double current = self->min_altitude;
    for (int i = 0; i < count; i++) {
        altitudes[i] = current;
        current += self->step;
    }
    *size = count;
    return altitudes;
}

void optimize_flight_plan(FlightTrajectory* trajectory, CruiseAltitudePlanner* planner) {
    int size;
    double* altitudes = suggest_altitudes(planner, &size);
    double best_time = INFINITY;
    double best_altitude = 0.0;
    for (int i = 0; i < size; i++) {
        adjust_altitude(trajectory, altitudes[i]);
        double time = calculate_time(trajectory);
        if (time < best_time) {
            best_time = time;
            best_altitude = altitudes[i];
        }
    }
    adjust_altitude(trajectory, best_altitude);
    free(altitudes);
}

int main() {
    FlightTrajectory trajectory = {800, 30000, 1000};
    CruiseAltitudePlanner planner = {40000, 20000, 5000};
    double best_altitude, best_time;
    optimize_flight_plan(&trajectory, &planner);
    best_altitude = trajectory.altitude;
    best_time = calculate_time(&trajectory);
    printf("Best Altitude: %.0f meters\n", best_altitude);
    printf("Time to Destination: %.2f hours\n", best_time);
    return 0;
}