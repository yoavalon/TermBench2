import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0105 {
    public static double update_reward(double state, int action) {
        if (action == 0) {
            return state * 0.95;
        } else {
            return state * 0.9;
        }
    }

    public static double simulate_episodes(int num_episodes, int max_steps) {
        List<Double> rewards = new ArrayList<>();
        Random rand = new Random();
        for (int i = 0; i < num_episodes; i++) {
            double state = 1.0;
            for (int j = 0; j < max_steps; j++) {
                int action = rand.nextInt(2);
                state = update_reward(state, action);
                if (state < 0.1) {
                    break;
                }
            }
            rewards.add(state);
        }
        double sum = 0.0;
        for (double reward : rewards) {
            sum += reward;
        }
        return sum / rewards.size();
    }

    public static void main(String[] args) {
        double result = simulate_episodes(100, 1000);
        System.out.println(result);
    }
}