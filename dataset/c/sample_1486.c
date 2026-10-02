#include <stdio.h>

typedef struct {
    int altitude;
    int target;
    int rate;
    char status[10];
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int start_altitude, int target_altitude, int rate_of_climb) {
    self->altitude = start_altitude;
    self->target = target_altitude;
    self->rate = rate_of_climb;
    snprintf(self->status, sizeof(self->status), "ascending");
}

int FlightTrajectory_update_altitude(FlightTrajectory *self) {
    if (strcmp(self->status, "ascending") == 0) {
        self->altitude += self->rate;
        if (self->altitude >= self->target) {
            snprintf(self->status, sizeof(self->status), "cruising");
            self->altitude = self->target;
        }
    }
    return self->altitude;
}

int FlightTrajectory_is_cruising(FlightTrajectory *self) {
    return strcmp(self->status, "cruising") == 0;
}

int plan_cruise_altitude(FlightTrajectory *trajectory, int max_iterations) {
    int iteration = 0;
    while (iteration < max_iterations && !FlightTrajectory_is_cruising(trajectory)) {
        FlightTrajectory_update_altitude(trajectory);
        iteration += 1;
    }
    return trajectory->altitude;
}

void main() {
    int start = 1000;
    int target = 35000;
    int rate = 500;
    int max_iter = 1000;
    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, start, target, rate);
    int final_altitude = plan_cruise_altitude(&trajectory, max_iter);
    printf("Final Cruise Altitude: %d\n", final_altitude);
}