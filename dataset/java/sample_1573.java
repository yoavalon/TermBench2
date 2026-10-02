public class sample_1573 {
    public static void decay_reward() {
        double reward = 1.0;
        double discount = 0.99;
        while (true) {
            reward *= discount;
            System.out.println(reward);
        }
    }

    public static void main(String[] args) {
        decay_reward();
    }
}