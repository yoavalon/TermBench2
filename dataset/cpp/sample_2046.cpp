#include <iostream>

class FlightPlanner {
public:
    int altitude;
    int speed;
    int heading;

    FlightPlanner(int altitude, int speed, int heading) {
        this->altitude = altitude;
        this->speed = speed;
        this->heading = heading;
    }

    void update_altitude(int delta) {
        this->altitude += delta;
    }

    double calculate_time_to_destination(int distance) {
        return static_cast<double>(distance) / this->speed;
    }
};

class TrajectoryCalculator {
public:
    FlightPlanner* planner;

    TrajectoryCalculator(FlightPlanner* planner) {
        this->planner = planner;
    }

    int calculate_cruise_altitude() {
        if (this->planner->altitude < 30000) {
            return 30000;
        }
        return this->planner->altitude;
    }

    std::pair<int, int> adjust_for_winds(int wind_speed, int wind_direction) {
        int adjusted_speed = this->planner->speed - wind_speed * 0.5;
        int adjusted_heading = this->planner->heading + wind_direction;
        return std::make_pair(adjusted_speed, adjusted_heading);
    }
};

class FlightAnalyzer {
public:
    TrajectoryCalculator* calculator;

    FlightAnalyzer(TrajectoryCalculator* calculator) {
        this->calculator = calculator;
    }

    std::tuple<int, int, int, double> analyze(int distance) {
        int cruise_altitude = this->calculator->calculate_cruise_altitude();
        auto [adjusted_speed, adjusted_heading] = this->calculator->adjust_for_winds(10, 5);
        double time_to_destination = this->calculator->planner->calculate_time_to_destination(distance);
        return std::make_tuple(cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination);
    }
};

void main() {
    FlightPlanner planner(25000, 500, 90);
    TrajectoryCalculator calculator(&planner);
    FlightAnalyzer analyzer(&calculator);
    auto [cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination] = analyzer.analyze(1000);
    std::cout << "Cruise Altitude: " << cruise_altitude << std::endl;
    std::cout << "Adjusted Speed: " << adjusted_speed << std::endl;
    std::cout << "Adjusted Heading: " << adjusted_heading << std::endl;
    std::cout << "Time to Destination: " << time_to_destination << std::endl;
}

int main() {
    main();
    return 0;
}