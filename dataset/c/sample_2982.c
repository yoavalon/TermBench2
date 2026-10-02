#include <stdio.h>

typedef struct {
    int altitude;
    int rate_of_climb;
    int cruise_altitude;
    int descent_rate;
    const char* status;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory* self, int initial_altitude, int rate_of_climb, int cruise_altitude, int descent_rate) {
    self->altitude = initial_altitude;
    self->rate_of_climb = rate_of_climb;
    self->cruise_altitude = cruise_altitude;
    self->descent_rate = descent_rate;
    self->status = "climbing";
}

void FlightTrajectory_update_altitude(FlightTrajectory* self) {
    if (strcmp(self->status, "climbing") == 0) {
        if (self->altitude + self->rate_of_climb < self->cruise_altitude) {
            self->altitude += self->rate_of_climb;
        } else {
            self->altitude = self->cruise_altitude;
            self->status = "cruising";
        }
    } else if (strcmp(self->status, "cruising") == 0) {
        // do nothing
    } else if (strcmp(self->status, "descending") == 0) {
        if (self->altitude - self->descent_rate > 0) {
            self->altitude -= self->descent_rate;
        } else {
            self->altitude = 0;
            self->status = "landed";
        }
    }
}

int FlightTrajectory_is_landed(FlightTrajectory* self) {
    return strcmp(self->status, "landed") == 0;
}

typedef struct {
    FlightTrajectory* trajectory;
} FlightPlanner;

void FlightPlanner_init(FlightPlanner* self, FlightTrajectory* trajectory) {
    self->trajectory = trajectory;
}

void FlightPlanner_plan_flight(FlightPlanner* self) {
    while (!FlightTrajectory_is_landed(self->trajectory)) {
        FlightTrajectory_update_altitude(self->trajectory);
        FlightPlanner_log_status(self);
    }
}

void FlightPlanner_log_status(FlightPlanner* self) {
    printf("Altitude: %d, Status: %s\n", self->trajectory->altitude, self->trajectory->status);
}

int main() {
    int initial_altitude = 0;
    int rate_of_climb = 1000;
    int cruise_altitude = 30000;
    int descent_rate = 500;
    FlightTrajectory trajectory;
    FlightPlanner planner;

    FlightTrajectory_init(&trajectory, initial_altitude, rate_of_climb, cruise_altitude, descent_rate);
    FlightPlanner_init(&planner, &trajectory);
    FlightPlanner_plan_flight(&planner);

    return 0;
}