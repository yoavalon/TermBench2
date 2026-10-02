import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2836 {

    public static List<Integer> generate_sequence(int length) {
        List<Integer> sequence = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < length; i++) {
            sequence.add(random.nextInt(100) + 1);
        }
        return sequence;
    }

    public static double calculate_reward(List<Integer> sequence, double decay_rate) {
        double reward = 0;
        for (int i = 0; i < sequence.size(); i++) {
            reward += sequence.get(i) * Math.pow(decay_rate, i);
        }
        return reward;
    }

    public static void main(String[] args) {
        double decay_rate = 0.9;
        Random random = new Random();
        while (true) {
            int seq_length = random.nextInt(16) + 5;
            List<Integer> sequence = generate_sequence(seq_length);
            double reward = calculate_reward(sequence, decay_rate);
            System.out.printf("Sequence: %s, Reward: %.2f%n", sequence, reward);
        }
    }
}