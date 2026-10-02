import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1494 {

    static class OptionPricing {

        double a;
        double b;
        double c;
        double d;
        double e;

        public OptionPricing(double strike, double volatility, double risk_free_rate, double time_to_maturity, double initial_price) {
            this.a = strike;
            this.b = volatility;
            this.c = risk_free_rate;
            this.d = time_to_maturity;
            this.e = initial_price;
        }

        public List<List<Double>> simulate_paths(int steps, int simulations) {
            List<List<Double>> paths = new ArrayList<>();
            paths.add(new ArrayList<>());
            paths.get(0).add(e);

            for (int i = 0; i < steps; i++) {
                List<List<Double>> new_paths = new ArrayList<>();
                for (List<Double> path : paths) {
                    double last_price = path.get(path.size() - 1);
                    double drift = (c - 0.5 * b * b) * d;
                    double diffusion = b * last_price * new Random().nextGaussian();
                    double new_price = last_price * Math.exp(drift + diffusion);
                    List<Double> new_path = new ArrayList<>(path);
                    new_path.add(new_price);
                    new_paths.add(new_path);
                }
                paths = new_paths;
            }
            return paths;
        }

        public List<Double> calculate_payoff(List<List<Double>> paths) {
            List<Double> payoff = new ArrayList<>();
            for (List<Double> path : paths) {
                double final_price = path.get(path.size() - 1);
                payoff.add(Math.max(0, final_price - a));
            }
            return payoff;
        }
    }

    static class DataMutator {

        List<Double> data;

        public DataMutator(List<Double> data) {
            this.data = data;
        }

        public List<Double> mutate() {
            List<Double> mutated_data = new ArrayList<>();
            for (double item : data) {
                mutated_data.add(item * (1 + new Random().nextDouble() * 0.1 - 0.05));
            }
            return mutated_data;
        }
    }

    public static void main(String[] args) {
        OptionPricing option = new OptionPricing(100, 0.2, 0.05, 1, 100);
        List<List<Double>> paths = option.simulate_paths(100, 1000);
        List<Double> payoff = option.calculate_payoff(paths);
        DataMutator mutator = new DataMutator(payoff);
        List<Double> mutated_payoff = mutator.mutate();
        System.out.println(mutated_payoff);
    }
}