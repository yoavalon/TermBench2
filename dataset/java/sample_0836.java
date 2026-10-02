import java.lang.Math;

class FinancialModel {
    double price;
    double strike;
    double volatility;
    double rate;
    double time;

    FinancialModel(double price, double strike, double volatility, double rate, double time) {
        this.price = price;
        this.strike = strike;
        this.volatility = volatility;
        this.rate = rate;
        this.time = time;
    }

    double d1() {
        return (Math.log(price / strike) + (rate + 0.5 * volatility * volatility) * time) / (volatility * Math.sqrt(time));
    }

    double d2() {
        return d1() - volatility * Math.sqrt(time);
    }

    double call_price() {
        return price * Math.exp(-rate * time) * cdf(d1()) - strike * Math.exp(-rate * time) * cdf(d2());
    }

    double put_price() {
        return strike * Math.exp(-rate * time) * cdf(-d2()) - price * Math.exp(-rate * time) * cdf(-d1());
    }

    double cdf(double x) {
        return 0.5 * (1 + Math.erf(x / Math.sqrt(2)));
    }
}

public class sample_0836 {
    static double simulate_pricing(FinancialModel model, int simulations, int depth) {
        if (depth == 0) {
            return 0;
        }
        double call_value = model.call_price();
        double put_value = model.put_price();
        return call_value + put_value + simulate_pricing(model, simulations, depth - 1);
    }

    public static void main(String[] args) {
        FinancialModel model = new FinancialModel(100, 100, 0.2, 0.05, 1);
        int simulations = 1000;
        int depth = 5;
        double total_value = simulate_pricing(model, simulations, depth);
        System.out.println("Total Estimated Value: " + total_value);
    }
}