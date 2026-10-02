import java.util.Random;

public class sample_0059 {
    public static double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
        Random random = new Random();
        double sum = 0;
        for (int i = 0; i < M; i++) {
            double Z = random.nextGaussian();
            double ST = S0 * Math.exp((r - 0.5 * sigma * sigma) * T + sigma * Math.sqrt(T) * Z);
            sum += Math.max(ST - K, 0);
        }
        double call_price = Math.exp(-r * T) * sum / M;
        return call_price;
    }

    public static void main(String[] args) {
        double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 1000, 100000);
        System.out.println(result);
    }
}