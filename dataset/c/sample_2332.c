#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double altitude;
    double velocity;
    double wind_speed;
} FlightData;

void FlightData_update_altitude(FlightData *self, double adjustment) {
    self->altitude += adjustment;
}

double FlightData_calculate_drag(FlightData *self) {
    return 0.5 * self->velocity * self->wind_speed;
}

typedef struct {
    FlightData *flight_data;
} TrajectoryPlanner;

void TrajectoryPlanner_optimize_altitude(TrajectoryPlanner *self, double target_drag) {
    double adjustment = 0.1;
    while (1) {
        double drag = FlightData_calculate_drag(self->flight_data);
        if (fabs(drag - target_drag) < 0.01) {
            break;
        }
        if (drag > target_drag) {
            adjustment = -adjustment;
        }
        FlightData_update_altitude(self->flight_data, adjustment);
    }
}

void TrajectoryPlanner_plan_cruise(TrajectoryPlanner *self) {
    double target_drag = 150.0;
    TrajectoryPlanner_optimize_altitude(self, target_drag);
}

typedef struct {
    FlightData flight_data;
    TrajectoryPlanner planner;
} FlightControl;

void FlightControl_execute_flight_plan(FlightControl *self) {
    while (1) {
        TrajectoryPlanner_plan_cruise(&self->planner);
    }
}

int main() {
    FlightData flight_data = {30000, 800, 50};
    TrajectoryPlanner planner = {&flight_data};
    FlightControl flight_control = {flight_data, planner};
    FlightControl_execute_flight_plan(&flight_control);
    return 0;
}