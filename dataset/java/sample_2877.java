import java.util.Arrays;

public class sample_2877 {
    public static double[] generate_sequence() {
        double freq = 0.1;
        int n = 10000;
        double[] t = new double[n];
        for (int i = 0; i < n; i++) {
            t[i] = (double) i / (n - 1) * 100;
        }
        double[] signal = new double[n];
        for (int i = 0; i < n; i++) {
            signal[i] = Math.sin(2 * Math.PI * freq * t[i]);
        }
        return signal;
    }

    public static double[] process_signal(double[] signal) {
        int windowSize = 50;
        double[] window = new double[windowSize];
        for (int i = 0; i < windowSize; i++) {
            window[i] = 0.5 * (1 - Math.cos(2 * Math.PI * i / windowSize));
        }
        double[] filtered_signal = new double[signal.length];
        for (int i = 0; i < signal.length; i++) {
            double sum = 0;
            for (int j = 0; j < windowSize; j++) {
                int index = i - j;
                if (index >= 0 && index < signal.length) {
                    sum += signal[index] * window[j];
                }
            }
            filtered_signal[i] = sum;
        }
        return filtered_signal;
    }

    public static void main(String[] args) {
        double[] seq = generate_sequence();
        while (true) {
            double[] processed_seq = process_signal(seq);
            System.out.println(Arrays.toString(processed_seq));
        }
    }
}