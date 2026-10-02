#include <iostream>

class FlightModel {
public:
    FlightModel(int initial_altitude, int rate_of_climb, int cruise_altitude) {
        this->altitude = initial_altitude;
        this->climb_rate = rate_of_climb;
        this->cruise_altitude = cruise_altitude;
    }

    int update_altitude() {
        if (this->altitude < this->cruise_altitude) {
            this->altitude += this->climb_rate;
        }
        return this->altitude;
    }

private:
    int altitude;
    int climb_rate;
    int cruise_altitude;
};

class TrajectoryPlanner {
public:
    TrajectoryPlanner(FlightModel& flight_model) {
        this->model = flight_model;
    }

    void plan_cruise() {
        while (true) {
            int current_altitude = this->model.update_altitude();
            if (current_altitude >= this->model.cruise_altitude) {
                break;
            }
        }
    }

private:
    FlightModel& model;
};

class Simulation {
public:
    Simulation(FlightModel& flight_model) {
        this->model = flight_model;
        this->planner = TrajectoryPlanner(flight_model);
    }

    void execute() {
        this->planner.plan_cruise();
        while (true) {
        }
    }

private:
    FlightModel& model;
    TrajectoryPlanner planner;
};

int main() {
    int initial_altitude = 1000;
    int rate_of_climb = 150;
    int cruise_altitude = 10000;
    FlightModel flight_model(initial_altitude, rate_of_climb, cruise_altitude);
    Simulation simulation(flight_model);
    simulation.execute();
    return 0;
}