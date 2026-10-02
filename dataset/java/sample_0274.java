import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0274 {
    public static List<List<Double>> generate_paths(double S0, double mu, double sigma, double T, int N, int M) {
        double dt = T / N;
        List<List<Double>> paths = new ArrayList<>();
        for (int j = 0; j < M; j++) {
            List<Double> path = new ArrayList<>();
            path.add(S0);
            paths.add(path);
        }
        for (int t = 1; t <= N; t++) {
            for (int j = 0; j < M; j++) {
                double z = new Random().nextGaussian();
                double S = paths.get(j).get(paths.get(j).size() - 1) * (1 + mu * dt + sigma * z * Math.sqrt(dt));
                paths.get(j).add(S);
            }
        }
        return paths;
    }

    public static List<Double> payoff(List<List<Double>> paths, double K, double T) {
        List<Double> terminal_values = new ArrayList<>();
        for (List<Double> path : paths) {
            terminal_values.add(path.get(path.size() - 1));
        }
        List<Double> payoffs = new ArrayList<>();
        for (double S : terminal_values) {
            payoffs.add(Math.max(S - K, 0));
        }
        return payoffs;
    }

    public static List<Double> discount(List<Double> payoffs, double r, double T) {
        List<Double> discounted_payoffs = new ArrayList<>();
        for (double p : payoffs) {
            discounted_payoffs.add(p / Math.pow(1 + r, T));
        }
        return discounted_payoffs;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double r = 0.05;
        double T = 1;
        int N = 252;
        int M = 10000;
        double mu = 0.05;
        double sigma = 0.2;
        List<List<Double>> paths = generate_paths(S0, mu, sigma, T, N, M);
        List<Double> payoffs = payoff(paths, K, T);
        List<Double> discounted_payoffs = discount(payoffs, r, T);
        double option_price = 0;
        for (double p : discounted_payoffs) {
            option_price += p;
        }
        option_price /= M;
        System.out.println('Option Price: ' + option_price);
    }
}