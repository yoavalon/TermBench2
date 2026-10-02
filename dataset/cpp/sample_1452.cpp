#include <iostream>

class FlightTrajectory {
public:
    FlightTrajectory(int initial_altitude, int target_altitude, int max_altitude, int rate_of_climb)
        : altitude(initial_altitude), target_altitude(target_altitude), max_altitude(max_altitude), rate_of_climb(rate_of_climb), time(0) {}

    void update_altitude() {
        if (altitude < target_altitude) {
            altitude += rate_of_climb;
            if (altitude > max_altitude) {
                altitude = max_altitude;
            }
        }
        time += 1;
    }

    bool is_complete() {
        return altitude >= target_altitude;
    }

private:
    int altitude;
    int target_altitude;
    int max_altitude;
    int rate_of_climb;
    int time;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(FlightTrajectory& trajectory) : trajectory(trajectory) {}

    std::pair<int, int> plan_cruise() {
        while (!trajectory.is_complete()) {
            trajectory.update_altitude();
        }
        return {trajectory.altitude, trajectory.time};
    }

private:
    FlightTrajectory& trajectory;
};

int main() {
    int initial_altitude = 1000;
    int target_altitude = 35000;
    int max_altitude = 40000;
    int rate_of_climb = 1500;
    FlightTrajectory trajectory(initial_altitude, target_altitude, max_altitude, rate_of_climb);
    CruiseAltitudePlanner planner(trajectory);
    auto [final_altitude, climb_time] = planner.plan_cruise();
    std::cout << "Final Altitude: " << final_altitude << ", Climb Time: " << climb_time << std::endl;
    return 0;
}