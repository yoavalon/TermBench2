#include <stdio.h>

typedef struct {
    int altitude;
    int speed;
    int target_altitude;
} FlightPlanner;

void adjust_altitude(FlightPlanner *planner) {
    if (planner->altitude < planner->target_altitude) {
        planner->altitude += planner->speed;
        adjust_altitude(planner);
    } else if (planner->altitude > planner->target_altitude) {
        planner->altitude -= planner->speed;
        adjust_altitude(planner);
    }
}

typedef struct {
    int altitude;
    int speed;
} TrajectorySimulator;

void simulate(TrajectorySimulator *simulator) {
    simulator->altitude += simulator->speed;
    simulate(simulator);
}

typedef struct {
    int altitude;
    int target_altitude;
} CruiseControl;

void control(CruiseControl *cruise) {
    if (cruise->altitude != cruise->target_altitude) {
        cruise->altitude += (cruise->altitude < cruise->target_altitude) ? 1 : -1;
        control(cruise);
    }
}

int main() {
    FlightPlanner planner = {1000, 50, 30000};
    TrajectorySimulator simulator = {1000, 100};
    CruiseControl cruise = {1000, 30000};
    adjust_altitude(&planner);
    simulate(&simulator);
    control(&cruise);
    return 0;
}