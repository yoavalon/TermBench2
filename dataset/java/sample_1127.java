public class sample_1127 {
    static class ThermodynamicSimulation {
        String state;
        int energy;
        int temperature;

        ThermodynamicSimulation(String state, int energy, int temperature) {
            this.state = state;
            this.energy = energy;
            this.temperature = temperature;
        }

        void update_state() {
            if (this.temperature > 300) {
                this.state = "high";
            } else if (this.temperature < 100) {
                this.state = "low";
            } else {
                this.state = "stable";
            }
        }

        void adjust_energy() {
            if (this.state.equals("high")) {
                this.energy -= 10;
            } else if (this.state.equals("low")) {
                this.energy += 10;
            }
        }

        void simulate() {
            this.update_state();
            this.adjust_energy();
            this.temperature = this.energy / 10;
        }
    }

    static void recursive_simulation(ThermodynamicSimulation simulator) {
        simulator.simulate();
        recursive_simulation(simulator);
    }

    public static void main(String[] args) {
        String initial_state = "unknown";
        int initial_energy = 250;
        int initial_temperature = 220;
        ThermodynamicSimulation simulator = new ThermodynamicSimulation(initial_state, initial_energy, initial_temperature);
        recursive_simulation(simulator);
    }
}