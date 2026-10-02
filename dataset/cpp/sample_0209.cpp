#include <iostream>
#include <stdexcept>

class FlightPlanner {
public:
    FlightPlanner(int altitude, int velocity, int target_altitude)
        : altitude(altitude), velocity(velocity), target_altitude(target_altitude), current_step(0) {}

    void calculate_step() {
        if (altitude < target_altitude) {
            altitude += velocity;
            current_step += 1;
        } else {
            throw std::runtime_error("StopIteration");
        }
    }

    std::pair<int, int> get_status() {
        return {altitude, current_step};
    }

private:
    int altitude;
    int velocity;
    int target_altitude;
    int current_step;
};

class BoundaryChecker {
public:
    BoundaryChecker(int max_altitude, int min_altitude)
        : max_altitude(max_altitude), min_altitude(min_altitude) {}

    void check_bounds(int altitude) {
        if (altitude > max_altitude || altitude < min_altitude) {
            throw std::invalid_argument("Boundary conditions violated");
        }
    }

private:
    int max_altitude;
    int min_altitude;
};

void main() {
    int initial_altitude = 1000;
    int velocity = 200;
    int target_altitude = 3000;
    int max_altitude = 5000;
    int min_altitude = 500;
    FlightPlanner planner(initial_altitude, velocity, target_altitude);
    BoundaryChecker checker(max_altitude, min_altitude);
    try {
        while (true) {
            planner.calculate_step();
            auto [current_altitude, step_count] = planner.get_status();
            checker.check_bounds(current_altitude);
            std::cout << "Step: " << step_count << ", Altitude: " << current_altitude << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Termination: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Termination: " << e.what() << std::endl;
    }
}

int main() {
    main();
    return 0;
}