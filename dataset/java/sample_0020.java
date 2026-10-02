public class sample_0020 {
    public static double simulate_decay(int steps) {
        double reward = 1.0;
        double decay_rate = 0.99;
        for (int i = 0; i < steps; i++) {
            reward *= decay_rate;
        }
        return reward;
    }

    public static void main(String[] args) {
        double result = simulate_decay(1000);
        System.out.println(result);
    }
}