import java.util.Random;

public class sample_0250 {

    static class FinancialModel {
        double S0;
        double K;
        double T;
        double r;
        double sigma;
        int N;
        int M;
        Random random = new Random();

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
            double[][] paths = new double[N + 1][M];
            paths[0] = new double[M];
            for (int i = 0; i < M; i++) {
                paths[0][i] = S0;
            }
            for (int i = 1; i <= N; i++) {
                for (int j = 0; j < M; j++) {
                    double z = random.nextGaussian();
                    paths[i][j] = paths[i - 1][j] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
                }
            }
            return paths;
        }

        double option_price() {
            double[][] paths = simulate_paths();
            double payoffSum = 0;
            for (int j = 0; j < M; j++) {
                payoffSum += Math.max(paths[N][j] - K, 0);
            }
            double price = Math.exp(-r * T) * (payoffSum / M);
            return price;
        }
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        int M = 10000;
        FinancialModel model = new FinancialModel(S0, K, T, r, sigma, N, M);
        double price = model.option_price();
        System.out.println(price);
    }
}