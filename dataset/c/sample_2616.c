#include <stdio.h>

typedef struct {
    int altitude;
    int target;
    int rate;
} FlightTrajectory;

FlightTrajectory* FlightTrajectory_new(int start_altitude, int target_altitude, int rate) {
    FlightTrajectory* self = (FlightTrajectory*)malloc(sizeof(FlightTrajectory));
    self->altitude = start_altitude;
    self->target = target_altitude;
    self->rate = rate;
    return self;
}

int FlightTrajectory_update_altitude(FlightTrajectory* self) {
    if (self->altitude < self->target) {
        self->altitude += self->rate;
        if (self->altitude > self->target) {
            self->altitude = self->target;
        }
    }
    return self->altitude;
}

int FlightTrajectory_is_at_target(FlightTrajectory* self) {
    return self->altitude == self->target;
}

typedef struct {
    FlightTrajectory* trajectory;
    int steps;
} CruiseAltitudePlanner;

CruiseAltitudePlanner* CruiseAltitudePlanner_new(FlightTrajectory* trajectory) {
    CruiseAltitudePlanner* self = (CruiseAltitudePlanner*)malloc(sizeof(CruiseAltitudePlanner));
    self->trajectory = trajectory;
    self->steps = 0;
    return self;
}

void CruiseAltitudePlanner_plan(CruiseAltitudePlanner* self) {
    while (!FlightTrajectory_is_at_target(self->trajectory)) {
        int current_altitude = FlightTrajectory_update_altitude(self->trajectory);
        self->steps += 1;
        printf("Step %d: Altitude = %d\n", self->steps, current_altitude);
    }
}

int main() {
    int start = 1000;
    int target = 35000;
    int rate = 1500;
    FlightTrajectory* trajectory = FlightTrajectory_new(start, target, rate);
    CruiseAltitudePlanner* planner = CruiseAltitudePlanner_new(trajectory);
    CruiseAltitudePlanner_plan(planner);
    printf("Reached target altitude in %d steps.\n", planner->steps);
    free(trajectory);
    free(planner);
    return 0;
}