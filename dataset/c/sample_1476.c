#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int current_altitude;
    int target_altitude;
    int rate_of_climb;
    int max_altitude;
} FlightPlanner;

void FlightPlanner_init(FlightPlanner *self, int initial_altitude, int target_altitude, int rate_of_climb, int max_altitude) {
    self->current_altitude = initial_altitude;
    self->target_altitude = target_altitude;
    self->rate_of_climb = rate_of_climb;
    self->max_altitude = max_altitude;
}

void FlightPlanner_climb(FlightPlanner *self) {
    if (self->current_altitude < self->target_altitude) {
        self->current_altitude += self->rate_of_climb;
        if (self->current_altitude > self->max_altitude) {
            self->current_altitude = self->max_altitude;
        }
    }
}

int FlightPlanner_stabilize(FlightPlanner *self) {
    if (self->current_altitude == self->target_altitude) {
        return 1;
    }
    return 0;
}

int FlightPlanner_plan_flight(FlightPlanner *self) {
    while (!FlightPlanner_stabilize(self)) {
        FlightPlanner_climb(self);
    }
    return self->current_altitude;
}

typedef struct {
    int *altitudes;
    int size;
} FlightData;

void FlightData_init(FlightData *self, int initial_altitude) {
    self->altitudes = (int *)malloc(sizeof(int));
    self->altitudes[0] = initial_altitude;
    self->size = 1;
}

void FlightData_update_altitude(FlightData *self, int new_altitude) {
    self->altitudes = (int *)realloc(self->altitudes, (self->size + 1) * sizeof(int));
    self->altitudes[self->size] = new_altitude;
    self->size++;
}

int *FlightData_get_altitudes(FlightData *self, int *size) {
    *size = self->size;
    return self->altitudes;
}

typedef struct {
    FlightPlanner *planner;
    FlightData *data;
} FlightController;

void FlightController_init(FlightController *self, FlightPlanner *planner, FlightData *data) {
    self->planner = planner;
    self->data = data;
}

int *FlightController_execute_flight(FlightController *self, int *size) {
    int final_altitude = FlightPlanner_plan_flight(self->planner);
    FlightData_update_altitude(self->data, final_altitude);
    return FlightData_get_altitudes(self->data, size);
}

void main() {
    int initial_altitude = 5000;
    int target_altitude = 35000;
    int rate_of_climb = 1000;
    int max_altitude = 40000;

    FlightPlanner planner;
    FlightPlanner_init(&planner, initial_altitude, target_altitude, rate_of_climb, max_altitude);

    FlightData data;
    FlightData_init(&data, initial_altitude);

    FlightController controller;
    FlightController_init(&controller, &planner, &data);

    int size;
    int *altitudes = FlightController_execute_flight(&controller, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", altitudes[i]);
    }
    printf("\n");

    free(data.altitudes);
}