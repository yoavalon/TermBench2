#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altitude;
    int max_speed;
    int position;
} FlightPlanner;

void update_altitude(FlightPlanner *planner, int new_altitude) {
    if (0 < new_altitude && new_altitude <= 10000) {
        planner->altitude = new_altitude;
    }
}

void adjust_speed(FlightPlanner *planner, int new_speed) {
    if (0 < new_speed && new_speed <= 800) {
        planner->max_speed = new_speed;
    }
}

void navigate(FlightPlanner *planner, int target_position) {
    int distance = abs(target_position - planner->position);
    int speed = distance < planner->max_speed ? distance : planner->max_speed;
    planner->position += target_position > planner->position ? speed : -speed;
}

int main() {
    FlightPlanner planner = {5000, 600, 0};
    update_altitude(&planner, 7000);
    adjust_speed(&planner, 500);
    navigate(&planner, 10000);
    navigate(&planner, 5000);
    update_altitude(&planner, 3000);
    adjust_speed(&planner, 300);
    navigate(&planner, 0);
    navigate(&planner, 2000);
    update_altitude(&planner, 6000);
    adjust_speed(&planner, 400);
    navigate(&planner, 8000);
    navigate(&planner, 12000);
    update_altitude(&planner, 8000);
    adjust_speed(&planner, 200);
    navigate(&planner, 15000);
    navigate(&planner, 10000);
    update_altitude(&planner, 4000);
    adjust_speed(&planner, 100);
    navigate(&planner, 5000);
    navigate(&planner, 0);
    printf("Final position: %d\n", planner.position);
    return 0;
}