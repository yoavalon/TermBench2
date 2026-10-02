import java.util.Random;

public class sample_1447 {
    public static double[][] generate_paths(double s0, double mu, double sigma, double dt, double T, int N) {
        double[][] paths = new double[N][((int) (T / dt)) + 1];
        for (int i = 0; i < N; i++) {
            paths[i][0] = s0;
        }
        for (int t = 1; t <= ((int) (T / dt)); t++) {
            double[] z = new double[N];
            Random random = new Random();
            for (int i = 0; i < N; i++) {
                z[i] = random.nextGaussian();
            }
            for (int i = 0; i < N; i++) {
                paths[i][t] = paths[i][t - 1] * Math.exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[i]);
            }
        }
        return paths;
    }

    public static double[] calculate_payoff(double[][] paths, double strike, String option_type) {
        double[] payoff = new double[paths.length];
        if (option_type.equals("call")) {
            for (int i = 0; i < paths.length; i++) {
                payoff[i] = Math.max(paths[i][paths[i].length - 1] - strike, 0);
            }
        } else if (option_type.equals("put")) {
            for (int i = 0; i < paths.length; i++) {
                payoff[i] = Math.max(strike - paths[i][paths[i].length - 1], 0);
            }
        }
        return payoff;
    }

    public static double monte_carlo_pricing(double s0, double strike, double r, double T, double sigma, int N, double dt, String option_type) {
        double[][] paths = generate_paths(s0, r, sigma, dt, T, N);
        double[] payoff = calculate_payoff(paths, strike, option_type);
        double discount_factor = Math.exp(-r * T);
        double option_price = 0;
        for (double p : payoff) {
            option_price += p;
        }
        option_price *= discount_factor / N;
        return option_price;
    }

    public static void main(String[] args) {
        double s0 = 100.0;
        double strike = 100.0;
        double r = 0.05;
        double T = 1.0;
        double sigma = 0.2;
        int N = 10000;
        double dt = 0.01;
        String option_type = "call";
        double price = monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type);
        System.out.println(price);
    }
}