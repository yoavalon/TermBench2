import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0051 {
    public static void main(String[] args) {
        double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
        int N = 252, M = 1000;
        List<Double> results = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            results.add(simulate_price("call", S0, K, T, r, sigma, N, M));
        }
        double average_price = 0;
        for (double result : results) {
            average_price += result;
        }
        average_price /= M;
        System.out.println(average_price);
    }

    public static double simulate_price(String option_type, double S0, double K, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double dS = S0 * (r * dt + sigma * Math.sqrt(dt));
        List<Double> prices = new ArrayList<>();
        prices.add(S0);
        for (int i = 1; i <= N; i++) {
            double S = prices.get(prices.size() - 1) + dS * new Random().nextGaussian();
            prices.add(S);
        }
        double payoff = option_type.equals("call") ? Math.max(0, prices.get(prices.size() - 1) - K) : Math.max(0, K - prices.get(prices.size() - 1));
        return payoff;
    }
}