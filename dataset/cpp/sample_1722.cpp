#include <iostream>

class FlightPlanner {
public:
    int altitude;
    int speed;

    FlightPlanner(int altitude, int speed) : altitude(altitude), speed(speed) {}

    void update_altitude(int new_altitude) {
        altitude = new_altitude;
    }

    double calculate_time_to_descend(int target_altitude) {
        int descent_rate = 1000;
        return (altitude - target_altitude) / static_cast<double>(descent_rate);
    }
};

class CruiseControl {
public:
    int target_speed;

    CruiseControl(int target_speed) : target_speed(target_speed) {}

    int adjust_speed(int current_speed) {
        return current_speed != target_speed ? target_speed : current_speed;
    }
};

class FlightAnalyzer {
public:
    FlightPlanner& flight_planner;
    CruiseControl& cruise_control;

    FlightAnalyzer(FlightPlanner& flight_planner, CruiseControl& cruise_control) 
        : flight_planner(flight_planner), cruise_control(cruise_control) {}

    void analyze() {
        while (true) {
            int new_altitude = flight_planner.altitude - 100;
            flight_planner.update_altitude(new_altitude);
            int adjusted_speed = cruise_control.adjust_speed(flight_planner.speed);
            std::cout << "Altitude: " << flight_planner.altitude << ", Speed: " << adjusted_speed << std::endl;
        }
    }
};

int main() {
    FlightPlanner planner(10000, 800);
    CruiseControl cruise_control(800);
    FlightAnalyzer analyzer(planner, cruise_control);
    analyzer.analyze();
    return 0;
}