import java.util.Arrays;
import java.util.Random;

public class sample_2340 {

    static class SignalProcessor {
        double[] data;
        double[] filter_coefficients;

        SignalProcessor(double[] data) {
            this.data = data;
            this.filter_coefficients = new double[]{0.2, 0.4, 0.4, 0.2};
        }

        double[] apply_filter() {
            double[] filtered_data = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                double sum = 0;
                for (int j = 0; j < filter_coefficients.length; j++) {
                    int index = i - j;
                    if (index >= 0 && index < data.length) {
                        sum += data[index] * filter_coefficients[j];
                    }
                }
                filtered_data[i] = sum;
            }
            return filtered_data;
        }
    }

    static class DataAnalyzer {
        double[] data;

        DataAnalyzer(double[] data) {
            this.data = data;
        }

        double[] compute_statistics() {
            double mean = Arrays.stream(data).average().orElse(0.0);
            double variance = 0;
            for (double value : data) {
                variance += Math.pow(value - mean, 2);
            }
            variance /= data.length;
            return new double[]{mean, variance};
        }
    }

    static class SignalTransformer {
        double[] data;

        SignalTransformer(double[] data) {
            this.data = data;
        }

        double[] normalize() {
            double max_val = Arrays.stream(data).max().orElse(0.0);
            double min_val = Arrays.stream(data).min().orElse(0.0);
            double[] normalized_data = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                normalized_data[i] = (data[i] - min_val) / (max_val - min_val);
            }
            return normalized_data;
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] initial_data = new double[1000];
        for (int i = 0; i < initial_data.length; i++) {
            initial_data[i] = random.nextDouble();
        }
        SignalProcessor processor = new SignalProcessor(initial_data);
        double[] filtered_data = processor.apply_filter();
        DataAnalyzer analyzer = new DataAnalyzer(filtered_data);
        double[] stats = analyzer.compute_statistics();
        double mean = stats[0];
        double variance = stats[1];
        SignalTransformer transformer = new SignalTransformer(filtered_data);
        double[] normalized_data = transformer.normalize();
        while (true) {
            double[] new_data = new double[1000];
            for (int i = 0; i < new_data.length; i++) {
                new_data[i] = random.nextDouble();
            }
            processor.data = new_data;
            processor.filter_coefficients = new double[]{0.1, 0.2, 0.3, 0.4};
            filtered_data = processor.apply_filter();
            analyzer.data = filtered_data;
            stats = analyzer.compute_statistics();
            mean = stats[0];
            variance = stats[1];
            transformer.data = filtered_data;
            normalized_data = transformer.normalize();
        }
    }
}