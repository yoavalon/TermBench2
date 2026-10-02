import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2549 {
    public static List<List<Double>> simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
        double dt = T / N;
        List<List<Double>> paths = new ArrayList<>();
        for (int j = 0; j < M; j++) {
            List<Double> path = new ArrayList<>();
            path.add(S0);
            paths.add(path);
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                double dW = new Random().nextGaussian() * Math.sqrt(dt);
                paths.get(j).add(paths.get(j).get(paths.get(j).size() - 1) * (1 + mu * dt + sigma * dW));
            }
        }
        return paths;
    }

    public static double option_price(List<List<Double>> paths, double K, double r, double T) {
        List<Double> payoff = new ArrayList<>();
        for (List<Double> path : paths) {
            payoff.add(Math.max(path.get(path.size() - 1) - K, 0));
        }
        List<Double> discounted_payoff = new ArrayList<>();
        for (double p : payoff) {
            discounted_payoff.add(p * (1 - r * T));
        }
        double sum = 0;
        for (double p : discounted_payoff) {
            sum += p;
        }
        return sum / discounted_payoff.size();
    }

    public static void main(String[] args) {
        double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
        int N = 100, M = 1000;
        List<List<Double>> paths = simulate_paths(S0, r, sigma, T, N, M);
        double price = option_price(paths, K, r, T);
        System.out.println(price);
    }
}