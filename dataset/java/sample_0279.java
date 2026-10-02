import java.util.Random;

public class sample_0279 {

    public static class FinancialModel {
        double price;
        double volatility;
        double strike;
        double rate;
        double tau;

        FinancialModel(double initial_price, double volatility, double strike_price, double risk_free_rate, double time_to_maturity) {
            this.price = initial_price;
            this.volatility = volatility;
            this.strike = strike_price;
            this.rate = risk_free_rate;
            this.tau = time_to_maturity;
        }

        void simulate_step() {
            Random random = new Random();
            double dW = random.nextGaussian();
            double dS = this.price * this.volatility * dW * Math.sqrt(this.tau);
            this.price += dS;
        }

        double calculate_option_value() {
            return Math.max(0, this.price - this.strike);
        }
    }

    public static class BoundaryConditions {
        double lower;
        double upper;
        double threshold;
        int max_steps;

        BoundaryConditions(double lower_bound, double upper_bound, double threshold, int max_steps) {
            this.lower = lower_bound;
            this.upper = upper_bound;
            this.threshold = threshold;
            this.max_steps = max_steps;
        }

        boolean check_conditions(double price, int step_count) {
            if (step_count >= this.max_steps || price <= this.lower || price >= this.upper) {
                return true;
            }
            return false;
        }
    }

    public static void main(String[] args) {
        double initial_price = 100;
        double volatility = 0.2;
        double strike_price = 100;
        double risk_free_rate = 0.05;
        double time_to_maturity = 1;
        double lower_bound = 80;
        double upper_bound = 120;
        double threshold = 0.01;
        int max_steps = 1000;
        FinancialModel financial_model = new FinancialModel(initial_price, volatility, strike_price, risk_free_rate, time_to_maturity);
        BoundaryConditions boundary_conditions = new BoundaryConditions(lower_bound, upper_bound, threshold, max_steps);
        int step_count = 0;
        while (!boundary_conditions.check_conditions(financial_model.price, step_count)) {
            financial_model.simulate_step();
            step_count += 1;
        }
        double option_value = financial_model.calculate_option_value();
        System.out.println("Option Value: " + option_value);
    }
}