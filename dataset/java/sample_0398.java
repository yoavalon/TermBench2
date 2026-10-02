public class sample_0398 {

    public static void main(String[] args) {
        main();
    }

    public static void main() {
        int step = 0;
        while (true) {
            System.out.printf("Step %d: Reward %.4f%n", step, reward_decay(step));
            step += 1;
        }
    }

    public static double reward_decay(int step) {
        return Math.pow(0.99, step);
    }
}