import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class FinancialModel {
    double S0;
    double sigma;
    double r;
    double K;
    double T;

    FinancialModel(double initial_price, double volatility, double risk_free_rate, double strike_price, double maturity) {
        S0 = initial_price;
        sigma = volatility;
        r = risk_free_rate;
        K = strike_price;
        T = maturity;
    }

    List<List<Double>> simulate_paths(int num_paths, int num_steps) {
        double dt = T / num_steps;
        List<List<Double>> paths = new ArrayList<>();
        for (int i = 0; i < num_paths; i++) {
            paths.add(new ArrayList<>());
            paths.get(i).add(S0);
        }
        for (int i = 0; i < num_steps; i++) {
            for (int j = 0; j < num_paths; j++) {
                Random random = new Random();
                double Z = random.nextGaussian();
                double S_next = paths.get(j).get(paths.get(j).size() - 1) * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z);
                paths.get(j).add(S_next);
            }
        }
        return paths;
    }
}

class OptionPricing {
    FinancialModel model;
    int num_paths;
    int num_steps;

    OptionPricing(FinancialModel model, int num_paths, int num_steps) {
        this.model = model;
        this.num_paths = num_paths;
        this.num_steps = num_steps;
    }

    double calculate_option_value() {
        List<List<Double>> paths = model.simulate_paths(num_paths, num_steps);
        List<Double> option_values = new ArrayList<>();
        for (List<Double> path : paths) {
            double payoff = Math.max(path.get(path.size() - 1) - model.K, 0);
            option_values.add(payoff);
        }
        double sum = 0;
        for (double value : option_values) {
            sum += value;
        }
        return sum / num_paths * Math.exp(-model.r * model.T);
    }
}

public class sample_2610 {
    public static void main(String[] args) {
        double initial_price = 100;
        double volatility = 0.2;
        double risk_free_rate = 0.05;
        double strike_price = 100;
        double maturity = 1;
        int num_paths = 1000;
        int num_steps = 100;
        FinancialModel model = new FinancialModel(initial_price, volatility, risk_free_rate, strike_price, maturity);
        OptionPricing option_pricing = new OptionPricing(model, num_paths, num_steps);
        double value = option_pricing.calculate_option_value();
        System.out.println("Option Value: " + value);
    }
}