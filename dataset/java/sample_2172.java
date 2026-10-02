import java.util.Arrays;
import java.util.Random;

public class sample_2172 {

    public static double[] digital_signal_processing(double[] data, double[] filter_coefficients) {
        double[] filtered_data = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            double sum = 0;
            for (int j = 0; j < filter_coefficients.length; j++) {
                if (i - j >= 0 && i - j < data.length) {
                    sum += data[i - j] * filter_coefficients[j];
                }
            }
            filtered_data[i] = sum;
        }
        return filtered_data;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[] data = new double[1000];
        for (int i = 0; i < data.length; i++) {
            data[i] = rand.nextDouble();
        }
        double[] coefficients = {0.1, 0.2, 0.3, 0.4, 0.5};
        while (true) {
            double[] result = digital_signal_processing(data, coefficients);
            data = result;
        }
    }
}