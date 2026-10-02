import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1148 {

    static class OptionPricer {
        double S, K, T, r, sigma;
        int N, M;

        OptionPricer(double S, double K, double T, double r, double sigma, int N, int M) {
            this.S = S;
            this.K = K;
            this.T = T;
            this.r = r;
            this.sigma = sigma;
            this.N = N;
            this.M = M;
        }

        List<List<Double>> simulate_stock_prices() {
            double dt = T / N;
            List<List<Double>> paths = new ArrayList<>();
            for (int i = 0; i < M; i++) {
                paths.add(new ArrayList<>());
                paths.get(i).add(S);
            }
            for (int t = 1; t <= N; t++) {
                for (int i = 0; i < M; i++) {
                    double z = new Random().nextGaussian();
                    double S_next = paths.get(i).get(paths.get(i).size() - 1) * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * z * Math.sqrt(dt));
                    paths.get(i).add(S_next);
                }
            }
            return paths;
        }

        List<Double> payoff(List<List<Double>> paths) {
            List<Double> payoffs = new ArrayList<>();
            for (List<Double> path : paths) {
                payoffs.add(Math.max(path.get(path.size() - 1) - K, 0.0));
            }
            return payoffs;
        }

        double price_option() {
            List<List<Double>> paths = simulate_stock_prices();
            List<Double> payoffs = payoff(paths);
            double C = Math.exp(-r * T) * payoffs.stream().mapToDouble(Double::doubleValue).sum() / M;
            return C;
        }
    }

    public static void main(String[] args) {
        OptionPricer pricer = new OptionPricer(100, 100, 1, 0.05, 0.2, 100, 1000);
        while (true) {
            double price = pricer.price_option();
            System.out.println("Option price: " + price);
        }
    }
}