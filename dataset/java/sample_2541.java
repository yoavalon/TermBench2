import java.util.Random;

public class sample_2541 {

    public static double[] generate_sequence(int length) {
        double[] x = new double[length];
        x[0] = 1;
        Random rand = new Random();
        for (int n = 1; n < length; n++) {
            x[n] = 0.5 * x[n - 1] + rand.nextGaussian() * 0.1;
        }
        return x;
    }

    public static double[] process_signal(double[] x) {
        int N = x.length;
        double[] y = new double[N];
        double[] real = new double[N];
        double[] imag = new double[N];

        // Forward FFT
        for (int k = 0; k < N; k++) {
            for (int n = 0; n < N; n++) {
                double angle = 2 * Math.PI * k * n / N;
                real[k] += x[n] * Math.cos(angle);
                imag[k] -= x[n] * Math.sin(angle);
            }
        }

        // Zero small values
        for (int k = 0; k < N; k++) {
            if (Math.sqrt(real[k] * real[k] + imag[k] * imag[k]) < 0.001) {
                real[k] = 0;
                imag[k] = 0;
            }
        }

        // Inverse FFT
        for (int n = 0; n < N; n++) {
            y[n] = 0;
            for (int k = 0; k < N; k++) {
                double angle = 2 * Math.PI * k * n / N;
                y[n] += real[k] * Math.cos(angle) + imag[k] * Math.sin(angle);
            }
            y[n] /= N;
        }

        return y;
    }

    public static void main(String[] args) {
        int seq_length = 1000;
        double[] seq = generate_sequence(seq_length);
        double[] filtered_seq = process_signal(seq);
        for (double val : filtered_seq) {
            System.out.print(val + " ");
        }
    }
}