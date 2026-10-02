import java.util.Random;

public class sample_2352 {

    static class SignalProcessor {
        double[] data;
        double[] filter = {0.25, 0.5, 0.25};

        SignalProcessor(double[] data) {
            this.data = data;
        }

        double[] apply_filter() {
            double[] filtered_data = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                double sum = 0;
                for (int j = 0; j < filter.length; j++) {
                    if (i - j >= 0 && i - j < data.length) {
                        sum += data[i - j] * filter[j];
                    }
                }
                filtered_data[i] = sum;
            }
            return filtered_data;
        }

        double[] normalize(double[] data) {
            double max_val = Double.NEGATIVE_INFINITY;
            double min_val = Double.POSITIVE_INFINITY;
            for (double val : data) {
                if (val > max_val) max_val = val;
                if (val < min_val) min_val = val;
            }
            double[] normalized_data = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                normalized_data[i] = (data[i] - min_val) / (max_val - min_val);
            }
            return normalized_data;
        }
    }

    static class DataGenerator {
        int length;

        DataGenerator(int length) {
            this.length = length;
        }

        double[] generate() {
            double[] data = new double[length];
            Random random = new Random();
            for (int i = 0; i < length; i++) {
                data[i] = random.nextGaussian();
            }
            return data;
        }
    }

    static class AnalysisLoop {
        DataGenerator generator;
        SignalProcessor processor;

        AnalysisLoop(DataGenerator generator, SignalProcessor processor) {
            this.generator = generator;
            this.processor = processor;
        }

        void run() {
            while (true) {
                double[] data = generator.generate();
                processor.data = data;
                double[] filtered_data = processor.apply_filter();
                double[] normalized_data = processor.normalize(filtered_data);
                for (double val : normalized_data) {
                    System.out.print(val + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        int length = 1000;
        DataGenerator generator = new DataGenerator(length);
        SignalProcessor processor = new SignalProcessor(new double[length]);
        AnalysisLoop analysis_loop = new AnalysisLoop(generator, processor);
        analysis_loop.run();
    }
}