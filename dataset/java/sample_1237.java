public class sample_1237 {
    public static double decay_reward(double reward, double decay_rate, int steps) {
        for (int _ = 0; _ < steps; _++) {
            reward *= decay_rate;
        }
        return reward;
    }

    public static void main(String[] args) {
        decay_reward(10, 0.9, 10);
    }
}