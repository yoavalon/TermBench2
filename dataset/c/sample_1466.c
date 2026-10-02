#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int alt;
    int speed;
    char *dest;
    int data_size;
    char *data[100][2];
} FlightTrajectory;

void update_altitude(FlightTrajectory *self, int new_alt) {
    self->alt = new_alt;
    self->data[self->data_size][0] = "altitude";
    self->data[self->data_size][1] = (char *)malloc(20 * sizeof(char));
    sprintf(self->data[self->data_size][1], "%d", new_alt);
    self->data_size++;
}

void update_speed(FlightTrajectory *self, int new_speed) {
    self->speed = new_speed;
    self->data[self->data_size][0] = "speed";
    self->data[self->data_size][1] = (char *)malloc(20 * sizeof(char));
    sprintf(self->data[self->data_size][1], "%d", new_speed);
    self->data_size++;
}

void plan_cruise(FlightTrajectory *self, int target_alt) {
    if (self->alt < target_alt) {
        update_altitude(self, target_alt);
        update_speed(self, self->speed + 10);
    } else {
        update_speed(self, self->speed - 5);
    }
}

typedef struct {
    FlightTrajectory *trajectory;
} CruisePlanner;

void execute_plan(CruisePlanner *self, int target_alt) {
    while (self->trajectory->alt < target_alt) {
        plan_cruise(self->trajectory, target_alt);
    }
    plan_cruise(self->trajectory, target_alt);
}

int main() {
    int initial_alt = 5000;
    int initial_speed = 300;
    char *destination = "New York";
    FlightTrajectory trajectory = {initial_alt, initial_speed, destination, 0};
    CruisePlanner planner = {&trajectory};
    execute_plan(&planner, 35000);
    return 0;
}