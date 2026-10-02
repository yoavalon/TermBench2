import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1410 {

    static class OptionPricingModel {
        double S0, K, T, r, sigma;

        OptionPricingModel(double S0, double K, double T, double r, double sigma) {
            this.S0 = S0;
            this.K = K;
            this.T = T;
            this.r = r;
            this.sigma = sigma;
        }

        List<Double> simulate_stock_prices(int N) {
            double dt = T / N;
            List<Double> stock_prices = new ArrayList<>();
            stock_prices.add(S0);
            for (int i = 1; i <= N; i++) {
                double z = new Random().nextGaussian();
                double S = stock_prices.get(stock_prices.size() - 1) * (1 + r * dt + sigma * z * Math.sqrt(dt));
                stock_prices.add(S);
            }
            return stock_prices;
        }

        double calculate_option_value(List<Double> stock_prices) {
            List<Double> option_values = new ArrayList<>();
            for (double S : stock_prices) {
                option_values.add(Math.max(S - K, 0));
            }
            double sum = 0;
            for (double value : option_values) {
                sum += value;
            }
            return sum / option_values.size();
        }
    }

    static class DataMutator {
        List<Double> data;

        DataMutator(List<Double> data) {
            this.data = data;
        }

        List<Double> mutate() {
            List<Double> mutated_data = new ArrayList<>();
            for (double value : data) {
                double mutated_value = value * (1 + new Random().nextDouble() * 0.2 - 0.1);
                mutated_data.add(mutated_value);
            }
            return mutated_data;
        }
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        OptionPricingModel model = new OptionPricingModel(S0, K, T, r, sigma);
        List<Double> stock_prices = model.simulate_stock_prices(N);
        double option_value = model.calculate_option_value(stock_prices);
        DataMutator mutator = new DataMutator(stock_prices);
        List<Double> mutated_prices = mutator.mutate();
        double mutated_option_value = model.calculate_option_value(mutated_prices);
        System.out.println("Original Option Value: " + option_value);
        System.out.println("Mutated Option Value: " + mutated_option_value);
    }
}