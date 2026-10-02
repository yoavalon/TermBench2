import java.util.ArrayList;
import java.util.List;

public class sample_2056 {

    static class FloatingPointAnalyzer {
        int precision;
        List<Double> data_points;

        FloatingPointAnalyzer(int precision) {
            this.precision = precision;
            this.data_points = new ArrayList<>();
        }

        void add_data(double value) {
            this.data_points.add(Math.round(value * Math.pow(10, precision)) / Math.pow(10, precision));
        }

        double calculate_average() {
            double total = 0;
            for (double value : data_points) {
                total += value;
            }
            int count = data_points.size();
            return count > 0 ? Math.round(total / count * Math.pow(10, precision)) / Math.pow(10, precision) : 0;
        }

        double[] analyze() {
            double average = calculate_average();
            double variance = calculate_variance(average);
            return new double[]{average, variance};
        }

        double calculate_variance(double average) {
            double sum_squared_diffs = 0;
            for (double value : data_points) {
                sum_squared_diffs += Math.pow(value - average, 2);
            }
            int count = data_points.size();
            return count > 0 ? Math.round(sum_squared_diffs / count * Math.pow(10, precision)) / Math.pow(10, precision) : 0;
        }
    }

    static class Ledger {
        int precision;
        FloatingPointAnalyzer analyzer;

        Ledger(int precision) {
            this.precision = precision;
            this.analyzer = new FloatingPointAnalyzer(precision);
        }

        void record_transaction(double value) {
            this.analyzer.add_data(value);
        }

        double[] get_analysis() {
            return this.analyzer.analyze();
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger(4);
        ledger.record_transaction(100.1234);
        ledger.record_transaction(200.5678);
        ledger.record_transaction(300.9012);
        ledger.record_transaction(400.3456);
        ledger.record_transaction(500.789);
        double[] analysis = ledger.get_analysis();
        System.out.println("Average: " + analysis[0] + ", Variance: " + analysis[1]);
    }
}