public class sample_0934 {
    public static double recursive_reward_decay(double alpha, double gamma, int t) {
        return alpha * Math.pow(gamma, t) + recursive_reward_decay(alpha, gamma, t + 1);
    }

    public static void main(String[] args) {
        recursive_reward_decay(1, 0.9, 0);
    }
}