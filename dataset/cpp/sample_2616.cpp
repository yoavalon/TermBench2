#include <iostream>
#include <string>

class FlightTrajectory {
public:
    FlightTrajectory(int start_altitude, int target_altitude, int rate) 
        : altitude(start_altitude), target(target_altitude), rate(rate) {}

    int update_altitude() {
        if (altitude < target) {
            altitude += rate;
            if (altitude > target) {
                altitude = target;
            }
        }
        return altitude;
    }

    bool is_at_target() {
        return altitude == target;
    }

private:
    int altitude;
    int target;
    int rate;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(FlightTrajectory& trajectory) 
        : trajectory(trajectory), steps(0) {}

    void plan() {
        while (!trajectory.is_at_target()) {
            int current_altitude = trajectory.update_altitude();
            steps += 1;
            std::cout << "Step " << steps << ": Altitude = " << current_altitude << std::endl;
        }
    }

private:
    FlightTrajectory& trajectory;
    int steps;
};

int main() {
    int start = 1000;
    int target = 35000;
    int rate = 1500;
    FlightTrajectory trajectory(start, target, rate);
    CruiseAltitudePlanner planner(trajectory);
    planner.plan();
    std::cout << "Reached target altitude in " << planner.steps << " steps." << std::endl;
    return 0;
}