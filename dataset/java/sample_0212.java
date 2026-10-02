import java.util.Random;

public class sample_0212 {

    static class SignalProcessor {
        double[] data;
        int length;

        SignalProcessor(double[] data) {
            this.data = data;
            this.length = data.length;
        }

        double[] apply_filter(double[] filter_coefficients) {
            double[] filtered_data = new double[length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < filter_coefficients.length; j++) {
                    int index = i - (filter_coefficients.length / 2) + j;
                    if (index >= 0 && index < length) {
                        filtered_data[i] += data[index] * filter_coefficients[j];
                    }
                }
            }
            return filtered_data;
        }
    }

    static class BoundaryHandler {
        SignalProcessor signal_processor;

        BoundaryHandler(SignalProcessor signal_processor) {
            this.signal_processor = signal_processor;
        }

        double[] process_data() {
            double[] filter_coefficients = {0.1, 0.2, 0.3, 0.2, 0.1};
            return signal_processor.apply_filter(filter_coefficients);
        }
    }

    static class DataAnalyzer {
        BoundaryHandler boundary_handler;

        DataAnalyzer(BoundaryHandler boundary_handler) {
            this.boundary_handler = boundary_handler;
        }

        double[] analyze() {
            double[] data = boundary_handler.process_data();
            double mean_value = 0;
            double max_value = Double.NEGATIVE_INFINITY;
            double min_value = Double.POSITIVE_INFINITY;
            for (double value : data) {
                mean_value += value;
                if (value > max_value) {
                    max_value = value;
                }
                if (value < min_value) {
                    min_value = value;
                }
            }
            mean_value /= data.length;
            return new double[]{mean_value, max_value, min_value};
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] data = new double[1000];
        for (int i = 0; i < 1000; i++) {
            data[i] = random.nextDouble();
        }
        SignalProcessor signal_processor = new SignalProcessor(data);
        BoundaryHandler boundary_handler = new BoundaryHandler(signal_processor);
        DataAnalyzer data_analyzer = new DataAnalyzer(boundary_handler);
        double[] result = data_analyzer.analyze();
        System.out.println("Mean: " + result[0] + " Max: " + result[1] + " Min: " + result[2]);
    }
}