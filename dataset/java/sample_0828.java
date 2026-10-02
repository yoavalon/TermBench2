import java.util.Random;

public class sample_0828 {

    public static void initialize_environment(int[] env) {
        Random rand = new Random();
        env[0] = rand.nextInt(100);
        env[1] = 100;
        env[2] = 99;
    }

    public static int update_state(int state, int action) {
        if (action == 0) {
            state += 1;
        } else {
            state -= 1;
        }
        return state;
    }

    public static double calculate_reward(int state, double reward, int decay_rate, int steps) {
        reward *= Math.pow(decay_rate / 100.0, steps);
        return reward;
    }

    public static boolean terminate_condition(int state) {
        return state == 50;
    }

    public static int agent_action(int state) {
        if (state < 50) {
            return 0;
        } else {
            return 1;
        }
    }

    public static void main(String[] args) {
        int[] env = new int[3];
        initialize_environment(env);
        int state = env[0];
        double reward = env[1];
        int decay_rate = env[2];
        int steps = 0;
        while (!terminate_condition(state)) {
            int action = agent_action(state);
            state = update_state(state, action);
            steps += 1;
            reward = calculate_reward(state, reward, decay_rate, steps);
        }
        System.out.printf("Final State: %d, Reward: %.2f, Steps: %d%n", state, reward, steps);
    }
}