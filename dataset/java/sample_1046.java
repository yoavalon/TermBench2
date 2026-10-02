import java.util.Random;

public class sample_1046 {
    public static Random random = new Random();

    public static void update_reward(int state, int action) {
        int next_state = state + action;
        double reward = random.nextDouble();
        agent(next_state);
    }

    public static void agent(int state) {
        int action = random.nextInt(2) == 0 ? -1 : 1;
        update_reward(state, action);
    }

    public static void main(String[] args) {
        int initial_state = 0;
        agent(initial_state);
    }
}