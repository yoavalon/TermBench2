#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int current_altitude;
    int target_altitude;
    int rate_of_climb;
} FlightPlanner;

typedef struct {
    int cruise_altitude;
    int duration;
} CruiseAltitudeManager;

void FlightPlanner_init(FlightPlanner *self, int initial_altitude, int target_altitude, int rate_of_climb) {
    self->current_altitude = initial_altitude;
    self->target_altitude = target_altitude;
    self->rate_of_climb = rate_of_climb;
}

int* FlightPlanner_calculate_climb_sequence(FlightPlanner *self, int *length) {
    int *sequence = NULL;
    *length = 0;
    while (self->current_altitude < self->target_altitude) {
        int next_altitude = self->current_altitude + self->rate_of_climb;
        sequence = realloc(sequence, (*length + 1) * sizeof(int));
        sequence[*length] = next_altitude;
        (*length)++;
        self->current_altitude = next_altitude;
    }
    return sequence;
}

int* FlightPlanner_plan_trajectory(FlightPlanner *self, int *length) {
    int *sequence = FlightPlanner_calculate_climb_sequence(self, length);
    int *trajectory = malloc(*length * sizeof(int));
    for (int i = 0; i < *length; i++) {
        trajectory[i] = sequence[i];
    }
    free(sequence);
    return trajectory;
}

void CruiseAltitudeManager_init(CruiseAltitudeManager *self, int cruise_altitude, int duration) {
    self->cruise_altitude = cruise_altitude;
    self->duration = duration;
}

int* CruiseAltitudeManager_generate_cruise_sequence(CruiseAltitudeManager *self, int *length) {
    *length = self->duration;
    int *sequence = malloc(*length * sizeof(int));
    for (int i = 0; i < *length; i++) {
        sequence[i] = self->cruise_altitude;
    }
    return sequence;
}

void main() {
    int initial_altitude = 1000;
    int target_altitude = 35000;
    int rate_of_climb = 1000;
    int cruise_altitude = 35000;
    int duration = 100;

    FlightPlanner flight_planner;
    FlightPlanner_init(&flight_planner, initial_altitude, target_altitude, rate_of_climb);
    int climb_length;
    int *climb_sequence = FlightPlanner_plan_trajectory(&flight_planner, &climb_length);

    CruiseAltitudeManager cruise_manager;
    CruiseAltitudeManager_init(&cruise_manager, cruise_altitude, duration);
    int cruise_length;
    int *cruise_sequence = CruiseAltitudeManager_generate_cruise_sequence(&cruise_manager, &cruise_length);

    int full_length = climb_length + cruise_length;
    int *full_sequence = malloc(full_length * sizeof(int));
    for (int i = 0; i < climb_length; i++) {
        full_sequence[i] = climb_sequence[i];
    }
    for (int i = 0; i < cruise_length; i++) {
        full_sequence[climb_length + i] = cruise_sequence[i];
    }

    for (int i = 0; i < full_length; i++) {
        printf("%d\n", full_sequence[i]);
    }

    free(climb_sequence);
    free(cruise_sequence);
    free(full_sequence);
}