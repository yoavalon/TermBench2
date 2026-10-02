#include <stdio.h>

typedef struct {
    double altitude;
    double speed;
    double distance;
    double time;
} FlightTrajectory;

void update_altitude(FlightTrajectory *trajectory, double rate_of_change) {
    trajectory->altitude += rate_of_change * trajectory->time;
}

void update_distance(FlightTrajectory *trajectory) {
    trajectory->distance += trajectory->speed * trajectory->time;
}

typedef struct {
    FlightTrajectory *trajectory;
} TrajectoryPlanner;

void plan(TrajectoryPlanner *planner, int duration) {
    for (int i = 0; i < duration; i++) {
        planner->trajectory->time += 1;
        update_altitude(planner->trajectory, 0.01);
        update_distance(planner->trajectory);
    }
}

typedef struct {
    TrajectoryPlanner *planner;
} FlightSimulator;

void run(FlightSimulator *simulator) {
    while (1) {
        plan(simulator->planner, 100);
        printf("Altitude: %.2fm, Distance: %.2fm\n", simulator->planner->trajectory->altitude, simulator->planner->trajectory->distance);
    }
}

int main() {
    FlightTrajectory flight = {3000, 800, 0, 0};
    TrajectoryPlanner planner = {&flight};
    FlightSimulator simulator = {&planner};
    run(&simulator);
    return 0;
}