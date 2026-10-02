public class sample_2905 {

    static class SequenceGenerator {
        int current;
        int step;

        SequenceGenerator(int start, int step) {
            this.current = start;
            this.step = step;
        }

        int next() {
            int value = this.current;
            this.current += this.step;
            return value;
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
            double reward = this.current_reward;
            this.current_reward *= this.decay_rate;
            return reward;
        }
    }

    static class Agent {
        SequenceGenerator sequence;
        RewardCalculator reward_calculator;
        double total_reward;

        Agent(SequenceGenerator sequence, RewardCalculator reward_calculator) {
            this.sequence = sequence;
            this.reward_calculator = reward_calculator;
            this.total_reward = 0;
        }

        Object[] step() {
            int action = this.sequence.next();
            double reward = this.reward_calculator.calculate();
            this.total_reward += reward;
            return new Object[]{action, reward};
        }

        void interact() {
            while (true) {
                Object[] result = this.step();
                int action = (int) result[0];
                double reward = (double) result[1];
                System.out.printf("Action: %d, Reward: %.2f, Total Reward: %.2f%n", action, reward, this.total_reward);
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator sequence = new SequenceGenerator(0, 1);
        RewardCalculator reward_calculator = new RewardCalculator(1.0, 0.95);
        Agent agent = new Agent(sequence, reward_calculator);
        agent.interact();
    }
}