public class sample_2405 {
    public static double reward_decay(double alpha, double gamma, int steps) {
        double reward = 1;
        for (int i = 0; i < steps; i++) {
            reward *= alpha * gamma;
        }
        return reward;
    }

    public static void main(String[] args) {
        double alpha = 0.5;
        double gamma = 0.9;
        int steps = 10;
        double result = reward_decay(alpha, gamma, steps);
        System.out.println(result);
    }
}