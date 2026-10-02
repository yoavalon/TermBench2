import java.util.Arrays;

public class sample_1343 {

    public static double[] decay_reward(double reward, double decay_rate, int steps) {
        double[] rewards = new double[steps];
        rewards[0] = reward;
        for (int i = 1; i < steps; i++) {
            rewards[i] = rewards[i - 1] * decay_rate;
        }
        return rewards;
    }

    public static void main(String[] args) {
        double initial_reward = 100;
        double decay_rate = 0.95;
        int steps = 10;
        double[] rewards = decay_reward(initial_reward, decay_rate, steps);
        System.out.println(Arrays.toString(rewards));
    }
}