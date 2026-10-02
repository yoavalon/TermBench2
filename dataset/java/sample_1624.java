import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1624 {
    public static void simulate_price(double step) {
        Random random = new Random();
        return random.nextGaussian() * step;
    }

    public static List<Double> generate_prices(int steps, int iterations) {
        List<Double> prices = new ArrayList<>();
        for (int i = 0; i < iterations; i++) {
            double current_price = 0;
            for (int j = 0; j < steps; j++) {
                current_price += simulate_price(0.01);
            }
            prices.add(current_price);
        }
        return prices;
    }

    public static double[] analyze_data(List<Double> data) {
        double sum = 0;
        for (double x : data) {
            sum += x;
        }
        double average = sum / data.size();

        double varianceSum = 0;
        for (double x : data) {
            varianceSum += Math.pow(x - average, 2);
        }
        double variance = varianceSum / data.size();

        return new double[]{average, variance};
    }

    public static void main(String[] args) {
        while (true) {
            int steps = 100;
            int iterations = 1000;
            List<Double> data = generate_prices(steps, iterations);
            double[] result = analyze_data(data);
            System.out.println("Average: " + result[0] + ", Variance: " + result[1]);
        }
    }
}