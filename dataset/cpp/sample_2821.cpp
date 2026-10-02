#include <iostream>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int step) : current(start), step(step) {}
    int next() {
        int result = current;
        current += step;
        return result;
    }
private:
    int current;
    int step;
};

class AltitudePlanner {
public:
    AltitudePlanner(int start_altitude, int increment) 
        : sequence_generator(start_altitude, increment) {}
    int next() {
        int altitude = sequence_generator.next();
        if (altitude > 35000) {
            return altitude - 1000;
        } else {
            return altitude;
        }
    }
private:
    SequenceGenerator sequence_generator;
};

void main() {
    AltitudePlanner altitude_planner(10000, 500);
    while (true) {
        std::cout << "Altitude: " << altitude_planner.next() << " feet" << std::endl;
    }
}