#include <iostream>

class FlightPlanner {
public:
    FlightPlanner(int initial_altitude, int target_altitude, int altitude_step, int descent_rate) {
        this->current_altitude = initial_altitude;
        this->target_altitude = target_altitude;
        this->altitude_step = altitude_step;
        this->descent_rate = descent_rate;
    }

    void adjust_altitude() {
        if (current_altitude > target_altitude) {
            current_altitude -= altitude_step;
            if (current_altitude < target_altitude) {
                current_altitude = target_altitude;
            }
        } else {
            current_altitude += altitude_step;
            if (current_altitude > target_altitude) {
                current_altitude = target_altitude;
            }
        }
    }

    int simulate_flight() {
        while (current_altitude != target_altitude) {
            adjust_altitude();
        }
        return current_altitude;
    }

private:
    int current_altitude;
    int target_altitude;
    int altitude_step;
    int descent_rate;
};

class TrajectoryAnalyzer {
public:
    TrajectoryAnalyzer(int initial_position, int target_position, int position_step, int direction) {
        this->current_position = initial_position;
        this->target_position = target_position;
        this->position_step = position_step;
        this->direction = direction;
    }

    void update_position() {
        if (current_position < target_position) {
            current_position += position_step;
        } else if (current_position > target_position) {
            current_position -= position_step;
        }
    }

    int analyze_trajectory() {
        while (current_position != target_position) {
            update_position();
        }
        return current_position;
    }

private:
    int current_position;
    int target_position;
    int position_step;
    int direction;
};

void main() {
    FlightPlanner altitude_planner(30000, 35000, 1000, 500);
    TrajectoryAnalyzer trajectory_analyzer(0, 1000, 100, 1);
    int final_altitude = altitude_planner.simulate_flight();
    int final_position = trajectory_analyzer.analyze_trajectory();
    std::cout << "Final Altitude: " << final_altitude << std::endl;
    std::cout << "Final Position: " << final_position << std::endl;
}