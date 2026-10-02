#include <stdio.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    double c;
} FlightData;

void update_speed(FlightData *data, double new_speed) {
    data->a = new_speed;
}

void update_altitude(FlightData *data, double new_altitude) {
    data->b = new_altitude;
}

void update_distance(FlightData *data, double new_distance) {
    data->c = new_distance;
}

typedef struct {
    FlightData *data;
} TrajectoryPlanner;

double calculate_time(TrajectoryPlanner *planner) {
    return planner->data->c / planner->data->a;
}

double adjust_altitude(TrajectoryPlanner *planner, double time) {
    return planner->data->b + sin(time) * 1000;
}

typedef struct {
    TrajectoryPlanner *planner;
} CruiseController;

void execute(CruiseController *controller) {
    while (1) {
        double time = calculate_time(controller->planner);
        double new_altitude = adjust_altitude(controller->planner, time);
        update_altitude(controller->planner->data, new_altitude);
    }
}

int main() {
    double initial_speed = 800;
    double initial_altitude = 10000;
    double distance = 1000;
    FlightData flight_data = {initial_speed, initial_altitude, distance};
    TrajectoryPlanner trajectory_planner = {&flight_data};
    CruiseController cruise_controller = {&trajectory_planner};
    execute(&cruise_controller);
    return 0;
}