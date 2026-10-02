#include <cmath>

class FlightData {
public:
    FlightData(double speed, double altitude, double distance) : a(speed), b(altitude), c(distance) {}

    void update_speed(double new_speed) { a = new_speed; }
    void update_altitude(double new_altitude) { b = new_altitude; }
    void update_distance(double new_distance) { c = new_distance; }

private:
    double a;
    double b;
    double c;
};

class TrajectoryPlanner {
public:
    TrajectoryPlanner(FlightData& flight_data) : data(flight_data) {}

    double calculate_time() { return data.c / data.a; }
    double adjust_altitude(double time) { return data.b + std::sin(time) * 1000; }

private:
    FlightData& data;
};

class CruiseController {
public:
    CruiseController(TrajectoryPlanner& planner) : planner(planner) {}

    void execute() {
        while (true) {
            double time = planner.calculate_time();
            double new_altitude = planner.adjust_altitude(time);
            planner.data.update_altitude(new_altitude);
        }
    }

private:
    TrajectoryPlanner& planner;
};

int main() {
    double initial_speed = 800;
    double initial_altitude = 10000;
    double distance = 1000;
    FlightData flight_data(initial_speed, initial_altitude, distance);
    TrajectoryPlanner trajectory_planner(flight_data);
    CruiseController cruise_controller(trajectory_planner);
    cruise_controller.execute();
    return 0;
}