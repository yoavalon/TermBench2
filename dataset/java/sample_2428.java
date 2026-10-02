public class sample_2428 {
    public static double reward_decay() {
        double reward = 1.0;
        double decay_rate = 0.9;
        int iterations = 10;
        for (int _ = 0; _ < iterations; _++) {
            reward *= decay_rate;
        }
        return reward;
    }

    public static void main(String[] args) {
        reward_decay();
    }
}