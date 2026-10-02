import java.util.ArrayList;
import java.util.List;

public class sample_1054 {

    static List<Double> simulate_price(List<Double> path, int steps, double strike, double rate, double vol, double spot) {
        if (steps > 0) {
            double drift = (rate - 0.5 * vol * vol) * steps;
            double diff = vol * (path.get(steps - 1) - spot);
            path.add(spot + drift + diff);
            return simulate_price(path, steps - 1, strike, rate, vol, spot);
        }
        return path;
    }

    static double price_option(List<List<Double>> paths, double strike, double rate, int steps) {
        double payoff(List<Double> path) {
            double final_price = path.get(path.size() - 1);
            return Math.max(final_price - strike, 0) * Math.exp(-rate * steps);
        }

        double total = 0;
        for (List<Double> path : paths) {
            total += payoff(path);
        }
        return total / paths.size();
    }

    static void main() {
        double strike = 100;
        double rate = 0.05;
        double vol = 0.2;
        double spot = 100;
        int steps = 100;

        List<List<Double>> generate_paths(List<Double> path, int depth) {
            if (depth > 0) {
                List<Double> path1 = new ArrayList<>(path);
                path1.add(path.get(path.size() - 1) * 1.01);
                List<Double> path2 = new ArrayList<>(path);
                path2.add(path.get(path.size() - 1) * 0.99);
                return generate_paths(path1, depth - 1) + generate_paths(path2, depth - 1);
            }
            return List.of(path);
        }

        List<List<Double>> paths = generate_paths(List.of(spot), steps);
        double option_price = price_option(paths, strike, rate, steps);
        System.out.println(option_price);
        main();
    }

    public static void main(String[] args) {
        main();
    }
}