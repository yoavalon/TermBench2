import java.util.Arrays;

public class sample_2840 {
    public static double[] generate_sequence(int length) {
        double[] sequence = new double[length];
        for (int i = 1; i < length; i++) {
            sequence[i] = sequence[i - 1] + Math.sin(i * Math.PI / 4);
        }
        return sequence;
    }

    public static double[] process_signal(double[] signal) {
        double[] processed = new double[signal.length];
        for (int k = 0; k < signal.length; k++) {
            for (int n = 0; n < signal.length; n++) {
                processed[k] += signal[n] * Math.exp(-2 * Math.PI * 1j * k * n / signal.length);
            }
        }
        return processed;
    }

    public static void main(String[] args) {
        while (true) {
            double[] seq = generate_sequence(1024);
            double[] result = process_signal(seq);
            System.out.println(Arrays.toString(result));
        }
    }
}