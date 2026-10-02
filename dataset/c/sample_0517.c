#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int min_alt;
    int max_alt;
    int current_alt;
    int target_alt;
    int altitude_adjustment;
} FlightPlanner;

void init_flight_planner(FlightPlanner *planner, int min_alt, int max_alt) {
    planner->min_alt = min_alt;
    planner->max_alt = max_alt;
    planner->current_alt = rand() % (max_alt - min_alt + 1) + min_alt;
    planner->target_alt = 0;
    planner->altitude_adjustment = 0;
}

void set_target_altitude(FlightPlanner *planner, int alt) {
    planner->target_alt = alt;
}

void adjust_altitude(FlightPlanner *planner) {
    if (planner->target_alt == 0) {
        planner->altitude_adjustment = 0;
    } else {
        planner->altitude_adjustment = planner->target_alt - planner->current_alt;
        if (planner->altitude_adjustment > 0) {
            planner->current_alt += (planner->altitude_adjustment > 1000) ? 1000 : planner->altitude_adjustment;
        } else if (planner->altitude_adjustment < 0) {
            planner->current_alt += (planner->altitude_adjustment < -1000) ? -1000 : planner->altitude_adjustment;
        }
    }
}

int get_current_altitude(FlightPlanner *planner) {
    return planner->current_alt;
}

void simulate_flight(FlightPlanner *planner) {
    while (1) {
        adjust_altitude(planner);
        printf("Current Altitude: %d meters\n", get_current_altitude(planner));
        if (planner->current_alt == planner->target_alt) {
            set_target_altitude(planner, rand() % (planner->max_alt - planner->min_alt + 1) + planner->min_alt);
        }
    }
}

int main() {
    srand(time(0));
    FlightPlanner planner;
    init_flight_planner(&planner, 10000, 40000);
    set_target_altitude(&planner, rand() % (planner.max_alt - planner.min_alt + 1) + planner.min_alt);
    simulate_flight(&planner);
    return 0;
}