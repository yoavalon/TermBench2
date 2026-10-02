#include <iostream>
#include <vector>

class FlightPlanner {
public:
    FlightPlanner(int initial_altitude, int target_altitude, int rate_of_climb) {
        this->current_altitude = initial_altitude;
        this->target_altitude = target_altitude;
        this->rate_of_climb = rate_of_climb;
    }

    std::vector<int> calculate_climb_sequence() {
        std::vector<int> sequence;
        while (this->current_altitude < this->target_altitude) {
            int next_altitude = this->current_altitude + this->rate_of_climb;
            sequence.push_back(next_altitude);
            this->current_altitude = next_altitude;
        }
        return sequence;
    }

    std::vector<int> plan_trajectory() {
        std::vector<int> sequence = this->calculate_climb_sequence();
        std::vector<int> trajectory(sequence.size());
        for (size_t i = 0; i < sequence.size(); ++i) {
            trajectory[i] = sequence[i];
        }
        return trajectory;
    }

private:
    int current_altitude;
    int target_altitude;
    int rate_of_climb;
};

class CruiseAltitudeManager {
public:
    CruiseAltitudeManager(int cruise_altitude, int duration) {
        this->cruise_altitude = cruise_altitude;
        this->duration = duration;
    }

    std::vector<int> generate_cruise_sequence() {
        std::vector<int> sequence(this->duration, this->cruise_altitude);
        return sequence;
    }

private:
    int cruise_altitude;
    int duration;
};

int main() {
    int initial_altitude = 1000;
    int target_altitude = 35000;
    int rate_of_climb = 1000;
    int cruise_altitude = 35000;
    int duration = 100;

    FlightPlanner flight_planner(initial_altitude, target_altitude, rate_of_climb);
    std::vector<int> climb_sequence = flight_planner.plan_trajectory();

    CruiseAltitudeManager cruise_manager(cruise_altitude, duration);
    std::vector<int> cruise_sequence = cruise_manager.generate_cruise_sequence();

    std::vector<int> full_sequence = climb_sequence;
    full_sequence.insert(full_sequence.end(), cruise_sequence.begin(), cruise_sequence.end());

    for (int altitude : full_sequence) {
        std::cout << altitude << std::endl;
    }

    return 0;
}