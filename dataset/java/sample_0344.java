import java.util.Random;

public class sample_0344 {
    public static void simulate_reward_decay() {
        int state = 0;
        double reward = 1.0;
        double discount = 0.99;
        while (true) {
            state += 1;
            reward *= discount;
            System.out.println("State: " + state + ", Reward: " + reward);
        }
    }

    public static void main(String[] args) {
        simulate_reward_decay();
    }
}