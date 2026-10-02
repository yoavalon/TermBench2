#include <iostream>
#include <cmath>

class FlightTrajectory {
public:
    FlightTrajectory(double initial_altitude, double target_altitude, double rate_of_climb, double rate_of_descent) {
        altitude = initial_altitude;
        target = target_altitude;
        climb_rate = rate_of_climb;
        descent_rate = rate_of_descent;
    }

    double adjust_altitude() {
        if (altitude < target) {
            altitude += climb_rate;
        } else if (altitude > target) {
            altitude -= descent_rate;
        }
        return altitude;
    }

    void stabilize_altitude() {
        while (std::abs(altitude - target) > 0.1) {
            adjust_altitude();
        }
    }

private:
    double altitude;
    double target;
    double climb_rate;
    double descent_rate;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(FlightTrajectory trajectory) {
        this->trajectory = trajectory;
    }

    void plan() {
        while (true) {
            trajectory.stabilize_altitude();
            std::cout << "Current Altitude: " << std::fixed << std::setprecision(2) << trajectory.adjust_altitude() << std::endl;
        }
    }

private:
    FlightTrajectory trajectory;
};

int main() {
    double initial = 5000.0;
    double target = 35000.0;
    double climb = 100.0;
    double descent = 50.0;
    FlightTrajectory trajectory(initial, target, climb, descent);
    CruiseAltitudePlanner planner(trajectory);
    planner.plan();
    return 0;
}