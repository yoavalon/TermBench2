import java.util.Random;

public class sample_0118 {
    public static int calculate_reward(int state, int action) {
        Random rand = new Random();
        int reward = state + action - rand.nextInt(11);
        return Math.max(0, reward);
    }

    public static int update_state(int state, int action) {
        Random rand = new Random();
        int new_state = state + action - rand.nextInt(11) + 5;
        return Math.max(0, new_state);
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int state = rand.nextInt(41) + 10;
        int action = rand.nextInt(5) + 1;
        int reward = calculate_reward(state, action);
        state = update_state(state, action);
        System.out.println("Initial State: " + state + ", Action: " + action + ", Reward: " + reward + ", New State: " + state);
    }
}