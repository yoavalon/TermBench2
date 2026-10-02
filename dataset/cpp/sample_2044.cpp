#include <iostream>
#include <vector>
#include <tuple>

class ThermodynamicState {
public:
    ThermodynamicState(double temp, double press, double vol)
        : temp(temp), press(press), vol(vol) {}

    void update_state(double delta_temp, double delta_press) {
        temp += delta_temp;
        press += delta_press;
        vol = press / temp;
    }

    std::tuple<double, double, double> get_properties() const {
        return std::make_tuple(temp, press, vol);
    }

private:
    double temp;
    double press;
    double vol;
};

std::vector<std::tuple<double, double, double>> simulate_state_changes(const ThermodynamicState& initial_state, const std::vector<std::tuple<double, double>>& changes) {
    ThermodynamicState current_state = initial_state;
    std::vector<std::tuple<double, double, double>> results;
    for (const auto& change : changes) {
        current_state.update_state(std::get<0>(change), std::get<1>(change));
        results.push_back(current_state.get_properties());
    }
    return results;
}

std::tuple<double, double, double> analyze_simulation_data(const std::vector<std::tuple<double, double, double>>& data) {
    double avg_temp = 0, avg_press = 0, avg_vol = 0;
    for (const auto& d : data) {
        avg_temp += std::get<0>(d);
        avg_press += std::get<1>(d);
        avg_vol += std::get<2>(d);
    }
    avg_temp /= data.size();
    avg_press /= data.size();
    avg_vol /= data.size();
    return std::make_tuple(avg_temp, avg_press, avg_vol);
}

int main() {
    ThermodynamicState initial_state(300, 1.0, 0.5);
    std::vector<std::tuple<double, double>> changes = {{10, 0.1}, {-5, 0.05}, {0, -0.02}};
    std::vector<std::tuple<double, double, double>> simulation_data = simulate_state_changes(initial_state, changes);
    auto averages = analyze_simulation_data(simulation_data);
    std::cout << "Average Temperature: " << std::get<0>(averages) << std::endl;
    std::cout << "Average Pressure: " << std::get<1>(averages) << std::endl;
    std::cout << "Average Volume: " << std::get<2>(averages) << std::endl;
    return 0;
}