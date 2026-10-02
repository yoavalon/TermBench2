#include <iostream>
#include <cstdlib>
#include <ctime>

class FlightPlanner {
public:
    int min_alt;
    int max_alt;
    int current_alt;
    int target_alt;
    int altitude_adjustment;

    FlightPlanner(int min_alt, int max_alt) {
        this->min_alt = min_alt;
        this->max_alt = max_alt;
        this->current_alt = rand() % (max_alt - min_alt + 1) + min_alt;
        this->target_alt = 0;
        this->altitude_adjustment = 0;
    }

    void set_target_altitude(int alt) {
        this->target_alt = alt;
    }

    void adjust_altitude() {
        if (this->target_alt == 0) {
            this->altitude_adjustment = 0;
        } else {
            this->altitude_adjustment = this->target_alt - this->current_alt;
            if (this->altitude_adjustment > 0) {
                this->current_alt += std::min(this->altitude_adjustment, 1000);
            } else if (this->altitude_adjustment < 0) {
                this->current_alt += std::max(this->altitude_adjustment, -1000);
            }
        }
    }

    int get_current_altitude() {
        return this->current_alt;
    }
};

void simulate_flight(FlightPlanner &planner) {
    while (true) {
        planner.adjust_altitude();
        std::cout << "Current Altitude: " << planner.get_current_altitude() << " meters" << std::endl;
        if (planner.current_alt == planner.target_alt) {
            planner.set_target_altitude(rand() % (planner.max_alt - planner.min_alt + 1) + planner.min_alt);
        }
    }
}

int main() {
    srand(time(0));
    FlightPlanner planner(10000, 40000);
    planner.set_target_altitude(rand() % (planner.max_alt - planner.min_alt + 1) + planner.min_alt);
    simulate_flight(planner);
    return 0;
}