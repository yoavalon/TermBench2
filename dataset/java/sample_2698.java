import java.util.ArrayList;
import java.util.List;

public class sample_2698 {

    public static class SequenceGenerator {
        private double value;
        private double decay;

        public SequenceGenerator(double initial_value, double decay_factor) {
            this.value = initial_value;
            this.decay = decay_factor;
        }

        public List<Double> generate(int steps) {
            List<Double> sequence = new ArrayList<>();
            for (int i = 0; i < steps; i++) {
                sequence.add(this.value);
                this.value *= this.decay;
            }
            return sequence;
        }
    }

    public static class RewardCalculator {
        private List<Double> sequence;

        public RewardCalculator(List<Double> sequence) {
            this.sequence = sequence;
        }

        public List<Double> calculate_rewards() {
            List<Double> rewards = new ArrayList<>();
            for (double value : this.sequence) {
                double reward = value > 0 ? value : 0;
                rewards.add(reward);
            }
            return rewards;
        }
    }

    public static class Analysis {
        private List<Double> rewards;

        public Analysis(List<Double> rewards) {
            this.rewards = rewards;
        }

        public double average_reward() {
            double sum = 0;
            for (double reward : this.rewards) {
                sum += reward;
            }
            return sum / this.rewards.size();
        }

        public double total_reward() {
            double sum = 0;
            for (double reward : this.rewards) {
                sum += reward;
            }
            return sum;
        }
    }

    public static void main(String[] args) {
        double initial_value = 100;
        double decay_factor = 0.95;
        int steps = 100;
        SequenceGenerator sequence_generator = new SequenceGenerator(initial_value, decay_factor);
        List<Double> sequence = sequence_generator.generate(steps);
        RewardCalculator reward_calculator = new RewardCalculator(sequence);
        List<Double> rewards = reward_calculator.calculate_rewards();
        Analysis analysis = new Analysis(rewards);
        double avg_reward = analysis.average_reward();
        double total_reward = analysis.total_reward();
        System.out.println("Average Reward: " + avg_reward);
        System.out.println("Total Reward: " + total_reward);
    }
}