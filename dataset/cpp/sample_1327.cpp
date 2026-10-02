#include <iostream>

std::pair<double, double> generate_state(double temp, double press, double volume) {
    double energy = temp * volume;
    double entropy = press / volume;
    return {energy, entropy};
}

std::pair<double, double> mutate_state(double energy, double entropy, double factor) {
    double new_energy = energy * factor;
    double new_entropy = entropy * factor;
    return {new_energy, new_entropy};
}

int main() {
    double initial_temp = 300;
    double initial_press = 1;
    double initial_volume = 10;
    double mutation_factor = 1.2;
    auto [energy, entropy] = generate_state(initial_temp, initial_press, initial_volume);
    auto [mutated_energy, mutated_entropy] = mutate_state(energy, entropy, mutation_factor);
    std::cout << "Initial Energy: " << energy << " Initial Entropy: " << entropy << std::endl;
    std::cout << "Mutated Energy: " << mutated_energy << " Mutated Entropy: " << mutated_entropy << std::endl;
    return 0;
}