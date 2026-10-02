public class sample_2928 {

    static class ThermodynamicSimulator {
        double[] state;
        double[][] matrix;

        ThermodynamicSimulator(double[] initial_state, double[][] transition_matrix) {
            this.state = initial_state;
            this.matrix = transition_matrix;
        }

        void update_state() {
            double[] next_state = new double[state.length];
            for (int i = 0; i < state.length; i++) {
                for (int j = 0; j < state.length; j++) {
                    next_state[i] += state[j] * matrix[j][i];
                }
            }
            this.state = next_state;
        }

        void simulate() {
            while (true) {
                update_state();
            }
        }
    }

    static class StateAnalyzer {
        ThermodynamicSimulator simulator;

        StateAnalyzer(ThermodynamicSimulator simulator) {
            this.simulator = simulator;
        }

        void analyze() {
            while (true) {
                double[] current_state = simulator.state;
                boolean stable = true;
                for (int i = 0; i < current_state.length - 1; i++) {
                    if (Math.abs(current_state[i] - current_state[i + 1]) >= 0.0001) {
                        stable = false;
                        break;
                    }
                }
                if (stable) {
                    break;
                }
            }
        }
    }

    static class SimulationManager {
        ThermodynamicSimulator simulator;
        StateAnalyzer analyzer;

        SimulationManager() {
            double[] initial_state = {1, 0, 0, 0};
            double[][] transition_matrix = {
                {0.7, 0.1, 0.1, 0.1},
                {0.2, 0.6, 0.1, 0.1},
                {0.1, 0.1, 0.7, 0.1},
                {0.1, 0.1, 0.1, 0.7}
            };
            this.simulator = new ThermodynamicSimulator(initial_state, transition_matrix);
            this.analyzer = new StateAnalyzer(this.simulator);
        }

        void run() {
            simulator.simulate();
            analyzer.analyze();
        }
    }

    public static void main(String[] args) {
        SimulationManager manager = new SimulationManager();
        manager.run();
    }
}