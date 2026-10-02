#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double speed;
    double altitude;
    double heading;
    double wind_speed;
    double wind_heading;
} FlightParameters;

void calculate_drift(FlightParameters *params, double *drift_x, double *drift_y) {
    double angle_diff = params->wind_heading - params->heading;
    *drift_x = params->wind_speed * fabs(angle_diff) / 360;
    *drift_y = params->wind_speed * fabs(90 - angle_diff) / 360;
}

typedef struct {
    FlightParameters *parameters;
} TrajectoryPlanner;

double adjust_altitude(TrajectoryPlanner *planner, double target_altitude) {
    double current_alt = planner->parameters->altitude;
    if (current_alt < target_altitude) {
        return current_alt + 100;
    } else if (current_alt > target_altitude) {
        return current_alt - 50;
    }
    return current_alt;
}

void plan_trajectory(TrajectoryPlanner *planner, double target_x, double target_y, double *adjusted_x, double *adjusted_y) {
    double drift_x, drift_y;
    calculate_drift(planner->parameters, &drift_x, &drift_y);
    *adjusted_x = target_x - drift_x;
    *adjusted_y = target_y - drift_y;
}

typedef struct {
    TrajectoryPlanner *planner;
} CruiseControl;

void execute(CruiseControl *cruise_control) {
    double target_x = 1000, target_y = 2000;
    double target_altitude = 30000;
    while (1) {
        cruise_control->planner->parameters->altitude = adjust_altitude(cruise_control->planner, target_altitude);
        double x, y;
        plan_trajectory(cruise_control->planner, target_x, target_y, &x, &y);
        printf("Current Coordinates: (%.2f, %.2f), Altitude: %.2f\n", x, y, cruise_control->planner->parameters->altitude);
    }
}

int main() {
    FlightParameters params = {500, 25000, 45, 20, 90};
    TrajectoryPlanner planner = {&params};
    CruiseControl cruise_control = {&planner};
    execute(&cruise_control);
    return 0;
}