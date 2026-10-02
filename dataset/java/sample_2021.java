import java.util.Arrays;

public class sample_2021 {

    static class SignalProcessor {
        double[] data;

        SignalProcessor(double[] data) {
            this.data = data;
        }

        double[] filter_signal(double low, double high) {
            double[] fft_data = fft(data);
            double[] frequencies = fftfreq(data.length, 1.0 / 44100);
            boolean[] mask = new boolean[frequencies.length];
            for (int i = 0; i < frequencies.length; i++) {
                mask[i] = (frequencies[i] > low) && (frequencies[i] < high);
            }
            double[] filtered_fft_data = new double[fft_data.length];
            for (int i = 0; i < fft_data.length; i++) {
                filtered_fft_data[i] = fft_data[i] * (mask[i] ? 1 : 0);
            }
            return ifft(filtered_fft_data);
        }

        double[] fft(double[] data) {
            // Placeholder for FFT implementation
            return Arrays.copyOf(data, data.length);
        }

        double[] ifft(double[] data) {
            // Placeholder for IFFT implementation
            return Arrays.copyOf(data, data.length);
        }

        double[] fftfreq(int n, double d) {
            // Placeholder for FFT frequency calculation
            double[] frequencies = new double[n];
            for (int i = 0; i < n; i++) {
                frequencies[i] = (i < n / 2) ? i * d : (i - n) * d;
            }
            return frequencies;
        }
    }

    static class DataAnalyzer {
        double[] processed_data;

        DataAnalyzer(double[] processed_data) {
            this.processed_data = processed_data;
        }

        double[] calculate_statistics() {
            double mean = Arrays.stream(processed_data).average().orElse(0.0);
            double sum = 0.0;
            for (double value : processed_data) {
                sum += Math.pow(value - mean, 2);
            }
            double std_dev = Math.sqrt(sum / processed_data.length);
            return new double[]{mean, std_dev};
        }
    }

    static class ResultFormatter {
        double mean;
        double std_dev;

        ResultFormatter(double mean, double std_dev) {
            this.mean = mean;
            this.std_dev = std_dev;
        }

        String format_output() {
            return String.format("Mean: %.6f, Std Dev: %.6f", mean, std_dev);
        }
    }

    public static void main(String[] args) {
        double[] raw_data = new double[44100];
        for (int i = 0; i < raw_data.length; i++) {
            raw_data[i] = Math.random();
        }
        SignalProcessor processor = new SignalProcessor(raw_data);
        double[] filtered_data = processor.filter_signal(1000, 5000);
        DataAnalyzer analyzer = new DataAnalyzer(filtered_data);
        double[] stats = analyzer.calculate_statistics();
        ResultFormatter formatter = new ResultFormatter(stats[0], stats[1]);
        System.out.println(formatter.format_output());
    }
}