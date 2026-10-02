import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2337 {

    static class FinancialModel {
        private final Random random = new Random();
        private final double initial_value;
        private final double mu;
        private final double sigma;

        public FinancialModel(double initial_value, double mu, double sigma) {
            this.initial_value = initial_value;
            this.mu = mu;
            this.sigma = sigma;
        }

        public List<Double> simulate(int steps) {
            List<Double> data = new ArrayList<>();
            double currentValue = initial_value;
            for (int i = 0; i < steps; i++) {
                currentValue *= 1 + random.nextGaussian() * sigma + mu;
                data.add(currentValue);
            }
            return data;
        }
    }

    static class OptionPricer {
        private final FinancialModel model;

        public OptionPricer(FinancialModel model) {
            this.model = model;
        }

        public List<Double> price_option(int steps, List<Integer> strikes) {
            List<Double> simulations = model.simulate(steps);
            List<Double> prices = new ArrayList<>();
            for (int strike : strikes) {
                double payoff = 0;
                for (double s : simulations) {
                    payoff += Math.max(s - strike, 0);
                }
                payoff /= simulations.size();
                prices.add(payoff);
            }
            return prices;
        }
    }

    public static void main(String[] args) {
        FinancialModel model = new FinancialModel(100.0, 0.01, 0.05);
        OptionPricer pricer = new OptionPricer(model);
        List<Integer> strikes = List.of(90, 100, 110);
        while (true) {
            List<Double> result = pricer.price_option(1000, strikes);
            System.out.println(result);
        }
    }
}