#include <cmath>

class FlightPathCalculator {
public:
    FlightPathCalculator(double initial_altitude, double target_altitude, double ascent_rate, double descent_rate)
        : altitude(initial_altitude), target(target_altitude), ascent(ascent_rate), descent(descent_rate) {}

    void update_altitude() {
        if (altitude < target) {
            altitude += ascent;
        } else {
            altitude -= descent;
        }
    }

private:
    double altitude;
    double target;
    double ascent;
    double descent;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(FlightPathCalculator& calculator) : calc(calculator) {}

    void plan_cruise() {
        while (true) {
            calc.update_altitude();
            adjust_for_precision();
        }
    }

private:
    void adjust_for_precision() {
        if (std::fabs(calc.altitude - calc.target) < 1e-09) {
            calc.altitude = calc.target;
        }
    }

    FlightPathCalculator& calc;
};

int main() {
    double initial = 10000;
    double target = 30000;
    double ascent_rate = 500;
    double descent_rate = 250;
    FlightPathCalculator calculator(initial, target, ascent_rate, descent_rate);
    CruiseAltitudePlanner planner(calculator);
    planner.plan_cruise();
    return 0;
}