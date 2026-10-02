import java.util.Arrays;

public class sample_2653 {

    static class SignalProcessor {
        double[] data;

        SignalProcessor(double[] data) {
            this.data = data;
        }

        double[] apply_filter(double[] kernel) {
            double[] result = new double[data.length];
            int klen = kernel.length;
            for (int i = 0; i < data.length; i++) {
                for (int j = 0; j < klen; j++) {
                    int index = i - j + klen / 2;
                    if (index >= 0 && index < data.length) {
                        result[i] += data[index] * kernel[j];
                    }
                }
            }
            return result;
        }

        double[] normalize(double[] data) {
            double min_val = Arrays.stream(data).min().orElse(0);
            double max_val = Arrays.stream(data).max().orElse(1);
            double[] normalized = new double[data.length];
            for (int i = 0; i < data.length; i++) {
                normalized[i] = (data[i] - min_val) / (max_val - min_val);
            }
            return normalized;
        }
    }

    static class SequenceGenerator {
        int length;
        double amplitude;

        SequenceGenerator(int length, double amplitude) {
            this.length = length;
            this.amplitude = amplitude;
        }

        double[] generate_sine_wave() {
            double[] result = new double[length];
            for (int i = 0; i < length; i++) {
                double x = 2 * Math.PI * i / length;
                result[i] = amplitude * Math.sin(x);
            }
            return result;
        }

        double[] generate_square_wave() {
            double[] result = new double[length];
            for (int i = 0; i < length; i++) {
                double x = 2 * Math.PI * i / length;
                result[i] = amplitude * Math.signum(Math.sin(x));
            }
            return result;
        }
    }

    public static void main(String[] args) {
        SequenceGenerator seq_gen = new SequenceGenerator(100, 1);
        double[] sine_wave = seq_gen.generate_sine_wave();
        double[] square_wave = seq_gen.generate_square_wave();
        SignalProcessor processor = new SignalProcessor(sine_wave);
        double[] filtered_sine = processor.apply_filter(new double[]{0.25, 0.5, 0.25});
        double[] normalized_sine = processor.normalize(filtered_sine);
        processor.data = square_wave;
        double[] filtered_square = processor.apply_filter(new double[]{-0.25, 0.5, -0.25});
        double[] normalized_square = processor.normalize(filtered_square);
        System.out.println('Normalized Sine Wave: ' + Arrays.toString(normalized_sine));
        System.out.println('Normalized Square Wave: ' + Arrays.toString(normalized_square));
    }
}