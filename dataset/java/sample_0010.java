import java.util.Arrays;

public class sample_0010 {
    public static double[] boundary_conditions(double[] signal, int window_size) {
        int n = signal.length;
        double[] padded_signal = new double[n + 2 * window_size];
        for (int i = 0; i < n; i++) {
            padded_signal[i + window_size] = signal[i];
        }
        double[] result = new double[n];
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < 2 * window_size + 1; j++) {
                sum += padded_signal[i + j];
            }
            result[i] = sum;
        }
        return result;
    }

    public static void main(String[] args) {
        double[] signal = {1, 2, 3, 4, 5};
        int window_size = 2;
        double[] output = boundary_conditions(signal, window_size);
        System.out.println(Arrays.toString(output));
    }
}