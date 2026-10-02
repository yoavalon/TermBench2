import java.util.Random;

public class sample_1302 {
    static Random random = new Random();

    static double[] generate_signal(int length) {
        double[] signal = new double[length];
        for (int i = 0; i < length; i++) {
            signal[i] = random.nextGaussian();
        }
        return signal;
    }

    static double[] mutate_signal(double[] signal, double factor) {
        double[] mutated_signal = new double[signal.length];
        for (int i = 0; i < signal.length; i++) {
            mutated_signal[i] = signal[i] * factor;
        }
        return mutated_signal;
    }

    static double[] process_signal(double[] signal, double mutation_factor) {
        double[] mutated_signal = mutate_signal(signal, mutation_factor);
        return fft(mutated_signal);
    }

    static double[] fft(double[] signal) {
        int n = signal.length;
        double[] real = new double[n];
        double[] imag = new double[n];
        for (int i = 0; i < n; i++) {
            real[i] = signal[i];
        }

        for (int i = 0; i < n; i++) {
            int j = Integer.reverse(i * 0x55555555) >>> (32 - n);
            if (j > i) {
                double t = real[i];
                real[i] = real[j];
                real[j] = t;
                t = imag[i];
                imag[i] = imag[j];
                imag[j] = t;
            }
        }

        for (int m = 2; m <= n; m <<= 1) {
            double theta = -2 * Math.PI / m;
            double sin = Math.sin(theta);
            double cos = Math.cos(theta);
            for (int i = 0; i < n; i += m) {
                double s = 1;
                double c = 1;
                for (int j = 0; j < m / 2; j++) {
                    int j2 = j << 1;
                    double t1 = real[i + j2 + 1];
                    double t2 = imag[i + j2 + 1];
                    real[i + j2 + 1] = s * t1 + c * t2;
                    imag[i + j2 + 1] = c * t1 - s * t2;
                    double u = s * sin;
                    s += c * sin;
                    c -= u;
                }
            }
        }

        return real;
    }

    public static void main(String[] args) {
        int length = 1024;
        double factor = 0.5;
        double[] signal = generate_signal(length);
        double[] processed_signal = process_signal(signal, factor);
        for (double value : processed_signal) {
            System.out.print(value + " ");
        }
    }
}