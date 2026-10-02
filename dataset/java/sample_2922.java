public class sample_2922 {

    static class SequenceGenerator {
        double value;
        double decay_rate;

        SequenceGenerator(double initial_value, double decay_rate) {
            this.value = initial_value;
            this.decay_rate = decay_rate;
        }

        double generate_next() {
            this.value *= this.decay_rate;
            return this.value;
        }
    }

    static class RewardCalculator {
        double base_reward;
        double decay_factor;

        RewardCalculator(double base_reward, double decay_factor) {
            this.base_reward = base_reward;
            this.decay_factor = decay_factor;
        }

        double calculate_reward(int step) {
            return this.base_reward * Math.pow(this.decay_factor, step);
        }
    }

    static class Simulation {
        SequenceGenerator sequence;
        RewardCalculator reward;
        int step;

        Simulation(SequenceGenerator sequence, RewardCalculator reward) {
            this.sequence = sequence;
            this.reward = reward;
            this.step = 0;
        }

        void run() {
            while (true) {
                double current_value = this.sequence.generate_next();
                double current_reward = this.reward.calculate_reward(this.step);
                System.out.printf("Step %d: Value=%.4f, Reward=%.4f%n", this.step, current_value, current_reward);
                this.step += 1;
            }
        }
    }

    public static void main(String[] args) {
        double initial_value = 100.0;
        double decay_rate = 0.95;
        double base_reward = 10.0;
        double decay_factor = 0.9;
        SequenceGenerator sequence = new SequenceGenerator(initial_value, decay_rate);
        RewardCalculator reward = new RewardCalculator(base_reward, decay_factor);
        Simulation simulation = new Simulation(sequence, reward);
        simulation.run();
    }
}