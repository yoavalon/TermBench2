import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1411 {
    public static List<List<Double>> simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
        double dt = T / N;
        List<List<Double>> paths = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            List<Double> path = new ArrayList<>();
            path.add(S0);
            paths.add(path);
        }
        for (int t = 1; t <= N; t++) {
            for (int i = 0; i < M; i++) {
                double z = new Random().nextGaussian();
                double nextValue = paths.get(i).get(paths.get(i).size() - 1) * Math.exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
                paths.get(i).add(nextValue);
            }
        }
        return paths;
    }

    public static List<Double> calculate_payoffs(List<List<Double>> paths, double K, double T, double r, String type) {
        List<Double> payoffs = new ArrayList<>();
        for (List<Double> path : paths) {
            double ST = path.get(path.size() - 1);
            double payoff;
            if (type.equals("call")) {
                payoff = Math.max(0, ST - K);
            } else {
                payoff = Math.max(0, K - ST);
            }
            payoffs.add(payoff * Math.exp(-r * T));
        }
        return payoffs;
    }

    public static double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int M) {
        List<List<Double>> paths = simulate_paths(S0, r, sigma, T, 100, M);
        List<Double> payoffs = calculate_payoffs(paths, K, T, r, "call");
        double sum = 0;
        for (double payoff : payoffs) {
            sum += payoff;
        }
        return sum / M;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int M = 10000;
        double price = monte_carlo_pricing(S0, K, T, r, sigma, M);
        System.out.printf("Option Price: %.2f%n", price);
    }
}