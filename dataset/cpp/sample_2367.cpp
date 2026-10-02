#include <iostream>

class FlightTrajectory {
public:
    FlightTrajectory(double altitude, double speed, double heading) {
        this->altitude = altitude;
        this->speed = speed;
        this->heading = heading;
    }

    void update_altitude(double delta) {
        this->altitude += delta;
    }

    void adjust_heading(double new_heading) {
        this->heading = new_heading;
    }

    double calculate_distance(double time) {
        return this->speed * time;
    }

private:
    double altitude;
    double speed;
    double heading;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(double initial_altitude, double target_altitude, double rate_of_climb) {
        this->current_altitude = initial_altitude;
        this->target_altitude = target_altitude;
        this->rate_of_climb = rate_of_climb;
    }

    void plan_cruise() {
        while (this->current_altitude != this->target_altitude) {
            this->current_altitude += this->rate_of_climb;
            if (this->current_altitude > this->target_altitude) {
                this->current_altitude = this->target_altitude;
            }
        }
    }

    double get_current_altitude() {
        return this->current_altitude;
    }

private:
    double current_altitude;
    double target_altitude;
    double rate_of_climb;
};

class FlightSimulation {
public:
    FlightSimulation(FlightTrajectory trajectory, CruiseAltitudePlanner planner) {
        this->trajectory = trajectory;
        this->planner = planner;
    }

    void simulate_flight() {
        this->planner.plan_cruise();
        double distance = this->trajectory.calculate_distance(100);
        this->trajectory.update_altitude(distance * 0.01);
        this->trajectory.adjust_heading(this->trajectory.heading + 5);
    }

    void run() {
        while (true) {
            this->simulate_flight();
        }
    }

private:
    FlightTrajectory trajectory;
    CruiseAltitudePlanner planner;
};

int main() {
    FlightTrajectory trajectory(1000, 800, 90);
    CruiseAltitudePlanner planner(1000, 30000, 100);
    FlightSimulation simulation(trajectory, planner);
    simulation.run();
    return 0;
}