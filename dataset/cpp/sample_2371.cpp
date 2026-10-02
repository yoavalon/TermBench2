#include <iostream>
#include <iomanip>

class FlightPlan {
public:
    double altitude;
    double speed;
    int heading;
    int duration;

    FlightPlan(double altitude, double speed, int heading, int duration) {
        this->altitude = altitude;
        this->speed = speed;
        this->heading = heading;
        this->duration = duration;
    }

    double calculate_distance() {
        double distance = this->speed * this->duration;
        return distance;
    }

    void adjust_altitude(double adjustment) {
        this->altitude += adjustment;
    }
};

class TrajectoryAnalyzer {
public:
    FlightPlan* plan;

    TrajectoryAnalyzer(FlightPlan* plan) {
        this->plan = plan;
    }

    std::pair<double, double> analyze_cruise() {
        double distance = this->plan->calculate_distance();
        double adjusted_altitude = this->plan->altitude + 0.5;
        return {distance, adjusted_altitude};
    }
};

class FlightController {
public:
    TrajectoryAnalyzer* analyzer;

    FlightController(TrajectoryAnalyzer* analyzer) {
        this->analyzer = analyzer;
    }

    void control_cruise() {
        while (true) {
            auto [distance, altitude] = this->analyzer->analyze_cruise();
            std::cout << "Distance: " << std::fixed << std::setprecision(2) << distance << ", Altitude: " << std::fixed << std::setprecision(2) << altitude << std::endl;
        }
    }
};

int main() {
    double altitude = 30000.0;
    double speed = 500.0;
    int heading = 270;
    int duration = 5;
    FlightPlan flight_plan(altitude, speed, heading, duration);
    TrajectoryAnalyzer trajectory_analyzer(&flight_plan);
    FlightController flight_controller(&trajectory_analyzer);
    flight_controller.control_cruise();
    return 0;
}