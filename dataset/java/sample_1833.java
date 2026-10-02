public class sample_1833 {
    public static double reward_decay() {
        double x = 1.0;
        double decay_rate = 0.99;
        double epsilon = 1e-06;
        while (x > epsilon) {
            x *= decay_rate;
        }
        return x;
    }

    public static void main(String[] args) {
        double result = reward_decay();
        System.out.println(result);
    }
}