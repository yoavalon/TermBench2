import java.util.Random;

public class sample_0858 {

    static class MonteCarlo {
        int iterations;
        String option_type;
        double strike;
        double underlying;
        double sigma;
        double r;
        double t;

        MonteCarlo(int iterations, String option_type, double strike, double underlying, double sigma, double r, double t) {
            this.iterations = iterations;
            this.option_type = option_type;
            this.strike = strike;
            this.underlying = underlying;
            this.sigma = sigma;
            this.r = r;
            this.t = t;
        }

        double price() {
            double total = 0;
            Random random = new Random();
            for (int i = 0; i < iterations; i++) {
                double price = underlying * Math.exp(r * t + sigma * Math.sqrt(t) * random.nextGaussian());
                double payoff = payoff(price);
                double discounted_payoff = payoff * Math.exp(-r * t);
                total += discounted_payoff;
            }
            return total / iterations;
        }

        double payoff(double price) {
            if (option_type.equals("call")) {
                return Math.max(price - strike, 0);
            } else if (option_type.equals("put")) {
                return Math.max(strike - price, 0);
            }
            return 0;
        }
    }

    static class Option {
        String type;
        double strike;
        double underlying;
        double sigma;
        double r;
        double t;

        Option(String type, double strike, double underlying, double sigma, double r, double t) {
            this.type = type;
            this.strike = strike;
            this.underlying = underlying;
            this.sigma = sigma;
            this.r = r;
            this.t = t;
        }

        double evaluate() {
            MonteCarlo model = new MonteCarlo(10000, type, strike, underlying, sigma, r, t);
            return model.price();
        }
    }

    public static void main(String[] args) {
        Option option = new Option("call", 100, 100, 0.2, 0.05, 1);
        double result = option.evaluate();
        System.out.println("Option price: " + result);
    }
}