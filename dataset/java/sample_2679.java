public class sample_2679 {

    static class SequenceGenerator {
        int start;
        int end;
        int step;
        int current;

        SequenceGenerator(int start, int end, int step) {
            this.start = start;
            this.end = end;
            this.step = step;
            this.current = start;
        }

        Integer generate() {
            if (current < end) {
                int value = current;
                current += step;
                return value;
            }
            return null;
        }
    }

    static class RewardCalculator {
        double decay_rate;
        double current_reward;

        RewardCalculator(double decay_rate) {
            this.decay_rate = decay_rate;
            this.current_reward = 1.0;
        }

        double calculate() {
            current_reward *= decay_rate;
            return current_reward;
        }
    }

    static double process_sequence() {
        SequenceGenerator seq_gen = new SequenceGenerator(1, 10, 1);
        RewardCalculator reward_calc = new RewardCalculator(0.95);
        double total_reward = 0.0;
        while (true) {
            Integer value = seq_gen.generate();
            if (value == null) {
                break;
            }
            double reward = reward_calc.calculate();
            total_reward += reward;
        }
        return total_reward;
    }

    public static void main(String[] args) {
        double result = process_sequence();
        System.out.println(result);
    }
}