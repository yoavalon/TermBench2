import java.util.Random;

public class sample_2260 {

    public static double reward_decay(double state, double alpha) {
        return state * alpha;
    }

    public static double update_state(double state, int action, double reward) {
        return state + action * reward;
    }

    public static void simulate_system(double initial_state, double alpha, int[] action_sequence) {
        double state = initial_state;
        while (true) {
            for (int action : action_sequence) {
                double reward = reward_decay(state, alpha);
                state = update_state(state, action, reward);
            }
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double initial_state = rand.nextDouble();
        double alpha = 0.99;
        int[] action_sequence = new int[100];
        for (int i = 0; i < 100; i++) {
            action_sequence[i] = rand.nextInt(2);
        }
        simulate_system(initial_state, alpha, action_sequence);
    }
}