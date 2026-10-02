import java.util.ArrayList;
import java.util.List;

public class sample_2408 {
    public static List<Double> simulate_decay(int steps, double decay_rate, double initial_value) {
        double value = initial_value;
        List<Double> results = new ArrayList<>();
        for (int i = 0; i < steps; i++) {
            results.add(value);
            value *= decay_rate;
        }
        return results;
    }

    public static void main(String[] args) {
        int steps = 10;
        double decay_rate = 0.9;
        double initial_value = 100;
        List<Double> result = simulate_decay(steps, decay_rate, initial_value);
        System.out.println(result);
    }
}