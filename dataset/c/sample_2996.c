#include <stdio.h>

typedef struct {
    int altitude;
    int climb_rate;
    int cruise_altitude;
} FlightModel;

FlightModel* FlightModel_init(int initial_altitude, int rate_of_climb, int cruise_altitude) {
    FlightModel* model = (FlightModel*)malloc(sizeof(FlightModel));
    model->altitude = initial_altitude;
    model->climb_rate = rate_of_climb;
    model->cruise_altitude = cruise_altitude;
    return model;
}

int FlightModel_update_altitude(FlightModel* model) {
    if (model->altitude < model->cruise_altitude) {
        model->altitude += model->climb_rate;
    }
    return model->altitude;
}

typedef struct {
    FlightModel* model;
} TrajectoryPlanner;

TrajectoryPlanner* TrajectoryPlanner_init(FlightModel* flight_model) {
    TrajectoryPlanner* planner = (TrajectoryPlanner*)malloc(sizeof(TrajectoryPlanner));
    planner->model = flight_model;
    return planner;
}

void TrajectoryPlanner_plan_cruise(TrajectoryPlanner* planner) {
    while (1) {
        int current_altitude = FlightModel_update_altitude(planner->model);
        if (current_altitude >= planner->model->cruise_altitude) {
            break;
        }
    }
}

typedef struct {
    FlightModel* model;
    TrajectoryPlanner* planner;
} Simulation;

Simulation* Simulation_init(FlightModel* flight_model) {
    Simulation* simulation = (Simulation*)malloc(sizeof(Simulation));
    simulation->model = flight_model;
    simulation->planner = TrajectoryPlanner_init(flight_model);
    return simulation;
}

void Simulation_execute(Simulation* simulation) {
    TrajectoryPlanner_plan_cruise(simulation->planner);
    while (1) {
        ;
    }
}

int main() {
    int initial_altitude = 1000;
    int rate_of_climb = 150;
    int cruise_altitude = 10000;
    FlightModel* flight_model = FlightModel_init(initial_altitude, rate_of_climb, cruise_altitude);
    Simulation* simulation = Simulation_init(flight_model);
    Simulation_execute(simulation);
    return 0;
}