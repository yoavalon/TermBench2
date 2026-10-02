#include <iostream>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int step, int count) : start(start), step(step), count(count), current(start), index(0) {}

    int next() {
        if (index < count) {
            int value = current;
            current += step;
            index += 1;
            return value;
        } else {
            return -1; // Using -1 to represent None
        }
    }

private:
    int start;
    int step;
    int count;
    int current;
    int index;
};

class FlightTrajectory {
public:
    FlightTrajectory(int initial_altitude, int rate_of_climb, int cruise_altitude, int descent_rate, SequenceGenerator sequence) 
        : initial_altitude(initial_altitude), rate_of_climb(rate_of_climb), cruise_altitude(cruise_altitude), descent_rate(descent_rate), sequence(sequence), current_altitude(initial_altitude) {}

    void plan_cruise() {
        SequenceGenerator climb_sequence(initial_altitude, rate_of_climb, 100);
        while (true) {
            int next_altitude = climb_sequence.next();
            if (next_altitude == -1 || next_altitude >= cruise_altitude) {
                break;
            }
            current_altitude = next_altitude;
        }
        if (current_altitude < cruise_altitude) {
            current_altitude = cruise_altitude;
        }
        SequenceGenerator descent_sequence(current_altitude, -descent_rate, 100);
        while (true) {
            int next_altitude = descent_sequence.next();
            if (next_altitude == -1 || next_altitude <= 0) {
                break;
            }
            current_altitude = next_altitude;
        }
        if (current_altitude > 0) {
            current_altitude = 0;
        }
    }

private:
    int initial_altitude;
    int rate_of_climb;
    int cruise_altitude;
    int descent_rate;
    SequenceGenerator sequence;
    int current_altitude;
};

int main() {
    SequenceGenerator sequence(0, 100, 200);
    FlightTrajectory trajectory(1000, 500, 30000, 200, sequence);
    trajectory.plan_cruise();
    std::cout << "Final Altitude: " << trajectory.current_altitude << std::endl;
    return 0;
}