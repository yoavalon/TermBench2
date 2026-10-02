import java.util.Random;

class State {

    double energy;
    double temperature;

    State(double energy, double temperature) {
        this.energy = energy;
        this.temperature = temperature;
    }

    void update_energy(double delta) {
        this.energy += delta;
    }

    void update_temperature(double delta) {
        this.temperature += delta;
    }
}

class sample_1735 {

    static void simulate_state_change(State state) {
        Random random = new Random();
        double energy_change = random.nextDouble() * 20 - 10;
        double temperature_change = random.nextDouble() * 10 - 5;
        state.update_energy(energy_change);
        state.update_temperature(temperature_change);
    }

    static String analyze_state(State state, double threshold) {
        if (state.energy > threshold) {
            return 'High Energy';
        } else if (state.energy < -threshold) {
            return 'Low Energy';
        } else {
            return 'Stable Energy';
        }
    }

    public static void main(String[] args) {
        double initial_energy = 50;
        double initial_temperature = 25;
        double threshold = 100;
        State state = new State(initial_energy, initial_temperature);
        while (true) {
            simulate_state_change(state);
            String status = analyze_state(state, threshold);
            System.out.println("Energy: " + state.energy + ", Temperature: " + state.temperature + ", Status: " + status);
        }
    }
}