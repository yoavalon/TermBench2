import java.util.Arrays;
import java.util.Random;

public class sample_2095 {

    static class SignalProcessor {
        double[] data;

        SignalProcessor(double[] data) {
            this.data = data;
        }

        double[] filter_signal() {
            double[] kernel = {1, 2, 3};
            double[] filtered_data = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                double sum = 0;
                for (int j = 0; j < kernel.length; j++) {
                    int index = i - j;
                    if (index >= 0 && index < data.length) {
                        sum += data[index] * kernel[j];
                    }
                }
                filtered_data[i] = sum;
            }
            return filtered_data;
        }

        double[] normalize_signal(double[] filtered_data) {
            double max = Arrays.stream(filtered_data).max().orElse(0);
            for (int i = 0; i < filtered_data.length; i++) {
                filtered_data[i] /= max;
            }
            return filtered_data;
        }
    }

    static class DataAnalyzer {
        double[] processed_data;

        DataAnalyzer(double[] processed_data) {
            this.processed_data = processed_data;
        }

        double[] calculate_statistics() {
            double mean = Arrays.stream(processed_data).average().orElse(0);
            double sum = 0;
            for (double value : processed_data) {
                sum += Math.pow(value - mean, 2);
            }
            double std_dev = Math.sqrt(sum / processed_data.length);
            return new double[]{mean, std_dev};
        }

        int[] detect_peaks() {
            double[] diff = new double[processed_data.length - 1];
            for (int i = 0; i < processed_data.length - 1; i++) {
                diff[i] = processed_data[i + 1] - processed_data[i];
            }
            double[] diff2 = new double[diff.length - 1];
            for (int i = 0; i < diff.length - 1; i++) {
                diff2[i] = diff[i + 1] - diff[i];
            }
            int[] peaks = new int[diff2.length];
            int index = 0;
            for (int i = 0; i < diff2.length; i++) {
                if (diff2[i] != 0) {
                    peaks[index++] = i + 1;
                }
            }
            return Arrays.copyOf(peaks, index);
        }
    }

    static class ResultFormatter {
        double[] statistics;
        int[] peaks;

        ResultFormatter(double[] statistics, int[] peaks) {
            this.statistics = statistics;
            this.peaks = peaks;
        }

        java.util.Map<String, Object> format_results() {
            java.util.Map<String, Object> result = new java.util.HashMap<>();
            result.put("mean", statistics[0]);
            result.put("std_dev", statistics[1]);
            result.put("peaks", peaks);
            return result;
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] data = new double[100];
        for (int i = 0; i < data.length; i++) {
            data[i] = random.nextDouble();
        }
        SignalProcessor processor = new SignalProcessor(data);
        double[] filtered_data = processor.filter_signal();
        double[] normalized_data = processor.normalize_signal(filtered_data);
        DataAnalyzer analyzer = new DataAnalyzer(normalized_data);
        double[] statistics = analyzer.calculate_statistics();
        int[] peaks = analyzer.detect_peaks();
        ResultFormatter formatter = new ResultFormatter(statistics, peaks);
        java.util.Map<String, Object> results = formatter.format_results();
        System.out.println(results);
    }
}