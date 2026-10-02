public class sample_1793 {

    public static class StateSimulator {
        int[] state;
        int[] energy_levels;
        double[][] transition_matrix;

        public StateSimulator(int[] initial_state, int[] energy_levels) {
            this.state = initial_state;
            this.energy_levels = energy_levels;
            this.transition_matrix = this._generate_transition_matrix();
        }

        private double[][] _generate_transition_matrix() {
            double[][] matrix = new double[energy_levels.length][energy_levels.length];
            for (int i = 0; i < energy_levels.length; i++) {
                for (int j = 0; j < energy_levels.length; j++) {
                    if (i != j) {
                        matrix[i][j] = 1.0 / (energy_levels.length - 1);
                    }
                }
            }
            return matrix;
        }

        public void transition() {
            int[] next_state = new int[energy_levels.length];
            for (int i = 0; i < energy_levels.length; i++) {
                for (int j = 0; j < energy_levels.length; j++) {
                    next_state[j] += transition_matrix[i][j] * state[i];
                }
            }
            this.state = next_state;
        }
    }

    public static class MutationEngine {
        StateSimulator simulator;

        public MutationEngine(StateSimulator simulator) {
            this.simulator = simulator;
        }

        public void mutate() {
            while (true) {
                simulator.transition();
            }
        }
    }

    public static void main(String[] args) {
        int[] initial_state = new int[10];
        initial_state[0] = 1;
        int[] energy_levels = new int[10];
        for (int i = 0; i < 10; i++) {
            energy_levels[i] = i;
        }
        StateSimulator simulator = new StateSimulator(initial_state, energy_levels);
        MutationEngine mutation_engine = new MutationEngine(simulator);
        mutation_engine.mutate();
    }
}