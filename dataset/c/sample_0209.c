#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altitude;
    int velocity;
    int target_altitude;
    int current_step;
} FlightPlanner;

typedef struct {
    int max_altitude;
    int min_altitude;
} BoundaryChecker;

void FlightPlanner_init(FlightPlanner *planner, int altitude, int velocity, int target_altitude) {
    planner->altitude = altitude;
    planner->velocity = velocity;
    planner->target_altitude = target_altitude;
    planner->current_step = 0;
}

void FlightPlanner_calculate_step(FlightPlanner *planner) {
    if (planner->altitude < planner->target_altitude) {
        planner->altitude += planner->velocity;
        planner->current_step += 1;
    } else {
        fprintf(stderr, "StopIteration\n");
        exit(1);
    }
}

void FlightPlanner_get_status(const FlightPlanner *planner, int *altitude, int *current_step) {
    *altitude = planner->altitude;
    *current_step = planner->current_step;
}

void BoundaryChecker_init(BoundaryChecker *checker, int max_altitude, int min_altitude) {
    checker->max_altitude = max_altitude;
    checker->min_altitude = min_altitude;
}

void BoundaryChecker_check_bounds(const BoundaryChecker *checker, int altitude) {
    if (altitude > checker->max_altitude || altitude < checker->min_altitude) {
        fprintf(stderr, "ValueError: Boundary conditions violated\n");
        exit(1);
    }
}

int main() {
    int initial_altitude = 1000;
    int velocity = 200;
    int target_altitude = 3000;
    int max_altitude = 5000;
    int min_altitude = 500;
    FlightPlanner planner;
    BoundaryChecker checker;

    FlightPlanner_init(&planner, initial_altitude, velocity, target_altitude);
    BoundaryChecker_init(&checker, max_altitude, min_altitude);

    try {
        while (1) {
            FlightPlanner_calculate_step(&planner);
            int current_altitude, step_count;
            FlightPlanner_get_status(&planner, &current_altitude, &step_count);
            BoundaryChecker_check_bounds(&checker, current_altitude);
            printf("Step: %d, Altitude: %d\n", step_count, current_altitude);
        }
    } catch (StopIteration e) {
        printf("Termination: StopIteration\n");
    } catch (ValueError e) {
        printf("Termination: Boundary conditions violated\n");
    }

    return 0;
}