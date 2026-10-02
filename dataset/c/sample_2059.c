#include <stdio.h>

typedef struct {
    double altitude;
    double target;
    double speed;
    double descent;
    int time;
} FlightPlanner;

void FlightPlanner_init(FlightPlanner *planner, double initial_altitude, double target_altitude, double speed, double descent_rate) {
    planner->altitude = initial_altitude;
    planner->target = target_altitude;
    planner->speed = speed;
    planner->descent = descent_rate;
    planner->time = 0;
}

void FlightPlanner_update_altitude(FlightPlanner *planner) {
    if (planner->altitude > planner->target) {
        planner->altitude -= planner->descent * planner->speed;
        planner->time += 1;
    } else {
        planner->altitude = planner->target;
    }
}

void FlightPlanner_get_flight_data(FlightPlanner *planner, double *altitude, int *time) {
    *altitude = planner->altitude;
    *time = planner->time;
}

typedef struct {
    FlightPlanner *planner;
} TrajectoryAnalyzer;

void TrajectoryAnalyzer_init(TrajectoryAnalyzer *analyzer, FlightPlanner *planner) {
    analyzer->planner = planner;
}

void TrajectoryAnalyzer_analyze(TrajectoryAnalyzer *analyzer, double **trajectory_data, int *data_size) {
    *data_size = 0;
    *trajectory_data = NULL;
    while (analyzer->planner->altitude > analyzer->planner->target) {
        FlightPlanner_update_altitude(analyzer->planner);
        *data_size += 1;
        *trajectory_data = realloc(*trajectory_data, *data_size * sizeof(double) * 2);
        double altitude;
        int time;
        FlightPlanner_get_flight_data(analyzer->planner, &altitude, &time);
        (*trajectory_data)[(*data_size) * 2 - 2] = time;
        (*trajectory_data)[(*data_size) * 2 - 1] = altitude;
    }
}

int main() {
    double initial_altitude = 35000.0;
    double target_altitude = 10000.0;
    double speed = 0.5;
    double descent_rate = 100.0;
    FlightPlanner planner;
    FlightPlanner_init(&planner, initial_altitude, target_altitude, speed, descent_rate);
    TrajectoryAnalyzer analyzer;
    TrajectoryAnalyzer_init(&analyzer, &planner);
    double *trajectory_data;
    int data_size;
    TrajectoryAnalyzer_analyze(&analyzer, &trajectory_data, &data_size);
    for (int i = 0; i < data_size; i++) {
        printf("Time: %d, Altitude: %f\n", (int)trajectory_data[i * 2], trajectory_data[i * 2 + 1]);
    }
    free(trajectory_data);
    return 0;
}