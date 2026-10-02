import java.util.Random;

public class sample_0282 {

    static class FinancialModel {
        double s0;
        double k;
        double t;
        double r;
        double sigma;
        int n_simulations;

        FinancialModel(double s0, double k, double t, double r, double sigma, int n_simulations) {
            this.s0 = s0;
            this.k = k;
            this.t = t;
            this.r = r;
            this.sigma = sigma;
            this.n_simulations = n_simulations;
        }

        double[][] simulate_paths() {
            double dt = t / 365.0;
            double[][] paths = new double[n_simulations][365];
            for (int i = 0; i < n_simulations; i++) {
                paths[i][0] = s0;
            }
            for (int i = 1; i < 365; i++) {
                Random rand = new Random();
                double[] z = new double[n_simulations];
                for (int j = 0; j < n_simulations; j++) {
                    z[j] = rand.nextGaussian();
                }
                for (int j = 0; j < n_simulations; j++) {
                    paths[j][i] = paths[j][i - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[j]);
                }
            }
            return paths;
        }

        double[] calculate_payoff(double[][] paths) {
            double[] payoff = new double[n_simulations];
            for (int i = 0; i < n_simulations; i++) {
                payoff[i] = Math.max(paths[i][359] - k, 0);
            }
            return payoff;
        }
    }

    static class OptionPricer {
        FinancialModel model;

        OptionPricer(FinancialModel model) {
            this.model = model;
        }

        double price_option() {
            double[][] paths = model.simulate_paths();
            double[] payoff = model.calculate_payoff(paths);
            double option_price = Math.exp(-model.r * model.t) * average(payoff);
            return option_price;
        }

        double average(double[] array) {
            double sum = 0.0;
            for (double num : array) {
                sum += num;
            }
            return sum / array.length;
        }
    }

    public static void main(String[] args) {
        double s0 = 100;
        double k = 100;
        double t = 1;
        double r = 0.05;
        double sigma = 0.2;
        int n_simulations = 10000;
        FinancialModel model = new FinancialModel(s0, k, t, r, sigma, n_simulations);
        OptionPricer pricer = new OptionPricer(model);
        double price = pricer.price_option();
        System.out.println(price);
    }
}