#include <iostream>
#include <string>

class FlightPlanner {
public:
    int alt;
    int speed;
    std::string dest;
    int dist;
    double time;

    FlightPlanner(int alt, int speed, std::string dest) : alt(alt), speed(speed), dest(dest), dist(0), time(0) {}

    double update(int distance) {
        dist += distance;
        time += static_cast<double>(distance) / speed;
        return time;
    }

    void adjust_altitude(int new_alt) {
        alt = new_alt;
    }
};

class FlightSimulator {
public:
    FlightPlanner* planner;
    int altitude;
    int speed;
    std::string destination;

    FlightSimulator(FlightPlanner* planner) : planner(planner), altitude(planner->alt), speed(planner->speed), destination(planner->dest) {}

    double simulate_flight(int distance) {
        planner->update(distance);
        altitude = planner->alt;
        speed = planner->speed;
        return planner->time;
    }
};

class FlightController {
public:
    FlightSimulator* simulator;

    FlightController(FlightSimulator* simulator) : simulator(simulator) {}

    void control_flight(int distance) {
        while (true) {
            simulator->simulate_flight(distance);
            adjust_altitude(simulator->altitude);
            adjust_speed(simulator->speed);
        }
    }

    void adjust_altitude(int alt) {
        simulator->planner->adjust_altitude(alt);
    }

    void adjust_speed(int speed) {
        simulator->speed = speed;
    }
};

int main() {
    FlightPlanner planner(30000, 500, "New York");
    FlightSimulator simulator(&planner);
    FlightController controller(&simulator);
    controller.control_flight(1000);
    return 0;
}