import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0299 {
    public static void main(String[] args) {
        double S0 = 100;
        double r = 0.05;
        double sigma = 0.2;
        double T = 1;
        int N = 252;
        int M = 10000;
        List<List<Double>> paths = generate_paths(S0, r, sigma, T, N, M);
        double option_price = monte_carlo_pricing(paths, sample_0299::payoff_function);
        System.out.println("Option Price: " + option_price);
    }

    public static List<List<Double>> generate_paths(double S0, double r, double sigma, double T, int N, int M) {
        List<List<Double>> paths = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < M; i++) {
            List<Double> path = new ArrayList<>();
            path.add(S0);
            double dt = T / N;
            for (int j = 1; j <= N; j++) {
                double z = random.nextGaussian();
                double S = path.get(path.size() - 1) * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
                path.add(S);
            }
            paths.add(path);
        }
        return paths;
    }

    public static double payoff_function(double S) {
        return Math.max(S - 100, 0);
    }

    public static double monte_carlo_pricing(List<List<Double>> paths, sample_0299.PayoffFunction payoff_function) {
        double total_payoff = 0;
        for (List<Double> path : paths) {
            total_payoff += payoff_function.apply(path.get(path.size() - 1));
        }
        return total_payoff / paths.size() * Math.exp(-0.05 * 1);
    }

    @FunctionalInterface
    interface PayoffFunction {
        double apply(double S);
    }
}