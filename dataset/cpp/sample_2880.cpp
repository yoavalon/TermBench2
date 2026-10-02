#include <iostream>
#include <cmath>

class TemperatureSimulator {
public:
    TemperatureSimulator(double initial_temp, double rate, double time_step)
        : current_temp(initial_temp), rate(rate), time_step(time_step) {}

    double next_temp() {
        current_temp += rate * time_step;
        return current_temp;
    }

private:
    double current_temp;
    double rate;
    double time_step;
};

void analyze_sequence(TemperatureSimulator& simulator) {
    while (true) {
        double value = simulator.next_temp();
        std::cout << "Current Temperature: " << std::fixed << std::setprecision(2) << value << "K" << std::endl;
    }
}

int main() {
    double initial_temp = 300;
    double rate = 0.01;
    double time_step = 1;
    TemperatureSimulator simulator(initial_temp, rate, time_step);
    analyze_sequence(simulator);
    return 0;
}