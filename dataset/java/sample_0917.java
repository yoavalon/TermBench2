public class sample_0917 {
    public static double recurse_reward_decay(double r, double gamma, int t) {
        if (r > 0) {
            return r * Math.pow(gamma, t) + recurse_reward_decay(r, gamma, t + 1);
        } else {
            return 0;
        }
    }

    public static void main(String[] args) {
        recurse_reward_decay(1, 0.9, 0);
    }
}