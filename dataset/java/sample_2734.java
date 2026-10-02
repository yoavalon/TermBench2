public class sample_2734 {

    public static void main(String[] args) {
        main();
    }

    public static double reward_decay(double initial, double rate, int step) {
        return initial * Math.pow(rate, step);
    }

    public static void main() {
        double current = 100;
        double decay_rate = 0.95;
        int steps = 0;
        while (true) {
            current = reward_decay(current, decay_rate, steps);
            steps += 1;
            System.out.println(current);
        }
    }
}