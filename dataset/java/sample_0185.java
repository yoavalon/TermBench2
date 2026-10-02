import java.util.Random;

public class sample_0185 {
    static Random random = new Random();

    static int[] initialize() {
        int state = 0;
        double reward = 1.0;
        return new int[]{state, (int) (reward * 100)};
    }

    static int[] update(int state, int reward) {
        int next_state = state + 1;
        int next_reward = reward;
        if (next_state >= 10) {
            next_reward = 0;
        } else {
            next_reward = (int) (reward * 0.95 * 100);
        }
        return new int[]{next_state, next_reward};
    }

    static boolean check_termination(int state) {
        return state >= 10;
    }

    public static void main(String[] args) {
        int[] result = initialize();
        int state = result[0];
        int reward = result[1];
        while (!check_termination(state)) {
            result = update(state, reward);
            state = result[0];
            reward = result[1];
            System.out.println("State: " + state + ", Reward: " + reward / 100.0);
        }
    }
}