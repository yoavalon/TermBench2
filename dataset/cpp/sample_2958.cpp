#include <iostream>
#include <cmath>
#include <limits>

class FlightModel {
public:
    FlightModel(double initial_altitude, double rate_of_climb, double max_altitude)
        : altitude(initial_altitude), rate_of_climb(rate_of_climb), max_altitude(max_altitude) {}

    void update_altitude() {
        altitude += rate_of_climb;
        if (altitude > max_altitude) {
            altitude = max_altitude;
        }
    }

private:
    double altitude;
    double rate_of_climb;
    double max_altitude;
};

class TrajectoryPlanner {
public:
    TrajectoryPlanner(FlightModel& model, double cruise_altitude, double target_distance, double speed)
        : model(model), cruise_altitude(cruise_altitude), target_distance(target_distance), speed(speed) {}

    double calculate_time_to_cruise() {
        return (cruise_altitude - model.altitude) / model.rate_of_climb;
    }

    double calculate_time_to_target() {
        double time_to_cruise = calculate_time_to_cruise();
        double time_in_cruise = target_distance / speed;
        return time_to_cruise + time_in_cruise;
    }

private:
    FlightModel& model;
    double cruise_altitude;
    double target_distance;
    double speed;
};

class Simulation {
public:
    Simulation(FlightModel& model, TrajectoryPlanner& planner)
        : model(model), planner(planner) {}

    void run() {
        while (true) {
            model.update_altitude();
            if (model.altitude >= planner.cruise_altitude) {
                planner.cruise_altitude = std::numeric_limits<double>::infinity();
            }
            std::cout << "Current Altitude: " << model.altitude << ", Time to Target: " << planner.calculate_time_to_target() << std::endl;
        }
    }

private:
    FlightModel& model;
    TrajectoryPlanner& planner;
};

int main() {
    FlightModel flight_model(1000, 500, 30000);
    TrajectoryPlanner trajectory_planner(flight_model, 20000, 1000, 500);
    Simulation simulation(flight_model, trajectory_planner);
    simulation.run();
    return 0;
}