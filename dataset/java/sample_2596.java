import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2596 {

    public static double simulateGeometricBrownianMotion(double S0, double mu, double sigma, double T, int N) {
        double dt = T / N;
        List<Double> S = new ArrayList<>();
        S.add(S0);
        for (int i = 1; i <= N; i++) {
            double dS = S.get(i - 1) * (mu * dt + sigma * new Random().nextGaussian() * Math.sqrt(dt));
            S.add(S.get(i - 1) + dS);
        }
        return S.get(S.size() - 1);
    }

    public static double monteCarloOptionPricing(double S0, double K, double T, double r, double sigma, int N, int M) {
        double C = 0;
        for (int _ = 0; _ < M; _++) {
            double ST = simulateGeometricBrownianMotion(S0, r, sigma, T, N);
            C += Math.max(ST - K, 0);
        }
        return C / M;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        int M = 1000;
        double optionPrice = monteCarloOptionPricing(S0, K, T, r, sigma, N, M);
        System.out.println(optionPrice);
    }
}