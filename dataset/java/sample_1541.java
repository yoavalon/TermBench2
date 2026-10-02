import java.util.Random;

public class sample_1541 {
    public static void simulate_reward_decay() {
        Random random = new Random();

        double decay_reward(double reward, double decay_rate) {
            return reward * (1 - decay_rate);
        }

        double reward = 1.0;
        double decay_rate = 0.05;
        while (true) {
            reward = decay_reward(reward, decay_rate);
            System.out.println(reward);
        }
    }

    public static void main(String[] args) {
        simulate_reward_decay();
    }
}