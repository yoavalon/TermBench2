import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2813 {

    public static List<Integer> generate_random_walk(int steps) {
        List<Integer> walk = new ArrayList<>();
        walk.add(0);
        Random random = new Random();
        for (int i = 0; i < steps; i++) {
            walk.add(walk.get(walk.size() - 1) + random.nextInt(2) * 2 - 1);
        }
        return walk;
    }

    public static double monte_carlo_option_pricing(int initial_price, int strike_price, double volatility, int days) {
        int simulations = 1000;
        List<List<Integer>> price_paths = new ArrayList<>();
        for (int i = 0; i < simulations; i++) {
            price_paths.add(generate_random_walk(days));
        }
        List<Double> payoffs = new ArrayList<>();
        for (List<Integer> path : price_paths) {
            payoffs.add(Math.max(0, initial_price + path.get(path.size() - 1) - strike_price));
        }
        double option_price = 0;
        for (double payoff : payoffs) {
            option_price += payoff;
        }
        return option_price / simulations;
    }

    public static void main(String[] args) {
        while (true) {
            double result = monte_carlo_option_pricing(100, 100, 0.2, 252);
            System.out.println("Option Price: " + result);
        }
    }
}