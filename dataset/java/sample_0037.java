import java.util.ArrayList;
import java.util.List;

public class sample_0037 {
    public static List<Double> decay_reward(double alpha, double gamma, int epochs) {
        List<Double> rewards = new ArrayList<>();
        double reward = 1.0;
        for (int i = 0; i < epochs; i++) {
            reward *= gamma;
            rewards.add(reward);
        }
        return rewards;
    }

    public static void main(String[] args) {
        decay_reward(0.1, 0.95, 10);
    }
}