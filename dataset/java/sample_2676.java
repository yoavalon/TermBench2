import java.util.Arrays;

public class sample_2676 {

    static class SignalProcessor {
        double[] data;

        SignalProcessor(double[] data) {
            this.data = data;
        }

        double[] apply_filter(double[] kernel) {
            double[] result = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                double sum = 0;
                for (int j = 0; j < kernel.length; j++) {
                    int index = i - j;
                    if (index >= 0 && index < data.length) {
                        sum += data[index] * kernel[j];
                    }
                }
                result[i] = sum;
            }
            return result;
        }

        double[] normalize(double[] data) {
            double min_val = Arrays.stream(data).min().orElse(0);
            double max_val = Arrays.stream(data).max().orElse(0);
            double[] normalized = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                normalized[i] = (data[i] - min_val) / (max_val - min_val);
            }
            return normalized;
        }
    }

    static class SequenceGenerator {
        int length;

        SequenceGenerator(int length) {
            this.length = length;
        }

        double[] generate_sine_wave(double frequency, double amplitude, double phase) {
            double[] wave = new double[length];
            for (int i = 0; i < length; i++) {
                wave[i] = amplitude * Math.sin(2 * Math.PI * frequency * (i / (double) length) + phase);
            }
            return wave;
        }
    }

    static class Analysis {
        double[] data;

        Analysis(double[] processed_data) {
            this.data = processed_data;
        }

        double[] calculate_fft() {
            double[] fft_result = new double[data.length];
            for (int k = 0; k < data.length; k++) {
                for (int n = 0; n < data.length; n++) {
                    fft_result[k] += data[n] * Math.exp(-2 * Math.PI * 1j * k * n / data.length);
                }
            }
            return fft_result;
        }

        double find_peak_frequency(double[] fft_result) {
            double[] freqs = new double[fft_result.length];
            for (int i = 0; i < fft_result.length; i++) {
                freqs[i] = i / (double) fft_result.length;
            }
            int peak_idx = 0;
            for (int i = 1; i < fft_result.length; i++) {
                if (Math.abs(fft_result[i]) > Math.abs(fft_result[peak_idx])) {
                    peak_idx = i;
                }
            }
            return freqs[peak_idx];
        }
    }

    public static void main(String[] args) {
        int length = 1024;
        SequenceGenerator generator = new SequenceGenerator(length);
        double[] signal = generator.generate_sine_wave(5, 1, 0);
        SignalProcessor processor = new SignalProcessor(signal);
        double[] kernel = {0.25, 0.5, 0.25};
        double[] filtered_data = processor.apply_filter(kernel);
        double[] normalized_data = processor.normalize(filtered_data);
        Analysis analysis = new Analysis(normalized_data);
        double[] fft_result = analysis.calculate_fft();
        double peak_frequency = analysis.find_peak_frequency(fft_result);
        System.out.println("Peak Frequency: " + peak_frequency);
    }
}