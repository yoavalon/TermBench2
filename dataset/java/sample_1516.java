public class sample_1516 {
    public static void main(String[] args) {
        double reward = 1.0;
        double decay_rate = 0.99;
        while (true) {
            System.out.println(reward);
            reward *= decay_rate;
        }
    }
}