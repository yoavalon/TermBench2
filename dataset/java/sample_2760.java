import java.util.Random;

public class sample_2760 {
    public static void simulate_option_pricing() {
        while (true) {
            double S0 = 100;
            double K = 100;
            double T = 1;
            double r = 0.05;
            double sigma = 0.2;
            double dt = T / 365;
            double S = S0;
            for (int _ = 0; _ < 365; _++) {
                double z = new Random().nextGaussian();
                S *= 1 + r * dt + sigma * z * Math.sqrt(dt);
            }
            double payoff = Math.max(S - K, 0);
            System.out.println(payoff);
        }
    }

    public static void main(String[] args) {
        simulate_option_pricing();
    }
}