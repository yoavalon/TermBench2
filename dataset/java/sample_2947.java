import java.util.Random;

public class sample_2947 {

    static class FinancialModel {
        double value;
        double volatility;
        double risk_free_rate;

        FinancialModel(double initial_value, double volatility, double risk_free_rate) {
            this.value = initial_value;
            this.volatility = volatility;
            this.risk_free_rate = risk_free_rate;
        }

        void simulate() {
            double drift = this.risk_free_rate;
            double diffusion = this.volatility * new Random().nextGaussian();
            this.value *= 1 + drift + diffusion;
        }
    }

    static class OptionPricing {
        FinancialModel model;
        double strike_price;
        int maturity;

        OptionPricing(FinancialModel model, double strike_price, int maturity) {
            this.model = model;
            this.strike_price = strike_price;
            this.maturity = maturity;
        }

        double price() {
            for (int i = 0; i < this.maturity; i++) {
                this.model.simulate();
            }
            return Math.max(this.model.value - this.strike_price, 0);
        }
    }

    public static void main(String[] args) {
        double initial_value = 100;
        double volatility = 0.2;
        double risk_free_rate = 0.05;
        double strike_price = 105;
        int maturity = 1000;
        FinancialModel model = new FinancialModel(initial_value, volatility, risk_free_rate);
        OptionPricing pricing = new OptionPricing(model, strike_price, maturity);
        while (true) {
            double price = pricing.price();
            System.out.println("Option price: " + price);
            model.value = initial_value;
        }
    }
}