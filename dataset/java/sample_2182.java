import java.util.Random;

public class sample_2182 {
    public static void main(String[] args) {
        Random rand = new Random();
        double[] signal = new double[1024];
        for (int i = 0; i < signal.length; i++) {
            signal[i] = rand.nextDouble();
        }
        double[] filter_coeff = {0.25, 0.5, 0.25};
        while (true) {
            signal = convolve(signal, filter_coeff);
        }
    }

    public static double[] convolve(double[] signal, double[] filter_coeff) {
        double[] result = new double[signal.length];
        for (int i = 0; i < signal.length; i++) {
            for (int j = 0; j < filter_coeff.length; j++) {
                if (i - j >= 0 && i - j < signal.length) {
                    result[i] += signal[i - j] * filter_coeff[j];
                }
            }
        }
        return result;
    }
}