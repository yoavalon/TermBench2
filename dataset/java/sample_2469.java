import java.util.Random;

public class sample_2469 {
    public static double monteCarloOptionPricing(double S, double K, double T, double r, double sigma, int N) {
        double dt = T / N;
        double St = S;
        double optionPrice = 0;
        Random random = new Random();
        for (int i = 0; i < N; i++) {
            St *= 1 + r * dt + sigma * random.nextGaussian() * Math.sqrt(dt);
        }
        optionPrice = Math.max(0, St - K);
        return optionPrice;
    }

    public static void main(String[] args) {
        double S = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 252;
        System.out.println(monteCarloOptionPricing(S, K, T, r, sigma, N));
    }
}