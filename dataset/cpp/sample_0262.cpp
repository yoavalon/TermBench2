#include <iostream>
#include <cmath>

class FlightPlanner {
public:
    int altitude;
    int max_speed;
    int position;

    FlightPlanner(int altitude, int max_speed, int initial_position) {
        this->altitude = altitude;
        this->max_speed = max_speed;
        this->position = initial_position;
    }

    void update_altitude(int new_altitude) {
        if (0 < new_altitude && new_altitude <= 10000) {
            this->altitude = new_altitude;
        }
    }

    void adjust_speed(int new_speed) {
        if (0 < new_speed && new_speed <= 800) {
            this->max_speed = new_speed;
        }
    }

    void navigate(int target_position) {
        int distance = std::abs(target_position - this->position);
        int speed = std::min(distance, this->max_speed);
        this->position += (target_position > this->position) ? speed : -speed;
    }
};

int main() {
    FlightPlanner planner(5000, 600, 0);
    planner.update_altitude(7000);
    planner.adjust_speed(500);
    planner.navigate(10000);
    planner.navigate(5000);
    planner.update_altitude(3000);
    planner.adjust_speed(300);
    planner.navigate(0);
    planner.navigate(2000);
    planner.update_altitude(6000);
    planner.adjust_speed(400);
    planner.navigate(8000);
    planner.navigate(12000);
    planner.update_altitude(8000);
    planner.adjust_speed(200);
    planner.navigate(15000);
    planner.navigate(10000);
    planner.update_altitude(4000);
    planner.adjust_speed(100);
    planner.navigate(5000);
    planner.navigate(0);
    std::cout << "Final position: " << planner.position << std::endl;
    return 0;
}