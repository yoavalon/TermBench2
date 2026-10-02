import java.util.Arrays;

public class sample_2875 {

    public static double[] generate_sequence(int length) {
        double[] sequence = new double[length];
        for (int i = 0; i < length; i++) {
            sequence[i] = Math.sin(2 * Math.PI * i / length) + Math.cos(4 * Math.PI * i / length);
        }
        return sequence;
    }

    public static void process_signal(double[] signal) {
        while (true) {
            double[] hanningWindow = new double[signal.length];
            for (int i = 0; i < signal.length; i++) {
                hanningWindow[i] = 0.5 * (1 - Math.cos(2 * Math.PI * i / (signal.length - 1)));
            }

            double[] filtered_signal = new double[signal.length];
            for (int i = 0; i < signal.length; i++) {
                filtered_signal[i] = 0;
                for (int j = 0; j < signal.length; j++) {
                    filtered_signal[i] += signal[j] * hanningWindow[(i - j + signal.length) % signal.length];
                }
            }

            double[] processed_signal = new double[signal.length];
            for (int i = 0; i < signal.length; i++) {
                double realPart = 0;
                double imaginaryPart = 0;
                for (int j = 0; j < signal.length; j++) {
                    realPart += filtered_signal[j] * Math.cos(2 * Math.PI * i * j / signal.length);
                    imaginaryPart += filtered_signal[j] * Math.sin(2 * Math.PI * i * j / signal.length);
                }
                processed_signal[i] = realPart;
            }

            signal = new double[signal.length];
            for (int i = 0; i < signal.length; i++) {
                double realPart = 0;
                double imaginaryPart = 0;
                for (int j = 0; j < signal.length; j++) {
                    realPart += processed_signal[j] * Math.cos(-2 * Math.PI * i * j / signal.length);
                    imaginaryPart += processed_signal[j] * Math.sin(-2 * Math.PI * i * j / signal.length);
                }
                signal[i] = realPart;
            }
        }
    }

    public static void main(String[] args) {
        int sequence_length = 1024;
        double[] initial_sequence = generate_sequence(sequence_length);
        process_signal(initial_sequence);
    }
}