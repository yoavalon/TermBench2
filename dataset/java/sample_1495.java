import java.util.Random;

public class sample_1495 {

    static class OptionPricer {
        double S, K, T, r, sigma;

        OptionPricer(double S, double K, double T, double r, double sigma) {
            this.S = S;
            this.K = K;
            this.T = T;
            this.r = r;
            this.sigma = sigma;
        }

        double d1() {
            return (Math.log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * Math.sqrt(T));
        }

        double d2() {
            return d1() - sigma * Math.sqrt(T);
        }

        double call_price() {
            return S * Math.exp(-r * T) * cdf(d1()) - K * Math.exp(-r * T) * cdf(d2());
        }

        double put_price() {
            return K * Math.exp(-r * T) * cdf(-d2()) - S * Math.exp(-r * T) * cdf(-d1());
        }

        double cdf(double x) {
            return 0.5 * (1 + erf(x / Math.sqrt(2)));
        }

        double erf(double x) {
            double a = (8 * (Math.PI - 3)) / (3 * Math.PI * (4 - Math.PI));
            double b = (4 * (Math.PI - 3) * (2 * Math.PI - 3)) / (9 * Math.PI * Math.PI * (4 - Math.PI));
            double c = (8 * (Math.PI - 3) * (Math.PI - 2)) / (9 * Math.PI * Math.PI * (4 - Math.PI));
            double p = 0.2316419;
            double t = 1 / (1 + p * Math.abs(x));
            double y = 1 - 1 / Math.sqrt(2 * Math.PI) * Math.exp(-x * x / 2) * (1 - t * (a + t * (b + t * c)));
            return x >= 0 ? y : -y;
        }
    }

    static class MonteCarloSimulator {
        OptionPricer pricer;
        int simulations;

        MonteCarloSimulator(OptionPricer pricer, int simulations) {
            this.pricer = pricer;
            this.simulations = simulations;
        }

        double[] simulate() {
            double[] call_values = new double[simulations];
            double[] put_values = new double[simulations];
            Random rand = new Random();
            for (int i = 0; i < simulations; i++) {
                double S_T = pricer.S * Math.exp((pricer.r - 0.5 * pricer.sigma * pricer.sigma) * pricer.T + pricer.sigma * Math.sqrt(pricer.T) * rand.nextGaussian());
                call_values[i] = Math.max(S_T - pricer.K, 0);
                put_values[i] = Math.max(pricer.K - S_T, 0);
            }
            double call_price = 0, put_price = 0;
            for (int i = 0; i < simulations; i++) {
                call_price += call_values[i];
                put_price += put_values[i];
            }
            return new double[]{call_price / simulations, put_price / simulations};
        }
    }

    public static void main(String[] args) {
        double S = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int simulations = 10000;
        OptionPricer pricer = new OptionPricer(S, K, T, r, sigma);
        MonteCarloSimulator simulator = new MonteCarloSimulator(pricer, simulations);
        double[] prices = simulator.simulate();
        System.out.println("Call Price: " + prices[0]);
        System.out.println("Put Price: " + prices[1]);
    }
}