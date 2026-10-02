#include <stdio.h>

typedef struct {
    int altitude;
    int climb_rate;
    int cruise_altitude;
    int descent_rate;
    char *state;
} FlightTrajectory;

void init_flight_trajectory(FlightTrajectory *trajectory, int start_altitude, int rate_of_climb, int cruise_altitude, int descent_rate) {
    trajectory->altitude = start_altitude;
    trajectory->climb_rate = rate_of_climb;
    trajectory->cruise_altitude = cruise_altitude;
    trajectory->descent_rate = descent_rate;
    trajectory->state = "climb";
}

void update_altitude(FlightTrajectory *trajectory) {
    if (strcmp(trajectory->state, "climb") == 0) {
        if (trajectory->altitude < trajectory->cruise_altitude) {
            trajectory->altitude += trajectory->climb_rate;
        } else {
            trajectory->state = "cruise";
        }
    } else if (strcmp(trajectory->state, "cruise") == 0) {
        // Do nothing
    } else if (strcmp(trajectory->state, "descent") == 0) {
        if (trajectory->altitude > 0) {
            trajectory->altitude -= trajectory->descent_rate;
        } else {
            trajectory->state = "landed";
        }
    }
}

void check_state(FlightTrajectory *trajectory) {
    if (trajectory->altitude >= trajectory->cruise_altitude && strcmp(trajectory->state, "climb") == 0) {
        trajectory->state = "cruise";
    } else if (trajectory->altitude <= 0 && strcmp(trajectory->state, "descent") == 0) {
        trajectory->state = "landed";
    }
}

void simulate_flight() {
    FlightTrajectory trajectory;
    init_flight_trajectory(&trajectory, 0, 500, 35000, 300);
    while (1) {
        update_altitude(&trajectory);
        check_state(&trajectory);
    }
}

int main() {
    simulate_flight();
    return 0;
}