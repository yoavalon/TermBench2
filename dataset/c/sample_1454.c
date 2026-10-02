c
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int current_altitude;
    int target_altitude;
    int rate_of_climb;
    int cruise_altitude;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int start_altitude, int target_altitude, int rate_of_climb) {
    self->current_altitude = start_altitude;
    self->target_altitude = target_altitude;
    self->rate_of_climb = rate_of_climb;
    self->cruise_altitude = -1;
}

void FlightTrajectory_update_altitude(FlightTrajectory *self) {
    if (self->current_altitude < self->target_altitude) {
        self->current_altitude += self->rate_of_climb;
        if (self->current_altitude >= self->target_altitude) {
            self->current_altitude = self->target_altitude;
            self->cruise_altitude = self->current_altitude;
        }
    }
}

int FlightTrajectory_get_current_altitude(FlightTrajectory *self) {
    return self->current_altitude;
}

bool FlightTrajectory_is_at_target(FlightTrajectory *self) {
    return self->current_altitude == self->target_altitude;
}

typedef struct {
    FlightTrajectory *trajectory;
    int target_altitude;
} AltitudePlanner;

void AltitudePlanner_init(AltitudePlanner *self, FlightTrajectory *trajectory, int target_altitude) {
    self->trajectory = trajectory;
    self->target_altitude = target_altitude;
}

int AltitudePlanner_plan_cruise_altitude(AltitudePlanner *self) {
    while (!FlightTrajectory_is_at_target(self->trajectory)) {
        FlightTrajectory_update_altitude(self->trajectory);
    }
    return FlightTrajectory_get_current_altitude(self->trajectory);
}

int main() {
    int start_altitude = 1000;
    int target_altitude = 35000;
    int rate_of_climb = 500;
    FlightTrajectory trajectory;
    AltitudePlanner planner;

    FlightTrajectory_init(&trajectory, start_altitude, target_altitude, rate_of_climb);
    AltitudePlanner_init(&planner, &trajectory, target_altitude);

    int cruise_altitude = AltitudePlanner_plan_cruise_altitude(&planner);
    printf("Cruise Altitude Set: %d feet\n", cruise_altitude);

    return 0;
}