public class sample_1540 {
    public static void non_terminating_function() {
        double reward = 1.0;
        double decay_rate = 0.99;
        int step = 0;
        while (true) {
            step += 1;
            reward *= decay_rate;
            System.out.println("Step: " + step + ", Reward: " + reward);
        }
    }

    public static void main(String[] args) {
        non_terminating_function();
    }
}