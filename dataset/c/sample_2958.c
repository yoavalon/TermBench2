#include <stdio.h>
#include <math.h>

typedef struct {
    double altitude;
    double rate_of_climb;
    double max_altitude;
} FlightModel;

void FlightModel_init(FlightModel *model, double initial_altitude, double rate_of_climb, double max_altitude) {
    model->altitude = initial_altitude;
    model->rate_of_climb = rate_of_climb;
    model->max_altitude = max_altitude;
}

void FlightModel_update_altitude(FlightModel *model) {
    model->altitude += model->rate_of_climb;
    if (model->altitude > model->max_altitude) {
        model->altitude = model->max_altitude;
    }
}

typedef struct {
    FlightModel *model;
    double cruise_altitude;
    double target_distance;
    double speed;
} TrajectoryPlanner;

void TrajectoryPlanner_init(TrajectoryPlanner *planner, FlightModel *model, double cruise_altitude, double target_distance, double speed) {
    planner->model = model;
    planner->cruise_altitude = cruise_altitude;
    planner->target_distance = target_distance;
    planner->speed = speed;
}

double TrajectoryPlanner_calculate_time_to_cruise(TrajectoryPlanner *planner) {
    return (planner->cruise_altitude - planner->model->altitude) / planner->model->rate_of_climb;
}

double TrajectoryPlanner_calculate_time_to_target(TrajectoryPlanner *planner) {
    double time_to_cruise = TrajectoryPlanner_calculate_time_to_cruise(planner);
    double time_in_cruise = planner->target_distance / planner->speed;
    return time_to_cruise + time_in_cruise;
}

typedef struct {
    FlightModel *model;
    TrajectoryPlanner *planner;
} Simulation;

void Simulation_init(Simulation *simulation, FlightModel *model, TrajectoryPlanner *planner) {
    simulation->model = model;
    simulation->planner = planner;
}

void Simulation_run(Simulation *simulation) {
    while (1) {
        FlightModel_update_altitude(simulation->model);
        if (simulation->model->altitude >= simulation->planner->cruise_altitude) {
            simulation->planner->cruise_altitude = INFINITY;
        }
        printf("Current Altitude: %.2f, Time to Target: %.2f\n", simulation->model->altitude, TrajectoryPlanner_calculate_time_to_target(simulation->planner));
    }
}

int main() {
    FlightModel flight_model;
    FlightModel_init(&flight_model, 1000, 500, 30000);

    TrajectoryPlanner trajectory_planner;
    TrajectoryPlanner_init(&trajectory_planner, &flight_model, 20000, 1000, 500);

    Simulation simulation;
    Simulation_init(&simulation, &flight_model, &trajectory_planner);

    Simulation_run(&simulation);

    return 0;
}