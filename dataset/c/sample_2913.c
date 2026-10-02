#include <stdio.h>

typedef struct {
    int altitude;
    int rate_of_ascent;
    int target_altitude;
} FlightPlanner;

int calculate_time_to_target(FlightPlanner *planner) {
    return (planner->target_altitude - planner->altitude) / planner->rate_of_ascent;
}

int adjust_rate_of_ascent(FlightPlanner *planner) {
    int time_to_target = calculate_time_to_target(planner);
    if (time_to_target < 10) {
        return planner->rate_of_ascent * 1.2;
    } else if (time_to_target > 20) {
        return planner->rate_of_ascent * 0.8;
    }
    return planner->rate_of_ascent;
}

int update_altitude(FlightPlanner *planner) {
    planner->rate_of_ascent = adjust_rate_of_ascent(planner);
    planner->altitude += planner->rate_of_ascent;
    return planner->altitude;
}

typedef struct {
    FlightPlanner planner;
} FlightSequence;

void execute_sequence(FlightSequence *sequence) {
    while (1) {
        int current_altitude = update_altitude(&sequence->planner);
        if (current_altitude >= sequence->planner.target_altitude) {
            sequence->planner.altitude = sequence->planner.target_altitude;
        }
        printf("Current Altitude: %d\n", current_altitude);
    }
}

void main() {
    int initial_altitude = 1000;
    int rate_of_ascent = 150;
    int target_altitude = 35000;
    FlightSequence sequence;
    sequence.planner.altitude = initial_altitude;
    sequence.planner.rate_of_ascent = rate_of_ascent;
    sequence.planner.target_altitude = target_altitude;
    execute_sequence(&sequence);
}