import java.util.Random;

public class sample_1653 {
    public static double simulate_stock_price(double S0, double mu, double sigma, double T, double dt) {
        double S = S0;
        for (int i = 0; i < (int)(T / dt); i++) {
            double dS = mu * S * dt + sigma * S * new Random().nextGaussian() * Math.sqrt(dt);
            S += dS;
        }
        return S;
    }

    public static double monte_carlo_option_price(double S0, double K, double T, double r, double sigma, int N, double dt) {
        double option_price = 0;
        for (int i = 0; i < N; i++) {
            double S_T = simulate_stock_price(S0, r, sigma, T, dt);
            option_price += Math.max(S_T - K, 0);
        }
        return option_price * (1 / N) * Math.exp(-r * T);
    }

    public static void main(String[] args) {
        double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2, dt = 0.01;
        int N = 100000;
        double price = monte_carlo_option_price(S0, K, T, r, sigma, N, dt);
        System.out.println("Option Price: " + price);
    }
}