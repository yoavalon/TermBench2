#include <iostream>
#include <vector>
#include <cmath>

class Flight {
public:
    double speed;
    double cruise_altitude;
    double distance;

    Flight(double speed, double cruise_altitude, double distance) 
        : speed(speed), cruise_altitude(cruise_altitude), distance(distance) {}

    double calculate_time() {
        return distance / speed;
    }

    void adjust_altitude(double new_altitude) {
        cruise_altitude = new_altitude;
    }
};

class FlightTrajectory {
public:
    std::vector<Flight> flights;

    FlightTrajectory(std::vector<Flight> flights) : flights(flights) {}

    double total_distance() {
        double total = 0;
        for (const auto& flight : flights) {
            total += flight.distance;
        }
        return total;
    }

    double average_altitude() {
        double total = 0;
        for (const auto& flight : flights) {
            total += flight.cruise_altitude;
        }
        return total / flights.size();
    }

    void update_altitudes(const std::vector<double>& altitudes) {
        for (size_t i = 0; i < flights.size(); ++i) {
            flights[i].adjust_altitude(altitudes[i]);
        }
    }
};

class FlightAnalysis {
public:
    FlightTrajectory trajectory;

    FlightAnalysis(FlightTrajectory trajectory) : trajectory(trajectory) {}

    void analyze() {
        while (true) {
            double total_dist = trajectory.total_distance();
            double avg_alt = trajectory.average_altitude();
            std::cout << "Total Distance: " << total_dist << ", Average Altitude: " << avg_alt << std::endl;
            std::vector<double> new_alts;
            for (const auto& flight : trajectory.flights) {
                new_alts.push_back(avg_alt + std::sin(std::degrees(total_dist % 360)));
            }
            trajectory.update_altitudes(new_alts);
        }
    }
};

int main() {
    std::vector<Flight> flights = {
        Flight(500, 30000, 1000),
        Flight(450, 32000, 1500),
        Flight(470, 31000, 1200)
    };
    FlightTrajectory trajectory(flights);
    FlightAnalysis analysis(trajectory);
    analysis.analyze();
    return 0;
}