#include <iostream>
#include <cmath>

class TrajectoryPlanner {
public:
    TrajectoryPlanner(double initial_altitude, double speed, double wind_speed, double wind_direction)
        : altitude(initial_altitude), speed(speed), wind_speed(wind_speed), wind_direction(wind_direction) {}

    double calculate_distance(double time) {
        double distance = speed * time;
        double wind_effect = wind_speed * cos((wind_direction - 90) * M_PI / 180);
        return distance + wind_effect;
    }

    void update_altitude(double time, double rate_of_climb) {
        double climb_distance = rate_of_climb * time;
        altitude += climb_distance;
    }

private:
    double altitude;
    double speed;
    double wind_speed;
    double wind_direction;
};

class CruiseManager {
public:
    CruiseManager(double target_altitude, double max_altitude)
        : target_altitude(target_altitude), max_altitude(max_altitude) {}

    bool should_adjust_altitude(double current_altitude) {
        return current_altitude < target_altitude;
    }

    double calculate_rate_of_climb(double current_altitude) {
        return (target_altitude - current_altitude) / 10;
    }

private:
    double target_altitude;
    double max_altitude;
};

int main() {
    double initial_altitude = 1000;
    double speed = 250;
    double wind_speed = 20;
    double wind_direction = 45;
    TrajectoryPlanner trajectory(initial_altitude, speed, wind_speed, wind_direction);
    CruiseManager cruise_manager(15000, 20000);
    double time_step = 60;
    while (true) {
        double distance = trajectory.calculate_distance(time_step);
        if (cruise_manager.should_adjust_altitude(trajectory.altitude)) {
            double rate_of_climb = cruise_manager.calculate_rate_of_climb(trajectory.altitude);
            trajectory.update_altitude(time_step, rate_of_climb);
        }
        std::cout << "Distance: " << distance << "m, Altitude: " << trajectory.altitude << "m\n";
    }
    return 0;
}