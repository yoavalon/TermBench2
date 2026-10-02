#include <stdio.h>

typedef struct {
    int current_altitude;
    int target_altitude;
    int altitude_step;
    int descent_rate;
} FlightPlanner;

typedef struct {
    int current_position;
    int target_position;
    int position_step;
    int direction;
} TrajectoryAnalyzer;

void FlightPlanner_init(FlightPlanner *fp, int initial_altitude, int target_altitude, int altitude_step, int descent_rate) {
    fp->current_altitude = initial_altitude;
    fp->target_altitude = target_altitude;
    fp->altitude_step = altitude_step;
    fp->descent_rate = descent_rate;
}

void FlightPlanner_adjust_altitude(FlightPlanner *fp) {
    if (fp->current_altitude > fp->target_altitude) {
        fp->current_altitude -= fp->altitude_step;
        if (fp->current_altitude < fp->target_altitude) {
            fp->current_altitude = fp->target_altitude;
        }
    } else {
        fp->current_altitude += fp->altitude_step;
        if (fp->current_altitude > fp->target_altitude) {
            fp->current_altitude = fp->target_altitude;
        }
    }
}

int FlightPlanner_simulate_flight(FlightPlanner *fp) {
    while (fp->current_altitude != fp->target_altitude) {
        FlightPlanner_adjust_altitude(fp);
    }
    return fp->current_altitude;
}

void TrajectoryAnalyzer_init(TrajectoryAnalyzer *ta, int initial_position, int target_position, int position_step, int direction) {
    ta->current_position = initial_position;
    ta->target_position = target_position;
    ta->position_step = position_step;
    ta->direction = direction;
}

void TrajectoryAnalyzer_update_position(TrajectoryAnalyzer *ta) {
    if (ta->current_position < ta->target_position) {
        ta->current_position += ta->position_step;
    } else if (ta->current_position > ta->target_position) {
        ta->current_position -= ta->position_step;
    }
}

int TrajectoryAnalyzer_analyze_trajectory(TrajectoryAnalyzer *ta) {
    while (ta->current_position != ta->target_position) {
        TrajectoryAnalyzer_update_position(ta);
    }
    return ta->current_position;
}

void main() {
    FlightPlanner altitude_planner;
    TrajectoryAnalyzer trajectory_analyzer;

    FlightPlanner_init(&altitude_planner, 30000, 35000, 1000, 500);
    TrajectoryAnalyzer_init(&trajectory_analyzer, 0, 1000, 100, 1);

    int final_altitude = FlightPlanner_simulate_flight(&altitude_planner);
    int final_position = TrajectoryAnalyzer_analyze_trajectory(&trajectory_analyzer);

    printf("Final Altitude: %d\n", final_altitude);
    printf("Final Position: %d\n", final_position);
}