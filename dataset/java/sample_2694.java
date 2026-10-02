public class sample_2694 {

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

        Iterable<Integer> generate() {
            return new Iterable<Integer>() {
                public java.util.Iterator<Integer> iterator() {
                    return new java.util.Iterator<Integer>() {
                        public boolean hasNext() {
                            return current < end;
                        }

                        public Integer next() {
                            int value = current;
                            current += step;
                            return value;
                        }
                    };
                }
            };
        }
    }

    static class RewardCalculator {
        double initial_reward;
        double decay_rate;
        double current_reward;

        RewardCalculator(double initial_reward, double decay_rate) {
            this.initial_reward = initial_reward;
            this.decay_rate = decay_rate;
            this.current_reward = initial_reward;
        }

        double calculate(int step) {
            current_reward = initial_reward * Math.pow(decay_rate, step);
            return current_reward;
        }
    }

    static double simulate(SequenceGenerator sequence_generator, RewardCalculator reward_calculator, int max_steps) {
        int steps = 0;
        double total_reward = 0;
        for (int value : sequence_generator.generate()) {
            if (steps >= max_steps) {
                break;
            }
            double reward = reward_calculator.calculate(steps);
            total_reward += reward;
            steps += 1;
        }
        return total_reward;
    }

    public static void main(String[] args) {
        SequenceGenerator seq_gen = new SequenceGenerator(0, 10, 1);
        RewardCalculator reward_calc = new RewardCalculator(1.0, 0.9);
        int max_steps = 5;
        double result = simulate(seq_gen, reward_calc, max_steps);
        System.out.println(result);
    }
}