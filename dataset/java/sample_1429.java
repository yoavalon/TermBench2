import java.util.Random;

public class sample_1429 {

    static class DataMutation {
        double[] data;

        DataMutation(double[] data) {
            this.data = data;
        }

        double[] apply_mutation(MutationFunction mutation_function) {
            this.data = mutation_function.apply(this.data);
            return this.data;
        }
    }

    interface MutationFunction {
        double[] apply(double[] data);
    }

    static class FinancialModel {
        double initial_price;
        double volatility;
        double risk_free_rate;
        int time_steps;
        int simulations;

        FinancialModel(double initial_price, double volatility, double risk_free_rate, int time_steps, int simulations) {
            this.initial_price = initial_price;
            this.volatility = volatility;
            this.risk_free_rate = risk_free_rate;
            this.time_steps = time_steps;
            this.simulations = simulations;
        }

        double[][] simulate_paths() {
            double dt = 1.0 / this.time_steps;
            double drift = (this.risk_free_rate - 0.5 * this.volatility * this.volatility) * dt;
            double diffusion = this.volatility * Math.sqrt(dt);
            double[][] paths = new double[this.time_steps + 1][this.simulations];
            paths[0] = this.initial_price;
            Random random = new Random();
            for (int t = 1; t <= this.time_steps; t++) {
                for (int i = 0; i < this.simulations; i++) {
                    double rand = random.nextGaussian();
                    paths[t][i] = paths[t - 1][i] * Math.exp(drift + diffusion * rand);
                }
            }
            return paths;
        }

        double[] calculate_payoff(double strike_price, String option_type) {
            double[][] paths = simulate_paths();
            double[] payoff = new double[this.simulations];
            if (option_type.equals("call")) {
                for (int i = 0; i < this.simulations; i++) {
                    payoff[i] = Math.max(paths[time_steps][i] - strike_price, 0);
                }
            } else if (option_type.equals("put")) {
                for (int i = 0; i < this.simulations; i++) {
                    payoff[i] = Math.max(strike_price - paths[time_steps][i], 0);
                }
            }
            return payoff;
        }

        double price_option(double strike_price, String option_type) {
            double[] payoff = calculate_payoff(strike_price, option_type);
            double option_price = Math.exp(-this.risk_free_rate * this.time_steps) * mean(payoff);
            return option_price;
        }

        double mean(double[] array) {
            double sum = 0;
            for (double value : array) {
                sum += value;
            }
            return sum / array.length;
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] data = new double[100];
        for (int i = 0; i < 100; i++) {
            data[i] = random.nextDouble();
        }
        DataMutation data_mutator = new DataMutation(data);
        double[] mutated_data = data_mutator.apply_mutation(x -> {
            double[] result = new double[x.length];
            for (int i = 0; i < x.length; i++) {
                result[i] = x[i] * 2;
            }
            return result;
        });
        FinancialModel financial_model = new FinancialModel(mutated_data[0], 0.2, 0.05, 252, 10000);
        double option_price = financial_model.price_option(100, "call");
        System.out.println(option_price);
    }
}