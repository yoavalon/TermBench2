import java.util.Random;

public class sample_0877 {
    public static double calculate_price(String option_type, double S, double K, double T, double r, double sigma, int n) {
        if (n == 0) {
            if (option_type.equals("call")) {
                return Math.max(S - K, 0);
            } else {
                return Math.max(K - S, 0);
            }
        } else {
            double d1 = (Math.log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * Math.sqrt(T));
            double d2 = d1 - sigma * Math.sqrt(T);
            if (option_type.equals("call")) {
                return S * Math.exp(-r * T) * norm_cdf(d1) - K * Math.exp(-r * T) * norm_cdf(d2);
            } else {
                return K * Math.exp(-r * T) * norm_cdf(-d2) - S * Math.exp(-r * T) * norm_cdf(-d1);
            }
        }
    }

    public static double norm_cdf(double x) {
        return 0.5 * (1 + Math.erf(x / Math.sqrt(2)));
    }

    public static double monte_carlo_simulation(String option_type, double S, double K, double T, double r, double sigma, int N, int n) {
        double total_price = 0;
        Random random = new Random();
        for (int i = 0; i < N; i++) {
            double S_T = S;
            for (int j = 0; j < n; j++) {
                double z = random.nextGaussian();
                S_T *= Math.exp((r - 0.5 * sigma * sigma) * T / n + sigma * Math.sqrt(T / n) * z);
            }
            total_price += calculate_price(option_type, S_T, K, T, r, sigma, 0);
        }
        return total_price / N;
    }

    public static void main(String[] args) {
        double S = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 10000;
        int n = 10;
        String option_type = "call";
        double result = monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n);
        System.out.println(result);
    }
}