#include <iostream>

class FlightTrajectory {
public:
    FlightTrajectory(int start_altitude, int target_altitude, int rate_of_climb) {
        this->current_altitude = start_altitude;
        this->target_altitude = target_altitude;
        this->rate_of_climb = rate_of_climb;
        this->cruise_altitude = 0;
    }

    void update_altitude() {
        if (this->current_altitude < this->target_altitude) {
            this->current_altitude += this->rate_of_climb;
            if (this->current_altitude >= this->target_altitude) {
                this->current_altitude = this->target_altitude;
                this->set_cruise_altitude();
            }
        }
    }

    void set_cruise_altitude() {
        this->cruise_altitude = this->current_altitude;
    }

    int get_current_altitude() {
        return this->current_altitude;
    }

    bool is_at_target() {
        return this->current_altitude == this->target_altitude;
    }

private:
    int current_altitude;
    int target_altitude;
    int rate_of_climb;
    int cruise_altitude;
};

class AltitudePlanner {
public:
    AltitudePlanner(FlightTrajectory trajectory, int target_altitude) {
        this->trajectory = trajectory;
        this->target_altitude = target_altitude;
    }

    int plan_cruise_altitude() {
        while (!this->trajectory.is_at_target()) {
            this->trajectory.update_altitude();
        }
        return this->trajectory.get_current_altitude();
    }

private:
    FlightTrajectory trajectory;
    int target_altitude;
};

int main() {
    int start_altitude = 1000;
    int target_altitude = 35000;
    int rate_of_climb = 500;
    FlightTrajectory trajectory(start_altitude, target_altitude, rate_of_climb);
    AltitudePlanner planner(trajectory, target_altitude);
    int cruise_altitude = planner.plan_cruise_altitude();
    std::cout << "Cruise Altitude Set: " << cruise_altitude << " feet" << std::endl;
    return 0;
}