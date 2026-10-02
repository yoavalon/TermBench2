import java.util.ArrayList;
import java.util.List;

public class sample_0861 {
    static class RandomNumberGenerator {
        private int state;

        public RandomNumberGenerator(int seed) {
            this.state = seed;
        }

        public double next() {
            this.state = (int) ((long) this.state * 1103515245 + 12345) % (1 << 31);
            return (double) this.state / (1 << 31);
        }
    }

    static class OptionPricer {
        private RandomNumberGenerator rng;
        private double strike;
        private double maturity;
        private double volatility;
        private double risk_free_rate;

        public OptionPricer(RandomNumberGenerator rng, double strike, double maturity, double volatility, double risk_free_rate) {
            this.rng = rng;
            this.strike = strike;
            this.maturity = maturity;
            this.volatility = volatility;
            this.risk_free_rate = risk_free_rate;
        }

        public List<Double> simulate(int steps) {
            List<Double> price_paths = new ArrayList<>();
            for (int i = 0; i < steps; i++) {
                double price = 1.0;
                for (int j = 0; j < steps; j++) {
                    double drift = this.risk_free_rate - 0.5 * this.volatility * this.volatility;
                    double diffusion = this.volatility * this.rng.next();
                    price *= 1 + drift + diffusion;
                }
                price_paths.add(price);
            }
            return price_paths;
        }

        public List<Double> payoff(List<Double> price_paths) {
            List<Double> payoff_values = new ArrayList<>();
            for (double path : price_paths) {
                payoff_values.add(Math.max(path - this.strike, 0));
            }
            return payoff_values;
        }

        public double price(int steps) {
            List<Double> price_paths = this.simulate(steps);
            List<Double> payoff_values = this.payoff(price_paths);
            double sum = 0;
            for (double value : payoff_values) {
                sum += value;
            }
            return sum * Math.exp(-this.risk_free_rate * this.maturity) / payoff_values.size();
        }
    }

    public static void main(String[] args) {
        RandomNumberGenerator rng = new RandomNumberGenerator(42);
        OptionPricer pricer = new OptionPricer(rng, 100, 1, 0.2, 0.05);
        double option_price = pricer.price(1000);
        System.out.println(option_price);
    }
}