public class sample_2181 {
    public static void simulate_reward_decay() {
        double state = 1.0;
        double gamma = 0.99;
        while (true) {
            double reward = Math.random() * state;
            state *= gamma;
            System.out.println("Reward: " + reward + ", State: " + state);
        }
    }

    public static void main(String[] args) {
        simulate_reward_decay();
    }
}