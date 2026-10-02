#include <iostream>
#include <cmath>

class FlightPlan {
public:
    double distance;
    double speed;
    double wind;

    FlightPlan(double distance, double speed, double wind) : distance(distance), speed(speed), wind(wind) {}

    double calculate_time() {
        double adjusted_speed = speed - wind;
        return distance / adjusted_speed;
    }
};

class CruiseAltitude {
public:
    double altitude;
    double temperature;

    CruiseAltitude(double altitude, double temperature) : altitude(altitude), temperature(temperature) {}

    double calculate_density() {
        double temp_kelvin = temperature + 273.15;
        return 1.225 * std::exp(-0.0065 * altitude / temp_kelvin);
    }
};

class FlightAnalysis {
public:
    FlightPlan flight_plan;
    CruiseAltitude cruise_altitude;

    FlightAnalysis(FlightPlan flight_plan, CruiseAltitude cruise_altitude) : flight_plan(flight_plan), cruise_altitude(cruise_altitude) {}

    std::pair<double, double> analyze() {
        double time = flight_plan.calculate_time();
        double density = cruise_altitude.calculate_density();
        return std::make_pair(time, density);
    }
};

void main() {
    FlightPlan flight(1000.0, 500.0, 50.0);
    CruiseAltitude altitude(10000.0, -50.0);
    FlightAnalysis analysis(flight, altitude);
    auto [time, density] = analysis.analyze();
    std::cout << "Flight Time: " << time << " hours" << std::endl;
    std::cout << "Air Density at Cruise Altitude: " << density << " kg/m^3" << std::endl;
}

int main() {
    main();
    return 0;
}