public class sample_2909 {

    static class SequenceGenerator {
        int base;
        int increment;
        int current;

        SequenceGenerator(int base, int increment) {
            this.base = base;
            this.increment = increment;
            this.current = base;
        }

        int next_value() {
            this.current += this.increment;
            return this.current;
        }
    }

    static class RewardCalculator {
        double current_reward;
        double decay_rate;

        RewardCalculator(double initial_reward, double decay_rate) {
            this.current_reward = initial_reward;
            this.decay_rate = decay_rate;
        }

        double calculate() {
            this.current_reward *= this.decay_rate;
            return this.current_reward;
        }
    }

    static class Environment {
        SequenceGenerator sequence;
        RewardCalculator reward;

        Environment(SequenceGenerator sequence_generator, RewardCalculator reward_calculator) {
            this.sequence = sequence_generator;
            this.reward = reward_calculator;
        }

        int[] step() {
            int value = this.sequence.next_value();
            double reward = this.reward.calculate();
            return new int[]{value, (int)reward};
        }
    }

    public static void main(String[] args) {
        int base = 1;
        int increment = 1;
        double initial_reward = 100;
        double decay_rate = 0.99;
        SequenceGenerator sequence_generator = new SequenceGenerator(base, increment);
        RewardCalculator reward_calculator = new RewardCalculator(initial_reward, decay_rate);
        Environment environment = new Environment(sequence_generator, reward_calculator);
        while (true) {
            int[] result = environment.step();
            System.out.println("Value: " + result[0] + ", Reward: " + result[1]);
        }
    }
}