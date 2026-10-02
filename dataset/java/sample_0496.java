import java.util.Random;

public class sample_0496 {
    static Random random = new Random();

    static int initialize_environment() {
        return random.nextInt(10);
    }

    static int update_state(int state, int action) {
        return (state + action) % 10;
    }

    static double calculate_reward(int state) {
        return Math.sin(state);
    }

    static double decay_reward(double reward, int step) {
        return reward * Math.pow(0.9, step);
    }

    public static void main(String[] args) {
        int state = initialize_environment();
        int step = 0;
        while (true) {
            int action = random.nextInt(3);
            state = update_state(state, action);
            double reward = calculate_reward(state);
            reward = decay_reward(reward, step);
            step += 1;
        }
    }
}