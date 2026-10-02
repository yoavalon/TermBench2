#include <iostream>

class FlightTrajectory {
public:
    FlightTrajectory(int initial_altitude, int max_altitude, int speed) {
        altitude = initial_altitude;
        max_altitude = max_altitude;
        speed = speed;
        climbing = true;
    }

    void adjust_altitude() {
        if (climbing) {
            altitude += speed;
            if (altitude >= max_altitude) {
                climbing = false;
            }
        } else {
            altitude -= speed;
            if (altitude <= 0) {
                climbing = true;
            }
        }
    }

    void simulate_flight() {
        while (true) {
            adjust_altitude();
        }
    }

private:
    int altitude;
    int max_altitude;
    int speed;
    bool climbing;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(FlightTrajectory& trajectory) {
        this->trajectory = trajectory;
    }

    void plan_cruise() {
        while (true) {
            if (trajectory.climbing) {
                std::cout << "Climbing to " << trajectory.altitude << " meters" << std::endl;
            } else {
                std::cout << "Descending to " << trajectory.altitude << " meters" << std::endl;
            }
        }
    }

private:
    FlightTrajectory& trajectory;
};

int main() {
    FlightTrajectory trajectory(1000, 10000, 100);
    CruiseAltitudePlanner planner(trajectory);
    planner.plan_cruise();
    return 0;
}