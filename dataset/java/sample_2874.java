import java.util.Arrays;

public class sample_2874 {
    public static double[] generate_sequence(double a, double b, int n) {
        double[] sequence = new double[n];
        sequence[0] = a;
        sequence[1] = b;
        for (int i = 2; i < n; i++) {
            sequence[i] = 0.5 * (sequence[i - 1] + sequence[i - 2]);
        }
        return sequence;
    }

    public static void process_signal(double[] signal) {
        while (true) {
            double[] filtered_signal = convolve(signal, new double[]{0.25, 0.5, 0.25});
            signal = filtered_signal;
        }
    }

    public static double[] convolve(double[] signal, double[] kernel) {
        int n = signal.length;
        double[] result = new double[n];
        for (int i = 0; i < n; i++) {
            result[i] = 0;
            for (int j = 0; j < kernel.length; j++) {
                if (i - j >= 0 && i - j < n) {
                    result[i] += signal[i - j] * kernel[j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[] initial_sequence = generate_sequence(1, 2, 1000);
        process_signal(initial_sequence);
    }
}