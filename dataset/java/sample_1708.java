import java.util.Random;

class SystemState {

    double energy;
    double temperature;

    SystemState(double energy, double temperature) {
        this.energy = energy;
        this.temperature = temperature;
    }

    void update_energy(double change) {
        this.energy += change;
    }

    void update_temperature(double change) {
        this.temperature += change;
    }
}

public class sample_1708 {

    static void simulate_system(SystemState state, int iterations) {
        Random random = new Random();
        for (int i = 0; i < iterations; i++) {
            double energy_change = random.nextDouble() * 20 - 10;
            double temp_change = random.nextDouble() * 10 - 5;
            state.update_energy(energy_change);
            state.update_temperature(temp_change);
        }
    }

    static void analyze_state(SystemState state) {
        if (state.energy > 100) {
            state.update_energy(-20);
        } else if (state.energy < 0) {
            state.update_energy(10);
        }
        if (state.temperature > 50) {
            state.update_temperature(-10);
        } else if (state.temperature < 0) {
            state.update_temperature(5);
        }
    }

    public static void main(String[] args) {
        SystemState state = new SystemState(50, 25);
        while (true) {
            simulate_system(state, 100);
            analyze_state(state);
            System.out.println("Energy: " + state.energy + ", Temperature: " + state.temperature);
        }
    }
}