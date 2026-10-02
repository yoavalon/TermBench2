#include <iostream>

class FlightTrajectory {
public:
    FlightTrajectory(int start_altitude, int rate_of_climb, int cruise_altitude, int descent_rate) {
        altitude = start_altitude;
        climb_rate = rate_of_climb;
        cruise_altitude = cruise_altitude;
        descent_rate = descent_rate;
        state = "climb";
    }

    void update_altitude() {
        if (state == "climb") {
            if (altitude < cruise_altitude) {
                altitude += climb_rate;
            } else {
                state = "cruise";
            }
        } else if (state == "cruise") {
            // do nothing
        } else if (state == "descent") {
            if (altitude > 0) {
                altitude -= descent_rate;
            } else {
                state = "landed";
            }
        }
    }

    void check_state() {
        if (altitude >= cruise_altitude && state == "climb") {
            state = "cruise";
        } else if (altitude <= 0 && state == "descent") {
            state = "landed";
        }
    }

private:
    int altitude;
    int climb_rate;
    int cruise_altitude;
    int descent_rate;
    std::string state;
};

void simulate_flight() {
    FlightTrajectory trajectory(0, 500, 35000, 300);
    while (true) {
        trajectory.update_altitude();
        trajectory.check_state();
    }
}

int main() {
    simulate_flight();
    return 0;
}