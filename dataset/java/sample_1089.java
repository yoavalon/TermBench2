import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1089 {

    public static double price_option(int step, List<Double> path, double strike, double risk_free, double volatility, double time_to_maturity) {
        if (step == 0) {
            return Math.max(path.get(path.size() - 1) - strike, 0);
        }
        double up = path.get(path.size() - 1) * (1 + volatility);
        double down = path.get(path.size() - 1) * (1 - volatility);
        return (risk_free * price_option(step - 1, addToList(path, up), strike, risk_free, volatility, time_to_maturity) + 
                (1 - risk_free) * price_option(step - 1, addToList(path, down), strike, risk_free, volatility, time_to_maturity)) / 2;
    }

    private static List<Double> addToList(List<Double> path, double value) {
        List<Double> newPath = new ArrayList<>(path);
        newPath.add(value);
        return newPath;
    }

    public static double monte_carlo(double strike, double risk_free, double volatility, double time_to_maturity) {
        int steps = (int) (time_to_maturity * 252);
        List<Double> paths = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            paths.add(price_option(steps, List.of(100.0), strike, risk_free, volatility, time_to_maturity));
        }
        return paths.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
    }

    public static void main(String[] args) {
        double strike = 100;
        double risk_free = 0.05;
        double volatility = 0.2;
        double time_to_maturity = 1;
        while (true) {
            monte_carlo(strike, risk_free, volatility, time_to_maturity);
        }
    }
}