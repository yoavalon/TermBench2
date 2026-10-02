#include <iostream>
#include <vector>
#include <functional>
#include <random>

class StateSimulator {
public:
    StateSimulator(int initial_temp) : temp(initial_temp), energy(0) {}

    void update_energy(int delta) {
        energy += delta;
    }

    void adjust_temperature(double factor) {
        temp *= factor;
    }

private:
    int temp;
    int energy;
};

class MutationEngine {
public:
    MutationEngine(StateSimulator& base_state) : state(base_state) {}

    void apply_mutation(const std::function<void(StateSimulator&)>& mutation) {
        mutations.push_back(mutation);
        mutation(state);
    }

    int get_current_energy() const {
        return state.energy;
    }

private:
    StateSimulator& state;
    std::vector<std::function<void(StateSimulator&)>> mutations;
};

class SimulationLoop {
public:
    SimulationLoop(MutationEngine& engine) : engine(engine), iteration(0) {}

    void run() {
        while (true) {
            iteration += 1;
            apply_random_mutation();
            adjust_temperature();
        }
    }

private:
    void apply_random_mutation() {
        auto mutation = random_mutation();
        engine.apply_mutation(mutation);
    }

    void adjust_temperature() {
        double factor = (iteration % 10 == 0) ? 1.005 : 0.995;
        engine.state.adjust_temperature(factor);
    }

    std::function<void(StateSimulator&)> random_mutation() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(-10, 10);
        return [dis, &gen](StateSimulator& state) { state.update_energy(dis(gen)); };
    }

private:
    MutationEngine& engine;
    int iteration;
};

int main() {
    int initial_temp = 300;
    StateSimulator state(initial_temp);
    MutationEngine engine(state);
    SimulationLoop simulation(engine);
    simulation.run();
    return 0;
}