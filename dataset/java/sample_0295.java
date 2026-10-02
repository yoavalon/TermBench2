import java.util.Random;

public class sample_0295 {

    static class FinancialModel {
        double[] S0;
        double K;
        double T;
        double r;
        double sigma;
        int N;
        double dt;

        FinancialModel(double[] S0, double K, double T, double r, double sigma, int N) {
            this.S0 = S0;
            this.K = K;
            this.T = T;
            this.r = r;
            this.sigma = sigma;
            this.N = N;
            this.dt = T / N;
        }

        double[][] simulate_paths() {
            double[][] paths = new double[N + 1][S0.length];
            paths[0] = S0;
            Random rand = new Random();
            for (int t = 1; t <= N; t++) {
                double[] z = new double[S0.length];
                for (int i = 0; i < S0.length; i++) {
                    z[i] = rand.nextGaussian();
                }
                for (int i = 0; i < S0.length; i++) {
                    paths[t][i] = paths[t - 1][i] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[i]);
                }
            }
            return paths;
        }

        double[] payoff(double[][] paths) {
            double[] payoff = new double[paths[0].length];
            for (int i = 0; i < paths[0].length; i++) {
                payoff[i] = Math.max(paths[paths.length - 1][i] - K, 0);
            }
            return payoff;
        }
    }

    static class OptionPricer {
        FinancialModel financial_model;
        int M;

        OptionPricer(FinancialModel financial_model, int M) {
            this.financial_model = financial_model;
            this.M = M;
        }

        double price_option() {
            double[] payoffs = new double[M];
            for (int i = 0; i < M; i++) {
                double[][] paths = financial_model.simulate_paths();
                double[] payoff = financial_model.payoff(paths);
                payoffs[i] = payoff[0]; // Assuming single asset for simplicity
            }
            double option_price = Math.exp(-financial_model.r * financial_model.T) * average(payoffs);
            return option_price;
        }

        double average(double[] array) {
            double sum = 0;
            for (double value : array) {
                sum += value;
            }
            return sum / array.length;
        }
    }

    public static void main(String[] args) {
        double[] S0 = {100, 100, 100};
        double K = 100;
        double T = 1.0;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        int M = 10000;
        FinancialModel financial_model = new FinancialModel(S0, K, T, r, sigma, N);
        OptionPricer option_pricer = new OptionPricer(financial_model, M);
        System.out.println(option_pricer.price_option());
    }
}