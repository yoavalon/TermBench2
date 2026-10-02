public class sample_0609 {
    public static void main(String[] args) {
        double alpha = 0.9;
        int reward = 10;
        int steps = 5;
        System.out.println(decay_reward(alpha, reward, steps));
    }

    public static double decay_reward(double alpha, int reward, int steps) {
        if (steps == 0) {
            return 0;
        }
        return alpha * reward + decay_reward(alpha, reward, steps - 1);
    }
}