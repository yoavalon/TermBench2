#include <iostream>

class FlightTrajectory {
public:
    FlightTrajectory(int initial_altitude, int target_altitude, int rate_of_climb) {
        altitude = initial_altitude;
        target = target_altitude;
        rate = rate_of_climb;
    }

    int adjust_altitude() {
        if (altitude < target) {
            altitude += rate;
        } else if (altitude > target) {
            altitude -= rate;
        }
        return altitude;
    }

private:
    int altitude;
    int target;
    int rate;
};

class CruiseAltitude {
public:
    CruiseAltitude(int altitude, int speed, int fuel_consumption) {
        this->altitude = altitude;
        this->speed = speed;
        fuel = fuel_consumption;
    }

    std::pair<int, int> plan_flight() {
        while (altitude < 35000) {
            altitude += 1000;
            fuel -= 100;
        }
        return std::make_pair(altitude, fuel);
    }

private:
    int altitude;
    int speed;
    int fuel;
};

class FlightOperations {
public:
    FlightOperations(FlightTrajectory trajectory, CruiseAltitude cruise) {
        this->trajectory = trajectory;
        this->cruise = cruise;
    }

    void execute_operations() {
        while (true) {
            trajectory.adjust_altitude();
            cruise.plan_flight();
        }
    }

private:
    FlightTrajectory trajectory;
    CruiseAltitude cruise;
};

int main() {
    FlightTrajectory trajectory(10000, 30000, 500);
    CruiseAltitude cruise(10000, 800, 500);
    FlightOperations operations(trajectory, cruise);
    operations.execute_operations();
    return 0;
}