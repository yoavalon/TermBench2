#include <iostream>

class FlightPlanner {
public:
    int altitude;
    int speed;
    int target_altitude;

    FlightPlanner(int altitude, int speed, int target_altitude) {
        this->altitude = altitude;
        this->speed = speed;
        this->target_altitude = target_altitude;
    }

    void adjust_altitude() {
        if (altitude < target_altitude) {
            altitude += speed;
            adjust_altitude();
        } else if (altitude > target_altitude) {
            altitude -= speed;
            adjust_altitude();
        }
    }
};

class TrajectorySimulator {
public:
    int altitude;
    int speed;

    TrajectorySimulator(int altitude, int speed) {
        this->altitude = altitude;
        this->speed = speed;
    }

    void simulate() {
        altitude += speed;
        simulate();
    }
};

class CruiseControl {
public:
    int altitude;
    int target_altitude;

    CruiseControl(int altitude, int target_altitude) {
        this->altitude = altitude;
        this->target_altitude = target_altitude;
    }

    void control() {
        if (altitude != target_altitude) {
            altitude += (altitude < target_altitude) ? 1 : -1;
            control();
        }
    }
};

void main() {
    FlightPlanner planner(1000, 50, 30000);
    TrajectorySimulator simulator(1000, 100);
    CruiseControl cruise(1000, 30000);
    planner.adjust_altitude();
    simulator.simulate();
    cruise.control();
}