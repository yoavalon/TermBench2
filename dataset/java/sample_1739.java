public class sample_1739 {
    static class ThermodynamicSimulator {
        String state;
        double temperature;
        double pressure;

        ThermodynamicSimulator(String state, double temperature, double pressure) {
            this.state = state;
            this.temperature = temperature;
            this.pressure = pressure;
        }

        void update_state(String new_state) {
            this.state = new_state;
        }

        void adjust_temperature(double delta) {
            this.temperature += delta;
        }

        void adjust_pressure(double delta) {
            this.pressure += delta;
        }
    }

    static class StateTransformer {
        ThermodynamicSimulator simulator;

        StateTransformer(ThermodynamicSimulator simulator) {
            this.simulator = simulator;
        }

        void transform() {
            while (true) {
                if (simulator.temperature > 100) {
                    simulator.adjust_temperature(-10);
                    simulator.update_state("Condensing");
                } else if (simulator.temperature < 0) {
                    simulator.adjust_temperature(10);
                    simulator.update_state("Boiling");
                } else {
                    simulator.update_state("Stable");
                }
            }
        }
    }

    static class SimulationController {
        ThermodynamicSimulator simulator;
        StateTransformer transformer;

        SimulationController(ThermodynamicSimulator simulator, StateTransformer transformer) {
            this.simulator = simulator;
            this.transformer = transformer;
        }

        void run() {
            while (true) {
                transformer.transform();
                simulator.adjust_pressure(1);
                if (simulator.pressure > 1000) {
                    simulator.adjust_pressure(-1000);
                }
            }
        }
    }

    public static void main(String[] args) {
        String initial_state = "Liquid";
        double initial_temperature = 50;
        double initial_pressure = 500;
        ThermodynamicSimulator simulator = new ThermodynamicSimulator(initial_state, initial_temperature, initial_pressure);
        StateTransformer transformer = new StateTransformer(simulator);
        SimulationController controller = new SimulationController(simulator, transformer);
        controller.run();
    }
}