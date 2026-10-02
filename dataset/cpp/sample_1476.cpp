#include <iostream>
#include <vector>

class FlightPlanner {
public:
    int current_altitude;
    int target_altitude;
    int rate_of_climb;
    int max_altitude;

    FlightPlanner(int initial_altitude, int target_altitude, int rate_of_climb, int max_altitude) {
        this->current_altitude = initial_altitude;
        this->target_altitude = target_altitude;
        this->rate_of_climb = rate_of_climb;
        this->max_altitude = max_altitude;
    }

    void climb() {
        if (this->current_altitude < this->target_altitude) {
            this->current_altitude += this->rate_of_climb;
            if (this->current_altitude > this->max_altitude) {
                this->current_altitude = this->max_altitude;
            }
        }
    }

    bool stabilize() {
        if (this->current_altitude == this->target_altitude) {
            return true;
        }
        return false;
    }

    int plan_flight() {
        while (!this->stabilize()) {
            this->climb();
        }
        return this->current_altitude;
    }
};

class FlightData {
public:
    std::vector<int> altitudes;

    FlightData(std::vector<int> altitudes) {
        this->altitudes = altitudes;
    }

    void update_altitude(int new_altitude) {
        this->altitudes.push_back(new_altitude);
    }

    std::vector<int> get_altitudes() {
        return this->altitudes;
    }
};

class FlightController {
public:
    FlightPlanner* planner;
    FlightData* data;

    FlightController(FlightPlanner* planner, FlightData* data) {
        this->planner = planner;
        this->data = data;
    }

    std::vector<int> execute_flight() {
        int final_altitude = this->planner->plan_flight();
        this->data->update_altitude(final_altitude);
        return this->data->get_altitudes();
    }
};

void main() {
    int initial_altitude = 5000;
    int target_altitude = 35000;
    int rate_of_climb = 1000;
    int max_altitude = 40000;
    FlightPlanner* planner = new FlightPlanner(initial_altitude, target_altitude, rate_of_climb, max_altitude);
    FlightData* data = new FlightData({initial_altitude});
    FlightController* controller = new FlightController(planner, data);
    std::vector<int> altitudes = controller->execute_flight();
    for (int altitude : altitudes) {
        std::cout << altitude << " ";
    }
    std::cout << std::endl;
}