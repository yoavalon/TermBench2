import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0053 {

    public static List<Double> boundary_conditions() {
        Random rand = new Random();
        double state = rand.nextDouble();
        double gamma = 0.99;
        List<Double> rewards = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            if (state < 0.1) {
                break;
            }
            double reward = state * rand.nextDouble();
            rewards.add(reward);
            state *= gamma;
        }
        return rewards;
    }

    public static void main(String[] args) {
        boundary_conditions();
    }
}