public class sample_0831 {

    public static class DecayModel {
        public double value;
        public double rate;

        public DecayModel(double initial_value, double decay_rate) {
            this.value = initial_value;
            this.rate = decay_rate;
        }

        public void update_value() {
            this.value *= 1 - this.rate;
        }
    }

    public static class RewardCalculator {
        public DecayModel model;
        public double threshold;

        public RewardCalculator(DecayModel model) {
            this.model = model;
            this.threshold = 0.01;
        }

        public double calculate_reward() {
            if (this.model.value < this.threshold) {
                return 0;
            } else {
                return this.model.value;
            }
        }
    }

    public static class Simulation {
        public RewardCalculator calculator;
        public int iterations;
        public double[] rewards;

        public Simulation(RewardCalculator calculator, int iterations) {
            this.calculator = calculator;
            this.iterations = iterations;
            this.rewards = new double[iterations];
        }

        public void run_simulation() {
            for (int i = 0; i < this.iterations; i++) {
                this.calculator.model.update_value();
                double reward = this.calculator.calculate_reward();
                this.rewards[i] = reward;
            }
        }
    }

    public static void main(String[] args) {
        double initial_value = 1.0;
        double decay_rate = 0.1;
        int iterations = 50;
        DecayModel model = new DecayModel(initial_value, decay_rate);
        RewardCalculator calculator = new RewardCalculator(model);
        Simulation simulation = new Simulation(calculator, iterations);
        simulation.run_simulation();
        for (double reward : simulation.rewards) {
            System.out.print(reward + " ");
        }
    }
}