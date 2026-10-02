#include <iostream>
#include <string>

class FlightTrajectory {
public:
    FlightTrajectory(int start_altitude, int target_altitude, int rate_of_climb) {
        altitude = start_altitude;
        target = target_altitude;
        rate = rate_of_climb;
        status = "ascending";
    }

    int update_altitude() {
        if (status == "ascending") {
            altitude += rate;
            if (altitude >= target) {
                status = "cruising";
                altitude = target;
            }
        }
        return altitude;
    }

    bool is_cruising() {
        return status == "cruising";
    }

private:
    int altitude;
    int target;
    int rate;
    std::string status;
};

int plan_cruise_altitude(FlightTrajectory& trajectory, int max_iterations) {
    int iteration = 0;
    while (iteration < max_iterations && !trajectory.is_cruising()) {
        trajectory.update_altitude();
        iteration += 1;
    }
    return trajectory.update_altitude();
}

int main() {
    int start = 1000;
    int target = 35000;
    int rate = 500;
    int max_iter = 1000;
    FlightTrajectory trajectory(start, target, rate);
    int final_altitude = plan_cruise_altitude(trajectory, max_iter);
    std::cout << "Final Cruise Altitude: " << final_altitude << std::endl;
    return 0;
}