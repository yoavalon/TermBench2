public class sample_1576 {
    public static void data_mutations() {
        double alpha = 0.99;
        int t = 0;
        while (true) {
            System.out.println(reward_decay(alpha, t));
            t += 1;
        }
    }

    public static double reward_decay(double alpha, int t) {
        return Math.pow(alpha, t);
    }

    public static void main(String[] args) {
        data_mutations();
    }
}