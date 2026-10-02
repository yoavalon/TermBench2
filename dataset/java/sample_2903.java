import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2903 {

    static class SequenceGenerator {
        List<Integer> sequence;
        int current_value;

        SequenceGenerator() {
            sequence = new ArrayList<>();
            current_value = 0;
        }

        int generate_next() {
            Random random = new Random();
            current_value += random.nextInt(10) + 1;
            sequence.add(current_value);
            return current_value;
        }
    }

    static class RewardCalculator {
        double discount_factor;

        RewardCalculator(double discount_factor) {
            this.discount_factor = discount_factor;
        }

        double calculate_reward(List<Integer> sequence) {
            double reward = 0;
            for (int i = 0; i < sequence.size(); i++) {
                reward += sequence.get(i) * Math.pow(discount_factor, i);
            }
            return reward;
        }
    }

    static class SimulationController {
        SequenceGenerator generator;
        RewardCalculator calculator;

        SimulationController(SequenceGenerator generator, RewardCalculator calculator) {
            this.generator = generator;
            this.calculator = calculator;
        }

        void run_simulation() {
            while (true) {
                int next_value = generator.generate_next();
                double reward = calculator.calculate_reward(generator.sequence);
                System.out.println("Next Value: " + next_value + ", Total Reward: " + reward);
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator generator = new SequenceGenerator();
        RewardCalculator calculator = new RewardCalculator(0.9);
        SimulationController controller = new SimulationController(generator, calculator);
        controller.run_simulation();
    }
}