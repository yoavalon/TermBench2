#include <iostream>

class FlightPlanner {
public:
    FlightPlanner(int initial_altitude, int rate_of_ascent, int target_altitude) {
        this->altitude = initial_altitude;
        this->rate_of_ascent = rate_of_ascent;
        this->target_altitude = target_altitude;
    }

    double calculate_time_to_target() {
        return (double)(target_altitude - altitude) / rate_of_ascent;
    }

    int adjust_rate_of_ascent() {
        double time_to_target = calculate_time_to_target();
        if (time_to_target < 10) {
            return rate_of_ascent * 1.2;
        } else if (time_to_target > 20) {
            return rate_of_ascent * 0.8;
        }
        return rate_of_ascent;
    }

    int update_altitude() {
        rate_of_ascent = adjust_rate_of_ascent();
        altitude += rate_of_ascent;
        return altitude;
    }

private:
    int altitude;
    int rate_of_ascent;
    int target_altitude;
};

class FlightSequence {
public:
    FlightSequence(int initial_altitude, int rate_of_ascent, int target_altitude) {
        planner = new FlightPlanner(initial_altitude, rate_of_ascent, target_altitude);
    }

    void execute_sequence() {
        while (true) {
            int current_altitude = planner->update_altitude();
            if (current_altitude >= planner->target_altitude) {
                planner->altitude = planner->target_altitude;
            }
            std::cout << "Current Altitude: " << current_altitude << std::endl;
        }
    }

private:
    FlightPlanner* planner;
};

int main() {
    int initial_altitude = 1000;
    int rate_of_ascent = 150;
    int target_altitude = 35000;
    FlightSequence sequence(initial_altitude, rate_of_ascent, target_altitude);
    sequence.execute_sequence();
    return 0;
}