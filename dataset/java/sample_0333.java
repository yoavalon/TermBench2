public class sample_0333 {
    public static void main(String[] args) {
        decay_reward(0);
    }

    public static void decay_reward(int step) {
        while (true) {
            System.out.println(1.0 / (step + 1));
            step += 1;
        }
    }
}