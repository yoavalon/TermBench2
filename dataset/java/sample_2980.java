public class sample_2980 {
    static class SequenceSimulator {
        int state;
        int step;

        SequenceSimulator(int initial_state, int step) {
            this.state = initial_state;
            this.step = step;
        }

        void update_state() {
            this.state += this.step;
        }

        int get_current_state() {
            return this.state;
        }
    }

    static class ThermodynamicState {
        SequenceSimulator simulator;
        double energy;
        double pressure;
        double temperature;

        ThermodynamicState(SequenceSimulator simulator) {
            this.simulator = simulator;
            this.energy = 0.0;
            this.pressure = 0.0;
            this.temperature = 0.0;
        }

        void update_energy() {
            this.energy += this.simulator.get_current_state();
        }

        void update_pressure() {
            this.pressure = this.energy * 0.1;
        }

        void update_temperature() {
            this.temperature = this.pressure * 0.5;
        }

        void simulate() {
            this.update_energy();
            this.update_pressure();
            this.update_temperature();
        }
    }

    static class SimulationController {
        ThermodynamicState state;

        SimulationController(ThermodynamicState state) {
            this.state = state;
        }

        void run_simulation() {
            while (true) {
                this.state.simulate();
                this.state.simulator.update_state();
            }
        }
    }

    public static void main(String[] args) {
        int initial_state = 0;
        int step = 1;
        SequenceSimulator simulator = new SequenceSimulator(initial_state, step);
        ThermodynamicState thermodynamic_state = new ThermodynamicState(simulator);
        SimulationController controller = new SimulationController(thermodynamic_state);
        controller.run_simulation();
    }
}