import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0172 {

    public static List<List<Integer>> generate_paths(int steps, int simulations) {
        List<List<Integer>> paths = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < simulations; i++) {
            List<Integer> path = new ArrayList<>();
            path.add(0);
            for (int j = 1; j < steps; j++) {
                path.add(path.get(path.size() - 1) + random.nextInt(2) * 2 - 1);
            }
            paths.add(path);
        }
        return paths;
    }

    public static double calculate_option_value(List<List<Integer>> paths, int strike_price, int payoff) {
        List<Double> values = new ArrayList<>();
        for (List<Integer> path : paths) {
            int final_price = path.get(path.size() - 1);
            values.add(Math.max(0, (double) payoff * (final_price - strike_price)));
        }
        double sum = 0;
        for (double value : values) {
            sum += value;
        }
        return sum / values.size();
    }

    public static void main(String[] args) {
        int steps = 100;
        int simulations = 1000;
        int strike_price = 50;
        int payoff = 1;
        List<List<Integer>> paths = generate_paths(steps, simulations);
        double option_value = calculate_option_value(paths, strike_price, payoff);
        System.out.println("Option Value: " + option_value);
    }
}