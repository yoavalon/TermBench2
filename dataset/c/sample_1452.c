#include <stdio.h>

typedef struct {
    int altitude;
    int target_altitude;
    int max_altitude;
    int rate_of_climb;
    int time;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int target_altitude, int max_altitude, int rate_of_climb) {
    self->altitude = initial_altitude;
    self->target_altitude = target_altitude;
    self->max_altitude = max_altitude;
    self->rate_of_climb = rate_of_climb;
    self->time = 0;
}

void FlightTrajectory_update_altitude(FlightTrajectory *self) {
    if (self->altitude < self->target_altitude) {
        self->altitude += self->rate_of_climb;
        if (self->altitude > self->max_altitude) {
            self->altitude = self->max_altitude;
        }
    }
    self->time += 1;
}

int FlightTrajectory_is_complete(FlightTrajectory *self) {
    return self->altitude >= self->target_altitude;
}

typedef struct {
    FlightTrajectory *trajectory;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *self, FlightTrajectory *trajectory) {
    self->trajectory = trajectory;
}

void CruiseAltitudePlanner_plan_cruise(CruiseAltitudePlanner *self, int *final_altitude, int *climb_time) {
    while (!FlightTrajectory_is_complete(self->trajectory)) {
        FlightTrajectory_update_altitude(self->trajectory);
    }
    *final_altitude = self->trajectory->altitude;
    *climb_time = self->trajectory->time;
}

int main() {
    int initial_altitude = 1000;
    int target_altitude = 35000;
    int max_altitude = 40000;
    int rate_of_climb = 1500;
    FlightTrajectory trajectory;
    CruiseAltitudePlanner planner;
    int final_altitude, climb_time;

    FlightTrajectory_init(&trajectory, initial_altitude, target_altitude, max_altitude, rate_of_climb);
    CruiseAltitudePlanner_init(&planner, &trajectory);
    CruiseAltitudePlanner_plan_cruise(&planner, &final_altitude, &climb_time);
    printf("Final Altitude: %d, Climb Time: %d\n", final_altitude, climb_time);

    return 0;
}