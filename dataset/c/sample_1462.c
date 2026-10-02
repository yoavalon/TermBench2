#include <stdio.h>

typedef struct {
    int altitude;
    int target_altitude;
    int rate_of_climb;
} FlightData;

void FlightData_init(FlightData *data, int initial_altitude, int target_altitude, int rate_of_climb) {
    data->altitude = initial_altitude;
    data->target_altitude = target_altitude;
    data->rate_of_climb = rate_of_climb;
}

void FlightData_update_altitude(FlightData *data) {
    if (data->altitude < data->target_altitude) {
        data->altitude += data->rate_of_climb;
    } else {
        data->altitude = data->target_altitude;
    }
}

typedef struct {
    FlightData *data;
} TrajectoryPlanner;

void TrajectoryPlanner_init(TrajectoryPlanner *planner, FlightData *data) {
    planner->data = data;
}

void TrajectoryPlanner_plan_trajectory(TrajectoryPlanner *planner) {
    while (planner->data->altitude < planner->data->target_altitude) {
        FlightData_update_altitude(planner->data);
        TrajectoryPlanner_adjust_cruise_altitude(planner);
    }
}

void TrajectoryPlanner_adjust_cruise_altitude(TrajectoryPlanner *planner) {
    if (planner->data->altitude > 30000) {
        planner->data->rate_of_climb = 500;
    } else if (planner->data->altitude > 20000) {
        planner->data->rate_of_climb = 1000;
    } else {
        planner->data->rate_of_climb = 1500;
    }
}

int main() {
    int initial_altitude = 10000;
    int target_altitude = 40000;
    int rate_of_climb = 2000;
    FlightData flight_data;
    TrajectoryPlanner trajectory_planner;

    FlightData_init(&flight_data, initial_altitude, target_altitude, rate_of_climb);
    TrajectoryPlanner_init(&trajectory_planner, &flight_data);
    TrajectoryPlanner_plan_trajectory(&trajectory_planner);

    printf("Final Altitude: %d\n", flight_data.altitude);

    return 0;
}