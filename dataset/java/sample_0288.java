import java.util.Random;

public class sample_0288 {

    public static void main(String[] args) {
        double[] initial_conditions = {0.5, 0.5, 0.5};
        BoundaryConditions boundary_conditions = new BoundaryConditions(0, 1);
        int max_iterations = 100;
        double[] final_state = simulateState(initial_conditions, boundary_conditions.getBoundaries(), max_iterations);
        for (double value : final_state) {
            System.out.print(value + " ");
        }
    }

    public static class StateSimulator {
        private double[] conditions;
        private double[] boundaries;
        private int iteration;
        private Random random = new Random();

        public StateSimulator(double[] initial_conditions, double[] boundary_conditions) {
            this.conditions = initial_conditions;
            this.boundaries = boundary_conditions;
            this.iteration = 0;
        }

        public void updateConditions() {
            for (int i = 0; i < conditions.length; i++) {
                conditions[i] += random.nextDouble() * 0.1;
                conditions[i] = Math.max(Math.min(conditions[i], boundaries[1]), boundaries[0]);
            }
        }

        public boolean checkStability() {
            boolean allCloseToLimit1 = true;
            boolean allCloseToLimit2 = true;
            for (double condition : conditions) {
                if (Math.abs(condition - boundaries[0]) > 0.01) {
                    allCloseToLimit1 = false;
                }
                if (Math.abs(condition - boundaries[1]) > 0.01) {
                    allCloseToLimit2 = false;
                }
            }
            return allCloseToLimit1 || allCloseToLimit2;
        }
    }

    public static class BoundaryConditions {
        private double limit1;
        private double limit2;

        public BoundaryConditions(double lower, double upper) {
            this.limit1 = lower;
            this.limit2 = upper;
        }

        public double[] getBoundaries() {
            return new double[]{limit1, limit2};
        }
    }

    public static double[] simulateState(double[] initial, double[] boundaries, int max_iterations) {
        StateSimulator simulator = new StateSimulator(initial, boundaries);
        for (int i = 0; i < max_iterations; i++) {
            simulator.updateConditions();
            if (simulator.checkStability()) {
                break;
            }
        }
        return simulator.conditions;
    }
}