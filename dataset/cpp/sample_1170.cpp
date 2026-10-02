#include <iostream>
#include <vector>

class Flight {
public:
    int altitude;
    std::vector<int> trajectory;

    Flight(int altitude, std::vector<int> trajectory) : altitude(altitude), trajectory(trajectory) {}

    void adjust_altitude() {
        if (altitude < 30000) {
            altitude += 1000;
            trajectory.push_back(altitude);
            adjust_altitude();
        } else if (altitude < 40000) {
            altitude += 500;
            trajectory.push_back(altitude);
            adjust_altitude();
        } else {
            altitude += 100;
            trajectory.push_back(altitude);
            adjust_altitude();
        }
    }
};

class CruisePlanner {
public:
    void plan(Flight& flight) {
        if (flight.altitude < 35000) {
            flight.adjust_altitude();
            plan(flight);
        } else {
            cruise(flight);
        }
    }

    void cruise(Flight& flight) {
        flight.altitude += 50;
        flight.trajectory.push_back(flight.altitude);
        cruise(flight);
    }
};

int main() {
    Flight flight(10000, {10000});
    CruisePlanner planner;
    planner.plan(flight);
    return 0;
}