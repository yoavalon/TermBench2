import java.util.Random;

class FinancialModel {
    double S0, K, T, r, sigma;
    int N, M;

    FinancialModel(double S0, double K, double T, double r, double sigma, int N, int M) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
        this.M = M;
    }

    double[][] simulate_paths() {
        double dt = T / N;
        double[][] S = new double[M][N + 1];
        for (int i = 0; i < M; i++) {
            S[i][0] = S0;
        }
        for (int t = 1; t <= N; t++) {
            Random random = new Random();
            double[] Z = new double[M];
            for (int i = 0; i < M; i++) {
                Z[i] = random.nextGaussian();
            }
            for (int i = 0; i < M; i++) {
                S[i][t] = S[i][t - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z[i]);
            }
        }
        return S;
    }

    double calculate_option_price() {
        double[][] S = simulate_paths();
        double sum = 0.0;
        for (int i = 0; i < M; i++) {
            sum += Math.max(S[i][N] - K, 0);
        }
        double option_price = Math.exp(-r * T) * (sum / M);
        return option_price;
    }
}

public class sample_2023 {
    public static void main(String[] args) {
        double S0 = 100.0;
        double K = 100.0;
        double T = 1.0;
        double r = 0.05;
        double sigma = 0.2;
        int N = 252;
        int M = 10000;
        FinancialModel model = new FinancialModel(S0, K, T, r, sigma, N, M);
        double price = model.calculate_option_price();
        System.out.printf("Option price: %.4f\n", price);
    }
}