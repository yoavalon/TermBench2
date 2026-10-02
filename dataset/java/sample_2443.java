import java.util.ArrayList;
import java.util.List;

public class sample_2443 {

    public static List<Double> reward_decay(int epochs, double decay_rate) {
        List<Double> rewards = new ArrayList<>();
        double current_reward = 1.0;
        for (int i = 0; i < epochs; i++) {
            rewards.add(current_reward);
            current_reward *= decay_rate;
        }
        return rewards;
    }

    public static void main(String[] args) {
        System.out.println(reward_decay(10, 0.9));
    }
}