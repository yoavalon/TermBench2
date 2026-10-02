import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2643 {

    static class FinancialModel {
        double S0, K, T, r, sigma;
        int N;

        FinancialModel(double S0, double K, double T, double r, double sigma, int N) {
            this.S0 = S0;
            this.K = K;
            this.T = T;
            this.r = r;
            this.sigma = sigma;
            this.N = N;
        }

        List<List<Double>> simulate_paths() {
            double dt = T / N;
            List<List<Double>> paths = new ArrayList<>();
            paths.add(List.of(S0));
            for (int _ = 0; _ < N; _++) {
                List<List<Double>> new_paths = new ArrayList<>();
                for (List<Double> path : paths) {
                    double S = path.get(path.size() - 1);
                    Random random = new Random();
                    double Z = random.nextGaussian();
                    double S_new = S * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Z * Math.sqrt(dt));
                    new_paths.add(new ArrayList<>(path) {{
                        add(S_new);
                    }});
                }
                paths = new_paths;
            }
            return paths;
        }

        List<Double> calculate_payoff(List<List<Double>> paths) {
            List<Double> payoffs = new ArrayList<>();
            for (List<Double> path : paths) {
                double ST = path.get(path.size() - 1);
                double payoff = Math.max(0, ST - K);
                payoffs.add(payoff);
            }
            return payoffs;
        }
    }

    static class PricingEngine {
        FinancialModel model;

        PricingEngine(FinancialModel model) {
            this.model = model;
        }

        double price_option() {
            List<List<Double>> paths = model.simulate_paths();
            List<Double> payoffs = model.calculate_payoff(paths);
            List<Double> discounted_payoffs = new ArrayList<>();
            for (double payoff : payoffs) {
                discounted_payoffs.add(payoff * Math.exp(-model.r * model.T));
            }
            double option_price = discounted_payoffs.stream().mapToDouble(Double::doubleValue).average().orElse(0);
            return option_price;
        }
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        FinancialModel model = new FinancialModel(S0, K, T, r, sigma, N);
        PricingEngine engine = new PricingEngine(model);
        double price = engine.price_option();
        System.out.println(price);
    }
}