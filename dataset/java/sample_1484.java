import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1484 {

    static class DataProcessor {
        List<Double> data;

        DataProcessor(List<Double> data) {
            this.data = data;
        }

        List<Double> mutate_data() {
            List<Double> mutated = new ArrayList<>();
            Random random = new Random();
            for (Double item : data) {
                mutated.add(item + random.nextDouble() * 0.2 - 0.1);
            }
            return mutated;
        }
    }

    static class OptionPricer {
        List<Double> data;

        OptionPricer(List<Double> data) {
            this.data = data;
        }

        List<Double> calculate_price() {
            List<Double> prices = new ArrayList<>();
            for (Double item : data) {
                double price = black_scholes(item);
                prices.add(price);
            }
            return prices;
        }

        double black_scholes(double S) {
            double K = 100, T = 1, r = 0.05, sigma = 0.2;
            double d1 = (Math.log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * Math.sqrt(T));
            double d2 = d1 - sigma * Math.sqrt(T);
            double call_price = S * Math.exp(-r * T) * norm_cdf(d1) - K * Math.exp(-r * T) * norm_cdf(d2);
            return call_price;
        }

        double norm_cdf(double x) {
            return (1.0 + erf(x / Math.sqrt(2.0))) / 2.0;
        }

        double erf(double x) {
            double t = 1.0 / (1.0 + 0.5 * Math.abs(x));
            double ans = 1 - t * Math.exp(-x * x - 1.26551223 + t * (1.00002368 + t * (0.37409196 + t * (0.09678418 + t * (-0.18628806 + t * (0.27886807 + t * (-1.13520398 + t * (1.48851587 + t * (-0.82215223 + t * 0.17087277)))))))));
            return x >= 0 ? ans : -ans;
        }
    }

    static class TerminationAnalyzer {
        List<Double> data;

        TerminationAnalyzer(List<Double> data) {
            this.data = data;
        }

        List<Boolean> analyze() {
            List<Boolean> analysis = new ArrayList<>();
            for (Double item : data) {
                analysis.add(determine_termination(item));
            }
            return analysis;
        }

        boolean determine_termination(double item) {
            return item > 100;
        }
    }

    public static void main(String[] args) {
        List<Double> initial_data = List.of(90.0, 100.0, 110.0, 120.0, 130.0);
        DataProcessor processor = new DataProcessor(initial_data);
        List<Double> mutated_data = processor.mutate_data();
        OptionPricer pricer = new OptionPricer(mutated_data);
        List<Double> prices = pricer.calculate_price();
        TerminationAnalyzer analyzer = new TerminationAnalyzer(prices);
        List<Boolean> analysis = analyzer.analyze();
        System.out.println(analysis);
    }
}