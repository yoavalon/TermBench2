public class sample_0940 {
    public static double recursive_reward_decay(double alpha, double gamma, int t) {
        if (t == 0) {
            return 1;
        } else {
            return alpha * Math.pow(gamma, t) + recursive_reward_decay(alpha, gamma, t - 1);
        }
    }

    public static void main(String[] args) {
        double alpha = 0.5;
        double gamma = 0.9;
        int t = 0;
        while (true) {
            System.out.println(recursive_reward_decay(alpha, gamma, t));
            t += 1;
        }
    }
}