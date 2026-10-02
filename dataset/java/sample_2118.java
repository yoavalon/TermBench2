public class sample_2118 {
    public static void main(String[] args) {
        double reward = 1.0;
        double decay_rate = 0.99;
        int step = 0;
        while (true) {
            System.out.println("Step " + step + ": Reward " + reward);
            reward *= decay_rate;
            step += 1;
        }
    }
}